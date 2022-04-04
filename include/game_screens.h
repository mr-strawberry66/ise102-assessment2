#include <iostream>
#include <string>
#include "constants.h"
#include "ise102.h"


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


/* Display the game complete message at the end of the game.
 *
 * Returns: void
*/
void displayGameComplete() {
    std::cout << "The door's face becomes inanimate as it slowly creaks open, revealing a winding staircase.\n\n";

    std::cout << "As you traverse the mossy, derelict stairs, the structure slowly fades into a far more natural looking cave.\n\n";

    delay(3000);

    std::cout << "The smell of the the forest becomes apparent as you continue to ascend...\n\n";

    delay(2000);

    std::cout << "You see a bright light ahead of you...\n\n\n";

    delay(3000);

    std::cout << "++ Game complete ++\n\n";
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
        << "4. Chapter 4: The Fairy.\n"
        << "5. Chapter 5: The Escape.\n"
        << "> ";

    std::ws(std::cin);
    std::getline(std::cin, str_choice);

    int choice = std::stoi(str_choice);

    switch (choice) {
        case 1: return Progress::NO_PROGRESS;
        case 2: return Progress::HAVE_SILVER_ORE;
        case 3: return Progress::FOUND_BLACKSMITH;
        case 4: return Progress::HAVE_FORGED_KEY;
        case 5: return Progress::HAVE_RUBY;
        default: return Progress::NO_PROGRESS;
    }
}
