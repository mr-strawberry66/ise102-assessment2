#include <iostream>
#include <string>
#include <vector>

#include "../constants.h"
#include "../ise102.h"
#include "../fmt/format.h"


class Sphinx : public Creature {
    private:
        /* Print an introduction to the Sphinx.
        *
        * Returns: void
        */
        void introduction() {
            std::cout << "Chapter 2: The Riddle.\n\n\n";

            delay(1500);

            std::cout
                << "You enter the dark room. The smell of dust and dampness is overwhelming.\n"
                << "In the corner of your eye, you see a statue of a sphinx.\n";

            delay(1500);

            std::cout
                << "You turn to face it, and it comes to life.\n\n";

            delay(3000);

            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::gold),
                "SPHINX:\n Greetings, traveller.\n I understand you are in need of a SILVER KEY.\n I can direct you to THE BLACKSMITH. She will forge you a SILVER KEY.\n HOWEVER. In order to pass, you must answer my riddle.\n\n"
            );
        }

        /* Return a message about the player dying to the Sphinx.
        *
        * Returns: std::string
        *   The death message.
        */
        std::string deathMessage() {
            return "Before you have time to process the SPHINX's response, it leaps forwards and strikes you in the chest.";
        }

        /* Get the player to answer the Sphinx's riddle.
        *
        * Returns: bool
        *   True if the player successfully answers the riddle.
        */
        bool riddleSuccess() {
            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::gold),
                "SPHINX:\n What has many teeth, but cannot bite?\n\n > "
            );

            std::string answer;
            std::ws(std::cin);
            std::getline(std::cin, answer);

            // If the player answers correctly (COMB or A COMB)
            // they can progress. Otherwise show the game over
            // screen.
            if (toUpperCase(answer) == "COMB" || toUpperCase(answer) == "A COMB") {
                fmt::print(
                    fmt::emphasis::bold | fg(fmt::color::gold),
                    " You have answered correctly.\n You may pass.\n\n"
                );

                return true;
            }

            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::gold),
                " You have answered incorrectly.\n\n"
            );
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

            // Itterate over the set of directions and
            // ask which way the player wants to go.
            // If they make a mistake, they end up at
            // the sphinx again and have to try again.
            for (std::string direction : directions) {
                std::cout
                    << "Which direction will you go?\n\n"
                    << " > ";
                std::string answer;
                std::ws(std::cin);
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
        * Params:
        *   game_progress: Progress - The player's progress so far.
        *
        * Returns: Progress
        *   The player's updated progress in the game.
        */
        Progress findBlacksmith(Progress game_progress) {

            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::gold),
                "SPHINX:\n To find the BLACKSMITH, you need to leave this room through the door to your right.\n These tunnels are long and winding, it is easy to get lost. So listen carefully.\n\n"
            );

            while (game_progress < Progress::FOUND_BLACKSMITH) {
                fmt::print(
                fmt::emphasis::bold | fg(fmt::color::gold),
                    " First follow the tunnel UP.\n Take the first LEFT.\n Then the next LEFT you see after that.\n Follow that path UP for a while.\n Finally, take a RIGHT.\n\n"
                );

                delay(3000);

                if (Sphinx::completeBlacksmithTrip()) {
                    game_progress = Progress::FOUND_BLACKSMITH;
                }

                else {
                    fmt::print(
                        fmt::emphasis::bold | fg(fmt::color::gold),
                        "SPHINX:\n Ahh, you're back...\n Allow me to repeat the directions for you.\n\n"
                    );
                }
            }
            return game_progress;
        }

    public:
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
        Progress gameLoop(Progress game_progress) {
                if (game_progress < Progress::FOUND_BLACKSMITH) {
                    Sphinx::introduction();
                }

                while(game_progress < Progress::FOUND_BLACKSMITH) {
                    if (Sphinx::riddleSuccess()) {
                        game_progress = Sphinx::findBlacksmith(game_progress);
                    }

                    else {
                        displayGameOver(Sphinx::deathMessage());
                        game_progress = Progress::FAILED;
                    }
                }
                return game_progress;
        }
};
