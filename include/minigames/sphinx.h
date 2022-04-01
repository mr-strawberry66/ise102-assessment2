#include <iostream>
#include <string>
#include <vector>
#include "../constants.h"
#include "../ise102.h"


/* Print an introduction to the Sphinx.
 *
 * Returns: void
*/
void sphinxIntroduction() {
    std::cout << "Chapter 2: The Riddle.\n\n\n";

    delay(1500);

    std::cout
        << "You enter the dark room. The smell of dust and dampness is overwhelming.\n"
        << "In the corner of your eye, you see a statue of a sphinx.\n";

    delay(1500);

    std::cout
        << "You turn to face it, and it comes to life.\n\n";

    delay(3000);

    std::cout
        << "SPHINX:\n Greetings, traveller.\n"
        << " I understand you are in need of a SILVER KEY.\n"
        << " I can direct you to THE BLACKSMITH. She will forge you a SILVER KEY.\n\n"
        << " HOWEVER. In order to pass, you must answer my riddle.\n\n";
}


/* Return a message about the player dying to the Sphinx.
 *
 * Returns: std::string
 *   The death message.
*/
std::string deathBySphinx() {
    return "Before you have time to process the SPHINX's response, it leaps forwards and strikes you in the chest.";
}


/* Get the player to answer the Sphinx's riddle.
 *
 * Returns: bool
 *   True if the player successfully answers the riddle.
*/
bool sphinxRiddleSuccess() {
    std::cout
    << "SPHINX:\n"
    << " What has many teeth, but cannot bite?\n\n"
    << " > ";

    std::string answer;
    std::getline(std::cin, answer);

    if (
        toUpperCase(answer) == "COMB"
        || toUpperCase(answer) == "A COMB"
    ) {
        std::cout
            << " You have answered correctly.\n"
            << " You may pass.\n\n";

        return true;
    }

    std::cout << " You have answered incorrectly.\n\n";
    return false;
}


/* Get the player to input directions to the Blacksmith.
 *
 * Returns: bool
 *   If the player succeeded or not.
*/
bool completeBlacksmithTrip() {
    std::vector<std::string> directions = {
        "UP",
        "LEFT",
        "LEFT",
        "UP",
        "RIGHT",
    };

    for (std::string direction : directions) {
        std::cout
            << "Which direction will you go?\n\n"
            << " > ";
        std::string answer;
        std::getline(std::cin, answer);

        std::cout << "\n";

        if (toUpperCase(answer) != direction) {
            std::cout << "The tunnels begin to look familiar.\n\n";

            delay(3000);

            std::cout << "You've definitely been here before...\n\n";
            return false;
        }
    }
    std::cout << "The tunnel walls begin to grow wider, the air lifts, and you see a light.\n\n";

    delay(3000);

    std::cout << "You've found THE BLACKSMITH!\n\n";
    return true;
}


/* The player is given directions to the blacksmith.
 *
 * If the player succeeds in following the directions
 * to the blacksmith, continue the game. Otherwise repeat
 * the instructions and get the player to try again.
 *
 * Returns: Progress
 *   The player's progress in the game.
*/
Progress findBlacksmith(Progress game_progress) {

    std::cout
        << "SPHINX:\n"
        << " To find the BLACKSMITH, you need to leave this room through the door to your right.\n"
        << " These tunnels are long and winding, it is easy to get lost. So listen carefully.\n\n";


    while (game_progress < Progress::FOUND_BLACKSMITH) {

        std::cout
            << " First follow the tunnel UP.\n"
            << " Take the first LEFT.\n"
            << " Then the next LEFT you see after that.\n"
            << " Follow that path UP for a while.\n"
            << " Finally, take a RIGHT.\n\n";

        delay(3000);

        if (completeBlacksmithTrip()) {
            game_progress = Progress::FOUND_BLACKSMITH;
        }

        else {
            std::cout
                << "SPHINX:\n"
                << " Ahh, you're back...\n"
                << " Allow me to repeat the directions for you.\n\n";
        }
    }
    return game_progress;
}


/* Run the game loop for Chapter 2 of the game.
 *
 * This involves interractions with the Sphinx, and
 * the player finding their way to the Blacksmith.
 *
 * Params:
 *   game_progress: Progress - The current progress of the game.
 *
 * Returns: Progress
 *   The new progress of the game.
*/
Progress sphinxGameLoop(Progress game_progress) {
    if (game_progress < Progress::FOUND_BLACKSMITH) {
        sphinxIntroduction();
    }

    while(game_progress < Progress::FOUND_BLACKSMITH) {
        if (sphinxRiddleSuccess()) {
            game_progress = findBlacksmith(game_progress);
        }

        else {
            displayGameOver(deathBySphinx());
            game_progress = Progress::FAILED;
        }
    }
    return game_progress;
}
