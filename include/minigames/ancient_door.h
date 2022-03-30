#include <iostream>
#include <string>
#include "../constants.h"
#include "../ise102.h"


/* Prints introductory dialogue about the ANCIENT STONE DOOR.
 *
 * Returns: Progress
 *   The player's progress through the game.
*/
Progress notMetDoorDialogue() {
    std::cout << "As you leave the forge, you see an enormous, ANCIENT STONE DOOR. A sculpted face in the surface speaks.\n\n";

    delay(2000);

    std::cout
        << "ANCIENT STONE DOOR:\n"
        << " Hello traveller, I see you are trying to return to the forest.\n";

    delay(3000);

    std::cout
        << " I am afraid I cannot let you pass.\n"
        << " The key you possess does not contain a RUBY!\n";

    delay(3000);

    std::cout
        << "\n Speak with THE FAIRY, he will help you acquire a RUBY.\n\n";

    delay(2000);

    return Progress::HAVE_FORGED_KEY;
}


/* Prints dialogue with the ANCIENT STONE DOOR about
 * progress on collecting a ruby.
 *
 * Args:
 *   has_ruby: bool - Whether the player has a ruby.
 *
 * Returns: Progress
 *   The player's progress through the game.
*/
Progress metDoorDialogue(bool has_ruby) {
    std::cout << "\nYou decide to return to the door.\n\n";

    delay(3000);

    std::cout
        << "ANCIENT STONE DOOR:\n"
        << " Welcome back traveller!\n"
        << " Have you acquired a RUBY?\n\n";

    delay(3000);

    if (!has_ruby) {
        std::cout
            << " No? Well I suggest you speak with THE FAIRY again.\n"
            << " I hope you have better luck this time.\n\n";

        delay(3000);

        return Progress::HAVE_FORGED_KEY;
    }

    else {
        std::cout
            << " Yes? Wonderful!\n"
            << " Insert it into your SILVER KEY, and I will gladly let you go.\n\n";

        delay(3000);

        return Progress::HAVE_GEMMED_KEY;
    }
}


/* Prints appropriate dialoge with the ANCIENT STONE DOOR
 * about the player's progress.
 *
 * Args:
 *   met_door: bool - Whether the player has spoken to the door before.
 *   game_progress: Progress - The player's progress through the game.
 *
 * Returns: Progress
 *   The player's progress through the game.
*/
Progress speakWithDoor(bool met_door, Progress game_progress) {
    if (!met_door) {
        return notMetDoorDialogue();
    }

    else if (met_door && game_progress < Progress::HAVE_RUBY) {
        return metDoorDialogue(false);
    }

    else {
        return metDoorDialogue(true);
    }
}
