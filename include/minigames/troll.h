#include <iostream>
#include <string>

#include "../constants.h"
#include "../ise102.h"
#include "../fmt/format.h"


class Troll : public Creature {
    private:
        /* Print an introduction to the Troll.
        *
        * Returns: void
        */
        void introduction() {
            const int TROLL_HEIGHT_INCHES = 30;
            std::cout << "Chapter 1: Trapped!\n\n\n";
            std::cout
                << "You wake up in a stone corridor, clearly underground and no longer in the forest you were so recently strolling through. A few feet away stands what appears to be - if cartoons are accurate - a thigh-high RED TROLL, maybe "
                << inchesToCms(TROLL_HEIGHT_INCHES)
                << " centimeters tall.\n\n";
        }

        /* Return a message about the player dying to the Troll.
        *
        * Returns: std::string
        *   The death message.
        */
        std::string deathMessage() {
            return "The troll jumps towards you and shoves you to the ground. Picking up the pickaxe you were carrying, she swings wildly at you.";
        }

        /* Interract with the Troll.
         *
         * If the player SPITS on the troll,
         * the troll will kill the player.
         *
         * If the player chooses to mine, the
         * troll will let them mine.
         *
         * Params:
         *   already_met: bool - Whether the player has met the troll before.
         *
         * Returns: bool
         *   If the player survived or not.
        */
        bool surviveTrollEncounter(bool already_met) {
            fmt::print(
                fmt::emphasis::bold | fg(fmt::color::purple),
                "MINE TROLL: \n "
            );
            if (already_met == false) {
                fmt::print(
                    fmt::emphasis::bold | fg(fmt::color::purple),
                    "G'day human. You need to make a SILVER KEY to escape. Take this EXCELLENT PICKAXE and head to the mines. Come back when you have some ORE OF SILVER.\n\n"
                );
            }

            else {
                fmt::print(
                    fmt::emphasis::bold | fg(fmt::color::purple),
                    "What are you doing back out here? No silver, no key!\n\n"
                );
            }

            std::cout << "Do you SPIT on the disgusting troll, or take the pickaxe and go to the MINE?\n";

            std::string choice = getPlayerChoice("SPIT", "MINE");

            if (choice == "MINE") return true;

            fmt::print(
                fmt::emphasis::italic | fg(fmt::color::orange),
                "\nThe troll, you discover, is awfully savage for her height.\n\n"
            );
            return false;
        }

        /* Get the outcome of the player mining for silver.
         *
         * The player has a 1 in 3 chance of mining ore.
         *
         * Returns: Progress
         *   The player's game progress.
        */
        Progress getSilverMiningOutcome() {
            const int SHINEY_YELLOW = 1;
            const int COAL = 2;
            const int SILVER = 3;

            Progress silver_progress = Progress::NO_PROGRESS;
            int found = randomInRange(1,3);

            if (found == SILVER) {
                fmt::print(
                    fmt::emphasis::italic | fg(fmt::color::green),
                    "Hooray, you found SILVER ORE.\n\n"
                );
                std::cout << "Having found the SILVER ORE, the troll directs you to a small room.\n\n";
                silver_progress = Progress::HAVE_SILVER_ORE;
            }

            else if (found == COAL) {
                std::cout << "You found COAL. Worried by the smoke and sparks from your strikes, you LEAVE THE MINE.\n\n";
                silver_progress = Progress::NO_PROGRESS;
            }

            else if (found == SHINEY_YELLOW) {
                std::cout << "You find a metal that, on closer inspection, is too YELLOWY GOLDEN to be Silver. Frustrated, you toss the nugget aside and stomp BACK INTO THE CORRIDOR.\n\n";
                silver_progress = Progress::NO_PROGRESS;
            }

            return silver_progress;
        }

        /* Player has a chance to acquire silver ore.
         *
         * Player gets a choice of a left, or right
         * wall to mine from.
         *
         * Returns: Progress
         *   The player's game progress.
        */
        Progress mineForSilver() {
            std::cout << "\n\n--- THE MINES ------------------------- \n\n";
            std::cout << "Entering the mine, you see two promising looking walls.\n";
            std::cout << "Do you start mining to the LEFT, or to the RIGHT?\n";

            std::string choice = getPlayerChoice("LEFT", "RIGHT");

            if (choice == "LEFT") {
                std::cout << "The wall to your left is damp and derelict, but you see small glimmering veins of SILVER peeking through.\n\n";
            }

            else if (choice == "RIGHT") {
                std::cout << "The wall to your right stands strong, but is riddled with vines and roots growing through from the forest above.\n\n";
            }

            std::cout << "Having settled on the " << choice << " wall, you start SWINGING..\n\n";
            delay(2000);
            std::cout << "**CHANK!!** You knock loose a chunk of something that isn't regular rock..\n\n";
            delay(1500);
            Progress silver_progress = getSilverMiningOutcome();
            return silver_progress;
        }

    public:
        /* Run the game loop for Chapter 1 of the game.
        *
        * This involves interractions with the Troll, and
        * the player mining for silver ore.
        *
        * Params:
        *   game_progress: Progress - The current progress of the game.
        *
        * Returns: Progress
        *   The new progress of the game.
        */
        Progress gameLoop(Progress game_progress) {
            if (game_progress < Progress::HAVE_SILVER_ORE) {
                Troll::introduction();
            }

            bool met_troll = false;
            while (game_progress < Progress::HAVE_SILVER_ORE) {
                if (Troll::surviveTrollEncounter(met_troll)) {
                    met_troll = true;
                    game_progress = Troll::mineForSilver();
                }

                else {
                    displayGameOver(Troll::deathMessage());
                    game_progress = Progress::FAILED;
                }
            }
            return game_progress;
        }
};
