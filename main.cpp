/*
* What To Do
*
* - Format the creature dialogue using fmt's prints' styles
* - Use colour/style elsewhere to communicate the player's situation,
*   their choices.
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


int main() {
    srand(time(0));

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

    Progress game_progress = getPlayerProgress();

    clearScreen();
    displayTitle();

    for (auto creature : creatures) {
        game_progress = creature->gameLoop(game_progress);
    }

    if (game_progress != Progress::FAILED) {
        displayGameComplete();
        game_progress = Progress::COMPLETED_GAME;
    }

    return 0;
}
