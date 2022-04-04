#include <iostream>
#include <string>

#include "../constants.h"
#include "../ise102.h"


class Fairy : public Creature {
    private:
        /* Print an introduction to the Fairy.
         *
         * Returns: void
        */
        void introduction() {
            std::cout << "Chapter 4: The Fairy\n\n\n";

            delay(1500);

            std::cout
                << "As you leave the forge, SILVER KEY in hand, you see an enormous, ANCIENT STONE DOOR. A sculpted face in the surface speaks.\n\n";

            delay(2000);

            std::cout
                << "ANCIENT STONE DOOR:\n"
                << " Hello traveller, I see you are trying to return to the forest.\n";

            delay(3000);

            std::cout
                << " I am afraid I cannot let you pass.\n"
                << " The key you possess does not contain a RUBY!\n";

            delay(3000);

            std::cout
                << "\n Speak with THE FAIRY, he will help you acquire a RUBY.\n\n";

            delay(2000);


            std::cout << "\nYou follow the ANCIENT STONE DOOR's instructions, and head off in search of the fairy.\n\n";

            delay(4000);

            std::cout << "After a few minutes of searching...\n";

            delay(2500);

            std::cout << "You spot the FAIRY!\n\n";

            delay(3000);

            std::cout
                << "FAIRY:\n"
                << " Hello there! Would you like to play a game?\n"
                << " If you win, I'll give you one RED GEM!\n\n";
        }

        /* Return a message about the player dying to the Fairy.
         *
         * Returns: std::string
         *   The death message.
        */
        std::string deathMessage() {
            return "In the blink of an eye, the FAIRY casts a spell and turns you into a frog! \n\nRibbit...";
        }

        /* Play the Fairy's number guessing game.
        *
        * Generates a random number between 1 and 10, then
        * asks the player to guess it.
        *
        * Returns: bool
        *   true if the player guesses correctly, false otherwise.
        */
        bool guessNumber() {
            int number = randomInRange(1, 10);
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
        * Generates a random number between 0 and 2, then
        * returns the gem at that index in the RedGem enum.
        *
        * Returns: RedGem
        *   The RedGem that was taken.
        */
        RedGem take_gem() {
            // One in 3 chance as one in 6 is too slow.
            int gem_number = randomInRange(0, 2);
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
        * If the player fails the game, or doesn't receive
        * a RUBY, play again.
        *
        * Returns: Progress
        *   The player's progress in the game.
        */
        Progress playGame(Progress game_progress) {
            bool success = Fairy::guessNumber();

            if (!success) {
                std::cout
                    << "FAIRY:\n"
                    << " Unlucky...\n Let's play again!\n\n";
                    delay(1000);
                    game_progress = Fairy::playGame(game_progress);
            }

            else {
                std::cout
                    << "FAIRY:\n"
                    << " Congratulations!\n"
                    << " Take a gem from this bag!\n\n";

                delay(3000);

                RedGem gem = Fairy::take_gem();

                if (gem == RedGem::RUBY) {
                    std::cout << "\nYou have acquired a RUBY!\n\n";

                    delay(3000);

                    game_progress = Progress::HAVE_RUBY;
                }

                else {
                    std::cout
                        << "FAIRY:\n"
                        << " Looks like that isn't a RUBY. Let's play again.\n";

                    delay(1000);

                    game_progress = Fairy::playGame(game_progress);
                }
            }
            return game_progress;
        }

    public:
        /* Begin interaction with the Fairy.
        *
        * If the player decides not to play the Fairy's game,
        * they will perish. Else, play the game until a ruby
        * is drawn.
        *
        * Params:
        *   met_fairy: bool - Whether the player has met the Fairy before.
        *
        * Returns: Progress
        *   The player's progress in the game.
        */
        Progress gameLoop(Progress game_progress) {
            bool met_fairy = false;

            while (game_progress < Progress::HAVE_RUBY) {
                if (!met_fairy) {
                    Fairy::introduction();
                    met_fairy = true;
                }

                std::string choice = getPlayerChoice("YES", "NO");

                if (choice == "YES") {
                    game_progress = Fairy::playGame(game_progress);
                }

                else {
                    std::cout << " That's a shame...\n\n";

                    delay(3000);

                    displayGameOver(Fairy::deathMessage());

                    game_progress = Progress::FAILED;
                }
            }
            return game_progress;
        }
};
