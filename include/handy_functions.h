// Get access to things in constants while coding on replit.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

#include "constants.h"
#include "ise102.h"


/* Generate a random number betweena a minimum and a maximum (inclusive) value.
 *
 * Params:
 *   min: int - the lowest value to generate.
 *   max: int - the highest value to generate.
 *
 * Returns:
 *  int - a random number between min and max.
*/
int randomInRange(int min, int max)
{
    int difference = max - min;
    int rand_in_range = min + (rand() % (difference + 1));
    return rand_in_range;
}


/* Take a string and return it as upper case.
 *
 * Params:
 *   input: std::string - The string to be converted to upper case.
 *
 * Returns: std::string
 *   The input string converted to upper case.
*/
std::string toUpperCase(std::string input)
{
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}


/* Create a prompt for the player to enter one of two choices.
 *
 * If the player's choice is not one of the two choices, the prompt will
 * be repeated until the player enters one of the two choices.
 *
 * Params:
 *  choiceA: std::string - The first choice the player can make.
 *  choiceB: std::string - The second choice the player can make.
 *
 * Returns: std::string
 *  The player's choice as uppercase.
*/
std::string getPlayerChoice(std::string choiceA, std::string choiceB)
{
    std::string choice = "";
    const std::vector<std::string> CHOICES = {
        choiceA,
        choiceB,
    };

    while (true)
    {
        std::cout << "Enter your choice, " << choiceA << " or " << choiceB << "\n";
        std::cout << " > ";
        std::cin >> choice;

        choice = toUpperCase(choice);

        // Search the CHOICES vector for the player's choice.
        bool valid_choice = std::find(CHOICES.begin(), CHOICES.end(), choice) != CHOICES.end();

        if (valid_choice) return choice;

        std::cout << choice << " is not a valid choice.\n\n";
    }
}


/* Convert imperial inches to metric centimeters.
 *
 * Params:
 *   inches: int - The number of inches to convert.
 *
 * Returns: int
 *   The number of inches converted to centimeters.
*/
int inchesToCms(int inches)
{
    int cms = inches * 2.54f;
    return cms;
}


/* Identify a red gem's type based on the gem's hardness in mohs scale and the gem's specific gravity.
 *
 * If no match is found, return UNIDENTIFIED_RED_GEM.
 *
 * Gems are identified using values provided from
 * https://www.mymathtables.com/calculator/others/precise-gemstone-carat-weight-calculator.html
 *
 * Params:
 *   mohs_hardness: int - The gem's hardness in mohs scale.
 *   specific_gravity: float - The gem's specific gravity.
 *
 * Returns: RedGem
 *   The type of gem.
*/
RedGem getRedGemKind(float mohs_hardness, float specific_gravity)
{
    if (
        specific_gravity >= 3.50
        && specific_gravity <= 4.30
        && mohs_hardness >= 6.5
        && mohs_hardness <= 7.5
    ) return RedGem::GARNET;

    else if (
        specific_gravity >= 3.96
        && specific_gravity <= 4.05
        && mohs_hardness == 9.0
    ) return RedGem::RUBY;

    else if (
        specific_gravity >= 3.03
        && specific_gravity <= 3.25
        && mohs_hardness >= 7.0
        && mohs_hardness <= 7.5
    ) return RedGem::TOURMALINE;

    else if (
        specific_gravity >= 3.50
        && specific_gravity <= 4.30
        && mohs_hardness >= 6.5
        && mohs_hardness <= 7.5
    ) return RedGem::RHODOLITE;

    else if (
        specific_gravity >= 3.58
        && specific_gravity <= 4.06
        && mohs_hardness == 8.0
    ) return RedGem::SPINEL;

    else return RedGem::UNIDENTIFIED_RED_GEM;
}



/* Return a RedGem's name by it's index in RedGem enum.
 *
 * Params:
 *   index: int - The index of the RedGem in the enum.
 *
 * Returns: std::string
 *   The name of the RedGem.
*/
std::string getRedGemNameByNumber(int index) {
    switch(index) {
        case 1: return "GARNET";
        case 2: return "RUBY";
        case 3: return "TOURMALINE";
        case 4: return "RHODOLITE";
        case 5: return "SPINEL";
        default: return "UNIDENTIFIED RED GEM";
    }
}


/* Count the number of words in a string counting by spaces.
 *
 * Params:
 *   input: std::string - The string to count the words in.
 *
 * Returns: int
 *   The number of words in the string.
*/
int countWordsInString(std::string input)
{
    int word_count = 0;
    bool currently_in_word = false;

    // Itterate over each character in the string
    // if the character is a space, we are not in a word.
    // else, we are in a word and should increment the word count.
    for (char c : input) {
        if (c == ' ') {
            currently_in_word = false;
        }

        else if (!currently_in_word) {
            word_count ++;
            currently_in_word = true;
        }
    }

    return word_count;
}


/* Test to see if a std::string value can be converted to an integer.
 *
 * Params:
 *   input: std::string - The value to convert.
 * 
 * Returns: bool
 *   Whether the input can be converted or not.
*/
bool canParseInt(std::string input) {
    try {
        std::stoi(input);
        return true;
    }
    catch (...) {
        return false;
    }
}
