/****************************************************************
 * Assessment 2: Adventure!
 ****************************************************************
*
* You've fallen into a strange underground lair and want out.
* A first encounter tells you what you must do: make a key
* that will open an ancient stone door.
*
* More info available in the README.md
* -------------------------------------------------------------
* What To Do
*
* - Fix the broken functions
* - Look for the todos in main for remaining encounters/features
*   that are needed
* - Look for other todos for functions that need to be created
*   or completed
* - Format the creature dialogue using fmt's prints' styles
* - Use colour/style elsewhere to communicate the player's situation,
*   their choices.
*
***************************************************************/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "include/ise102.h"
#include "include/constants.h"
#include "include/handy_functions.h"

// Show a pretty box surrounding the name of this game and maybe a blurb
// or subtitle.
void displayTitleAndIntro()
{
    const int TROLL_HEIGHT_INCHES = 30;
    // TODO: Replace the game name with something of your own choosing. Improve
    // the look of the Title here, don't leave it as the ### mess I created.

    cout << "######### DUNGEONS OF GIGGLEBERRY ##########\n";
    std::cout
            << "   ______                    ______                   "
            << "  / ____/___ __   _____     / ____/___ _____ ___  ___ "
            << " / /   / __ `/ | / / _ \\   / / __/ __ `/ __ `__ \\/ _ \\"
            << "/ /___/ /_/ /| |/ /  __/  / /_/ / /_/ / / / / / /  __/"
            << "\\____/\\__,_/ |___/\\___/   \\____/\\__,_/_/ /_/ /_/\\___/ ";
    cout << "\n\n";

    cout << "  Chapter 84 of the chronicles of Gorlanda \n";
    cout << "############################################\n\n\n";
    cout << "You wake up in a stone corridor, clearly underground and no longer in the forest you were so recently strolling through. A few feet away stands what appears to be - if cartoons are accurate - a thigh-high RED TROLL, maybe ";
    // TODO: This was made for U.S. audiences. Update it to metric (cms) by calling
    // one of the functions in handy_functions.h
    cout << TROLL_HEIGHT_INCHES << " inches tall.\n\n";
}

// The troll directs the player to the mines to retrieve ore.
// Introductory text is used if .
bool surviveTrollEncounter(bool already_met)
{
    cout << "MINE TROLL: \n ";
    // If first encounter, troll introduces self, gives quest
    if (already_met == false)
    {
        cout << "G'day human.You need to make a SILVER KEY to escape. Take this EXCELLENT PICKAXE and head to the mines. Come back when you have some ORE OF SILVER.\n\n";
    }

    else
    {
        cout << "What are you doing back out here? No silver, no key!\n\n";
    }
    // Give the player a choice..
    cout << "Do you SPIT on the disgusting troll, or take the pickaxe and go to the MINE?\n";
    string choice = getPlayerChoice("SPIT", "MINE");

    // end the function and return true if they mine
    if (choice == "MIME") return true;
    // if it hasn't ended, you spat.. uh oh
    cout << "\nThe troll, you discover, is awfully savage for her height.\n\n";
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
    if ( found == SILVER)
    {
        cout << "Hooray, you found SILVER ORE.\n\n";
        silver_progress = Progress::HAVE_SILVER_ORE;
    }

    else if (found == COAL)
    {
        cout << "You found COAL. Worried by the smoke and sparks from your strikes, you LEAVE THE MINE.\n\n";
        silver_progress = Progress::NO_PROGRESS;
    }

    else if (found == SHINEY_YELLOW)
    {
        cout << "You find a metal that, on closer inspection, is too YELLOWY GOLDEN to be Silver. Frustrated, you toss the nugget aside and stomp BACK INTO THE CORRIDOR.\n\n";
        silver_progress = Progress::NO_PROGRESS;
    }

    return silver_progress;
}

// Enter the mines looking for silver ore.
Progress mineForSilver()
{
    // TODO: Add a choice here, which area would they prefer to mine? You'll need
    // to describe the area and come up with choices.
    print("\n\n--- THE MINES ------------------------- \n\n");
    print("Entering the mine, you see two promising looking walls. Picking one, you start SWINGING..\n\n");
    delay(2000);   // Mining takes time..
    print("**CHANK!!** You knock loose a chunk of something that isn't regular rock..\n\n");
    delay(1500);
    Progress silver_progress = getSilverMiningOutcome();
    return silver_progress;
}

// TODO: Create a displayGameOver function that tells you what
// horrible fate ended your short, underground vacation.

int main() {
    srand(time(0));
    // TODO: Students - add game save option? Would have to be able to choose
    // to continue or start over on load.
    Progress game_progress = Progress::NO_PROGRESS;
    clearScreen();
    displayTitleAndIntro();

    // As long as the player hasn't found silver ore,
    // keep meeting troll, who sends you to mine for silver
    bool met_troll = false;
    while (game_progress != Progress::HAVE_SILVER_ORE)
    {
        if (surviveTrollEncounter(met_troll))
        {
            met_troll = true;
            // If you're successful, you'll pass the `while` condition!
            game_progress = mineForSilver();
        }

        else
        {
            //displayGameOver(a message about troll attack);
            cout << ("++ Game over ++\n\n");
            return 0;
        }
    }

    // TODO: encounter another creature, who tells you were to get
    // your silver forged into a key

    // while game_progress != have forged key, maybe?
    // TODO: Send the player to the forge, where they must tell the blacksmith a
    // funny name. the blacksmith is very particular though: she only wants a name made up   // of three words, and it has to be exactly 20 characters long, including spaces.
    // "Jasmine Bee Flettles" would work, but "Bonno Bingoparaloop" wouldn't, nor would
    // "Minh Gyu Lee" because it's too short.

    // TODO: leaving the forge, you see an enormous, ANCIENT STONE DOOR. A sculpted face in
    // the surface speaks and tells you he prefers keys with rubys in. He sends you to..

    // TODO: The Fairy's Gambit. Here you can engage in a challenge to get a red gem.
    // If it turns out to be a ruby (look at handy_functions) and not some other red gem,
    // you can set it in the key. If not, you must stay and try again. (The challenge is up to
    // you - it could be a game with a random draw like the silver mining, but something
    // different would be worth more marks!)
    //
    // TODO: You return to the door with the Ruby now set in the key. He graciously opens,
    // and lets you out into the forest you left so vertically earlier. Sourly, you realise
    // you didn't actually use the key to open the door.
    cout << "You walk up to the ancient stone door, who sighs and lets you\
    out. \"GREAT JOB\" he says, definitely not meaning it.\n";
    cout << "++ Game over ++ \n\n";
}
