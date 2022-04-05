#include <iostream>
#include <string>

#include "../constants.h"
#include "../ise102.h"

#include "../fmt/format.h"


class AncientStoneDoor : public Creature {
    private:
        /* Print an introduction to the Ancient Stone Door.
         *
         * Returns: void
         */
        void introduction() {
            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::green_yellow),
                "Chapter 5: The Escape.\n\n\n"
            );

            delay(2000);

            std::cout
                << "With a RUBY in hand, you leave the FAIRY, and return to the ANCIENT STONE DOOR.\n\n";

            delay(3000);

            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::rosy_brown),
                "ANCIENT STONE DOOR:\n Welcome back traveller. Did you have any luck with the FAIRY?\n\n"
            );

            delay(2000);

            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::rosy_brown),
                " Excellent!\n Insert the RUBY into your SILVER KEY, and I will gladly let you pass.\n\n"
            );
        }

    public:
        /* Talk to the Ancient Stone Door about leaving.
         *
         * Returns: Progress
         *   The player's progress in the game.
        */
        Progress gameLoop(Progress game_progress) {
            while (game_progress < Progress::HAVE_GEMMED_KEY) {
                AncientStoneDoor::introduction();
                game_progress = Progress::HAVE_GEMMED_KEY;
            }

            return game_progress;
        }
};
