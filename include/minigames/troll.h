#include <iostream>
#include <string>
#include "../constants.h"
#include "../ise102.h"


/* Print an introduction to the Troll.
 *
 * Returns: void
*/
void trollIntroduction() {
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
std::string deathByTroll() {
    return "The troll jumps towards you and shoves you to the ground. Picking up the pickaxe you were carrying, she swings wildly at you.";
}


// The troll directs the player to the mines to retrieve ore.
// Introductory text is used if .
bool surviveTrollEncounter(bool already_met)
{
    std::cout << "MINE TROLL: \n ";
    // If first encounter, troll introduces self, gives quest
    if (already_met == false) {
        std::cout << "G'day human. You need to make a SILVER KEY to escape. Take this EXCELLENT PICKAXE and head to the mines. Come back when you have some ORE OF SILVER.\n\n";
    }

    else {
        std::cout << "What are you doing back out here? No silver, no key!\n\n";
    }
    // Give the player a choice..
    std::cout << "Do you SPIT on the disgusting troll, or take the pickaxe and go to the MINE?\n";
    std::string choice = getPlayerChoice("SPIT", "MINE");

    // end the function and return true if they mine
    if (choice == "MINE") return true;
    // if it hasn't ended, you spat.. uh oh
    std::cout << "\nThe troll, you discover, is awfully savage for her height.\n\n";
    return false;
}


// The player has a 1 in 3 chance of mining ore. The progress returned
// is either HAVE_ORE or NO_PROGRESS
Progress getSilverMiningOutcome()
{
    const int SHINEY_YELLOW = 1;
    const int COAL = 2;
    const int SILVER = 3;

    // Randomly mine one of the 3 materials above
    Progress silver_progress = Progress::NO_PROGRESS;
    int found = randomInRange(1,3);
    // Tell the player how they did, return their progress
    if (found == SILVER)
    {
        std::cout << "Hooray, you found SILVER ORE.\n\n";
        std::cout << "Having found the SILVER ORE, the troll directs you to a small room.\n\n";
        silver_progress = Progress::HAVE_SILVER_ORE;
    }

    else if (found == COAL)
    {
        std::cout << "You found COAL. Worried by the smoke and sparks from your strikes, you LEAVE THE MINE.\n\n";
        silver_progress = Progress::NO_PROGRESS;
    }

    else if (found == SHINEY_YELLOW)
    {
        std::cout << "You find a metal that, on closer inspection, is too YELLOWY GOLDEN to be Silver. Frustrated, you toss the nugget aside and stomp BACK INTO THE CORRIDOR.\n\n";
        silver_progress = Progress::NO_PROGRESS;
    }

    return silver_progress;
}


// Enter the mines looking for silver ore.
Progress mineForSilver()
{
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
    delay(2000);   // Mining takes time..
    std::cout << "**CHANK!!** You knock loose a chunk of something that isn't regular rock..\n\n";
    delay(1500);
    Progress silver_progress = getSilverMiningOutcome();
    return silver_progress;
}


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
Progress trollGameLoop(Progress game_progress) {
    if (game_progress < Progress::HAVE_SILVER_ORE) {
        trollIntroduction();
    }

    bool met_troll = false;
    while (game_progress < Progress::HAVE_SILVER_ORE) {
        if (surviveTrollEncounter(met_troll)) {
            met_troll = true;
            game_progress = mineForSilver();
        }

        else {
            displayGameOver(deathByTroll());
            game_progress = Progress::FAILED;
        }
    }
    return game_progress;
}
