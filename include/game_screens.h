#include <iostream>
#include <string>
#include "constants.h"


/* Display the game title screen.
 *
 * Returns: void
*/
void displayTitle()
{
    std::cout
        << "   ______                    ______                   " << "\n"
        << "  / ____/___ __   _____     / ____/___ _____ ___  ___ " << "\n"
        << " / /   / __ `/ | / / _ \\   / / __/ __ `/ __ `__ \\/ _ \\" << "\n"
        << "/ /___/ /_/ /| |/ /  __/  / /_/ / /_/ / / / / / /  __/" << "\n"
        << "\\____/\\__,_/ |___/\\___/   \\____/\\__,_/_/ /_/ /_/\\___/ " << "\n";
    std::cout << "\n";
}


/* Display the game over message depending on your fate.
 *
 * Params:
 *   message: std::string - The game over message to display.
 *
 * Returns: void
*/
void displayGameOver(std::string message) {
    std::cout << message << "\n\n\n";
    std::cout << ("++ Game over ++\n\n");
}


/* Let the player decide which chapter to start from.
 *
 * This gives the player a pseudo save function.
 *
 * Returns: Progress
 *   Where the player should start from.
*/
Progress getPlayerProgress() {
    std::string str_choice;
    std::cout
        << "Which chapter would you like to begin your adventure from?:\n"
        << "1. Chapter 1: Trapped!\n"
        << "2. Chapter 2: The Riddle.\n"
        << "3. Chapter 3: The Forge.\n"
        << "> ";

    std::getline(std::cin, str_choice);

    int choice = std::stoi(str_choice);

    switch (choice) {
        case 1: return Progress::NO_PROGRESS;
        case 2: return Progress::HAVE_SILVER_ORE;
        case 3: return Progress::FOUND_BLACKSMITH;
        default: return Progress::NO_PROGRESS;
    }
}
