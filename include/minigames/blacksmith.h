#include <iostream>
#include <string>

#include "../constants.h"
#include "../ise102.h"

#include "../fmt/format.h"

class Blacksmith : public Creature {
    private:
        /* Print an introduction to the Blacksmith.
        *
        * Returns: void
        */
        void introduction() {
            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::green_yellow),
                "Chapter 3: The Forge.\n\n\n"
            );

            delay(1500);

            std::cout
                << "As you approach the end of the tunnel, you see a large forge.\n"
                << "The smell of smoke and metal fills the air.\n"
                << "You approach the forge and see a BLACKSMITH working tirelessly over an anvil.\n";

            delay(1500);

            std::cout
                << "As you walk up to the BLACKSMITH, she turns to face you.\n\n";
        }

        /* Return a message to the player about the name they have provided.
        *
        * Params:
        *   name: std::string - The name the player has provided.
        *
        * Returns: std::string
        *   A message to the player about their name.
        */
        std::string validateNameMessage(std::string message) {
            std::string full_message = "THE BLACKSMITH:\n Hmmm...\n That IS a funny name, but, it is " + message + ".\n Try again.\n\n";

            return full_message;
        }

        /* Confirm the provided name meets the requirements of the blacksmith.
        *
        * Params:
        *   name: std::string - The name the player has provided.
        *   word_count: int - The number of words in the name.
        *
        * Returns: Progress
        *   The player's progress based on the name they have provided.
        */
        Progress validateName(std::string name, int word_count) {
            std::string validation_message = "";
            Progress game_progress;

            if (name.length() < 20) {
                validation_message = Blacksmith::validateNameMessage("not long enough");
                game_progress = Progress::HAVE_SILVER_ORE;
            }

            else if (name.length() > 20) {
                validation_message = Blacksmith::validateNameMessage("too long");
                game_progress = Progress::HAVE_SILVER_ORE;
            }

            if (word_count < 3) {
                validation_message = Blacksmith::validateNameMessage("too few words");
                game_progress = Progress::HAVE_SILVER_ORE;
            }

            else if (word_count > 3) {
                validation_message = Blacksmith::validateNameMessage("too many words");
                game_progress = Progress::HAVE_SILVER_ORE;
            }
            else {
                validation_message = "THE BLACKSMITH:\n HA HA HA! Well done!\n Here, I will forge you the key.\n\n";
                game_progress = Progress::HAVE_FORGED_KEY;
            }
            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::teal),
                validation_message
            );
            return game_progress;
        }

        /* Play the blacksmith's minigame.
        *
        * The blacksmith asks the player for a name, and the
        * player must provide one that meets certain parameters.
        *
        * Args:
        *   met_blacksmith: bool - Whether or not the player has met the blacksmith.
        *
        * Returns: Progress
        *   The player's progress based on the name they have provided.
        */
        Progress miniGame(bool met_blacksmith) {
            if (!met_blacksmith) {
                fmt::print(
                    fmt::emphasis::bold | fg(fmt::color::teal),
                    "THE BLACKSMITH:\n Hello traveller! I am THE BLACKSMITH.\n I can forge you a SILVER KEY, but in return, I require something from you.\n\n"
                );

                delay(1000);
            }

            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::teal),
                " Tell me a funny name for your SILVER KEY.\n This name must be three words long, and, it must be EXACTLY 20 characters long.\n\n"
            );

            std::string name = "";

            std::cout << "Choose a name.\n" << " > ";
            std::ws(std::cin);
            std::getline(std::cin, name);

            std::cout << "\n";

            int word_count = countWordsInString(name);

            Progress game_progress = Blacksmith::validateName(name, word_count);

            if (game_progress == Progress::HAVE_FORGED_KEY) {
                fmt::print(
                    fmt::emphasis::italic | fg(fmt::color::green),
                    "You have acquired the SILVER KEY!\n\n"
                );
            }

            return game_progress;
        }

    public:
        /* Run the game loop for Chapter 3 of the game.
        *
        * This involves interractions with the Blacksmith.
        *
        * Params:
        *   game_progress: Progress - The current progress of the game.
        *
        * Returns: Progress
        *   The new progress of the game.
        */
        Progress gameLoop(Progress game_progress) {
            if (game_progress < Progress::HAVE_FORGED_KEY) {
                Blacksmith::introduction();
            }

            bool met_blacksmith = false;
            while (game_progress < Progress::HAVE_FORGED_KEY) {
                game_progress = Blacksmith::miniGame(met_blacksmith);
                met_blacksmith = true;
            }

            return game_progress;
        }
};
