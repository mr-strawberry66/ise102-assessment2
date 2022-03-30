#include <iostream>
#include <string>
#include <random>
#include "../constants.h"
#include "../ise102.h"


/* Play the Fairy's number guessing game.
 *
 * Generates a random number between 1 and 10, then
 * asks the player to guess it.
 *
 * Returns: bool
 *   true if the player guesses correctly, false otherwise.
*/
bool guessNumber() {
    int number = rand() % 10 + 1;
    int guess;
    int guess_count = 0;
    int guess_limit = 5;

    delay(2000);

    std::cout << "\n Great! I'm thinking of a number between 1 and 10.\n";
    std::cout << " You have " << guess_limit << " guesses.\n";

    while (guess_count < guess_limit) {
        std::cout << " Your guess?\n > ";
        std::cin >> guess;

        if (guess < number) {
            std::cout << "\n Hmmm, too low.\n";
        } else if (guess > number) {
            std::cout << "\n Almost, you're too high.\n";
        } else {
            std::cout << "\n You got it!\n\n";

            delay(2000);

            return true;
        }

        guess_count ++;
    }

    std::cout << " You ran out of guesses.\n\n";

    delay(2000);

    return false;
}


/* Take a random gem from the Fairy's inventory.
 *
 * Generates a random number between 0 and 5, then
 * returns the gem at that index in the RedGem enum.
 *
 * Returns: RedGem
 *   The RedGem that was taken.
*/
RedGem take_gem() {
    int gem_number = rand() % 5;
    std::cout << "You reach into the bag and feel a number of red gems.\n\n";

    RedGem gem = RedGem(gem_number);

    std::cout << "You take one...\n\n";

    delay(3000);

    std::string a_an = (gem_number != 0) ? " a " : " an ";

    std::cout << "It's" << a_an << getRedGemNameByNumber(gem_number) << "!\n\n";

    delay(3000);
    return gem;
}


/* Run the Fairy's game loop using recursion.
 *
 * Asks the player if they want to play the game,
 * then runs the game loop if they do.
 *
 * If the player fails the game, or doesn't receive
 * a RUBY, ask if the player wants to play again.
 *
 * Returns: Progress
 *   The player's progress in the game.
*/
Progress playGame() {
    bool success = guessNumber();

    if (!success) {
        std::cout
            << "FAIRY:\n"
            << " Unlucky!\n Would you like to try again?\n\n";
            delay(1000);

            std::string choice = getPlayerChoice("YES", "NO");

            if (choice == "YES") {
                return playGame();
            }
            else {
                return Progress::HAVE_FORGED_KEY;
            }
    }

    else {
        std::cout
            << "FAIRY:\n"
            << " Congratulations!\n"
            << " Take a gem from this bag!\n\n";

        delay(3000);

        RedGem gem = take_gem();

        if (gem == RedGem::RUBY) {
            std::cout << "\nYou have acquired a RUBY!\n\n";

            delay(3000);

            return Progress::HAVE_RUBY;
        }

        else {
            std::cout
                << "FAIRY:\n"
                << " Would you like to play again?\n";

            delay(1000);

            std::string choice = getPlayerChoice("YES", "NO");

            if (choice == "YES") {
                return playGame();
            }
        }
    }
    return Progress::HAVE_FORGED_KEY;
}


/* Print the dialogue with the Fairy upon first encounter.
 *
 * Initiate the Fairy's game loop if the player
 * agrees to playing.
 *
 * End the game if the player declines.
 *
 * Returns: Progress
 *   The player's progress in the game.
*/
Progress notMetFairyDialogue() {
    std::cout << "You spot the FAIRY!\n\n";

    delay(3000);

    std::cout
        << "FAIRY:\n"
        << " Hello there! Would you like to play a game?\n"
        << " If you win, I'll give you one RED GEM!\n\n";


    std::string choice = getPlayerChoice("YES", "NO");

    if (choice == "YES") {
        return playGame();
    }

    cout << " That's a shame...\n\n";

    delay(3000);

    return Progress::FAILED;
}


/* Print the dialogue with the Fairy after the player has met the Fairy previously.
 *
 * Initiate the Fairy's game loop if the player
 * agrees to playing.
 *
 * Let the player return to the door if they decline.
 *
 * Returns: Progress
 *   The player's progress in the game.
*/
Progress metFairyDialogue() {
    std::cout
        << "FAIRY:\n"
        << " Ah! You're back! Would you like to play a game?\n"
        << " If you win, I'll give you one RED GEM!\n\n";


    std::string choice = getPlayerChoice("YES", "NO");

    if (choice == "YES") {
        return playGame();
    }

    return Progress::HAVE_FORGED_KEY;
}


/* Initiate a conversation with the Fairy.
 *
 * Params:
 *   met_fairy: bool - Whether the player has met the Fairy before.
 *
 * Returns: Progress
 *   The player's progress in the game.
*/
Progress speakWithFairy(bool met_fairy) {
    if (!met_fairy) {
        return notMetFairyDialogue();
    } else {
        return metFairyDialogue();
    }
}
