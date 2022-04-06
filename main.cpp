/* ISE102 - Assessment 2: Adventure.
 * 
 * Code extended and refactored 
 * by Sam Kenney - 2022
*/
#include <iostream>
#include <string>
#include <vector>

#include "include/constants.h"
#include "include/game_screens.h"
#include "include/handy_functions.h"
#include "include/ise102.h"

#include "include/minigames/creature.h"

#include "include/minigames/ancient_door.h"
#include "include/minigames/blacksmith.h"
#include "include/minigames/fairy.h"
#include "include/minigames/sphinx.h"
#include "include/minigames/troll.h"


/* Entry point for code.
 *
 * Main game loop.
*/
int main() {
    // Set a seed for randoms generated
    // within this program.
    srand(time(0));

    // Initialise each creature and 
    // add them to a std::vector.
    Troll troll;
    Sphinx sphinx;
    Blacksmith blacksmith;
    Fairy fairy;
    AncientStoneDoor door;

    std::vector<Creature*> creatures;

    creatures.push_back(&troll);
    creatures.push_back(&sphinx);
    creatures.push_back(&blacksmith);
    creatures.push_back(&fairy);
    creatures.push_back(&door);

    // Ask where in the game the player
    // would like to start from.
    Progress game_progress = getPlayerProgress();

    clearScreen();
    displayTitle();

    // Itterate over each creature and
    // start the appropriate game loop
    // based on the player's starting
    // point.
    for (auto creature : creatures) {
        game_progress = creature->gameLoop(game_progress);
    }

    // If the player has succeeded, show
    // the game complete text.
    if (game_progress != Progress::FAILED) {
        displayGameComplete();
        game_progress = Progress::COMPLETED_GAME;
    }

    return 0;
}
