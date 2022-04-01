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
#include <string>

#include "include/constants.h"
#include "include/game_screens.h"
#include "include/handy_functions.h"
#include "include/ise102.h"

#include "include/minigames/ancient_door.h"
#include "include/minigames/blacksmith.h"
#include "include/minigames/fairy.h"
#include "include/minigames/sphinx.h"
#include "include/minigames/troll.h"


int main() {
    srand(time(0));

    Progress game_progress = getPlayerProgress();

    clearScreen();
    displayTitle();

    game_progress = trollGameLoop(game_progress);

    game_progress = sphinxGameLoop(game_progress);

    game_progress = blacksmithGameLoop(game_progress);


    bool met_door = false;
    bool met_fairy = false;
    while (game_progress < Progress::HAVE_GEMMED_KEY) {
        game_progress= speakWithDoor(met_door, game_progress);
        met_door = true;

        if (game_progress < Progress::HAVE_RUBY) {

            std::cout << "\nYou follow the ANCIENT STONE DOOR's instructions, and head off in search of the fairy.\n\n";
            delay(4000);
            std::cout << "After a few minutes of searching...\n";
            delay(2500);

            game_progress = speakWithFairy(met_fairy);
            met_fairy = true;
        }
    }

    // TODO: You return to the door with the Ruby now set in the key. He graciously opens,
    // and lets you out into the forest you left so vertically earlier. Sourly, you realise
    // you didn't actually use the key to open the door.

    // game_progress = Progress::COMPLETED_GAME
}
