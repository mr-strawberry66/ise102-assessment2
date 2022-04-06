#include <string>

#include "../constants.h"


/* Abstract class to inherit from when creating
 * a new creature and minigame.
*/
class Creature {
    public:
        /* Virtual method to play the child creature's game loop.
         *
         * Returns: Progress
         *   The player's progress
         */
        virtual Progress gameLoop(Progress game_progress) = 0;
};
