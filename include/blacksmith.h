#include <iostream>
#include <string>
#include "constants.h"
#include "ise102.h"


/* Return a message to the player about the name they have provided.
 *
 * Params:
 *   name: std::string - The name the player has provided.
 *
 * Returns: std::string
 *   A message to the player about their name.
*/
std::string validateNameMessage(std::string message) {
    std::string full_message = "THE BLACKSMITH:\n  Hmmm...\n That IS a funny name, but, it is " + message + ".\n Try again.\n\n";

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

    if (name.length() < 20) {
        std::cout << validateNameMessage("not long enough");
            return Progress::HAVE_SILVER_ORE;
    }

    else if (name.length() > 20) {
        std::cout << validateNameMessage("too long");
            return Progress::HAVE_SILVER_ORE;
    }

    if (word_count < 3) {
        std::cout << validateNameMessage("too few words");
            return Progress::HAVE_SILVER_ORE;
    }

    else if (word_count > 3) {
        std::cout << validateNameMessage("too many words");
            return Progress::HAVE_SILVER_ORE;
    }
    else {
        std::cout
            << "THE BLACKSMITH:\n"
            << " HA HA HA! Well done!\n"
            << " Here, I will forge you the key.\n\n";

        delay(3000);

        std::cout << "You have acquired the SILVER KEY!\n\n";
        return Progress::HAVE_FORGED_KEY;
    }
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
Progress blacksmithMiniGame(bool met_blacksmith) {
    if (!met_blacksmith) {
        cout << "You've found THE BLACKSMITH!\n\n";

        cout
            << "THE BLACKSMITH:\n"
            << " Hello traveller! I am THE BLACKSMITH.\n"
            << " I can forge you a SILVER KEY, but in return, I require something from you.\n\n";

        delay(1000);
    }

    std::cout
        << " Tell me a funny name for your SILVER KEY.\n"
        << " This name must be three words long, and, it must be EXACTLY 20 characters long.\n\n";

    std::string name = "";

    std::cout << "Tell me a name.\n" << "> ";
    std::getline(cin, name);

    std::cout << "\n";

    int word_count = countWordsInString(name);

    return validateName(name, word_count);
}