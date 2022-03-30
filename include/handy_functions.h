// Get access to things in constants while coding on replit.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "constants.h"
#include "ise102.h"
using namespace std;

using std::string;
// Takes in a minimum number (int) and a maximum number (int), returns a random
// number between the min and max (inclusive)
int randomInRange(int min, int max)
{
    int difference = max - min;
    int rand_in_range = min + (rand() % (difference+1));
    // send back the result.
    return rand_in_range;
}

// Prompts player to go with one of the available options
string getPlayerChoice(string choiceA, string choiceB)
{
    string choice = "";
    // TODO: Add a loop here so the player is asked for their choice until they
    // enter one of the two. If they don't, they see an error and have to input again.
    cout << "Enter your choice, " << choiceA << " or " << choiceB << "\n";
    cout << " > ";
    // print("Enter your choice, {0} or {1}\n", choiceA, choiceB);
    cin >> choice;
    return choice;
}

// Converts US/Imperial inches to metric (Système Internationale) cms.
int inchesToCms(int inches)
{
    // TODO: Check if this works. Fix it if it doesn't (google inches to cms)
    int cms = inches * 2.54f;
    return cms;
}

// Identifies a red gem's type given values for mohs_hardness and specific_gravity.
// Returns a constant from the enum `RedGem` in constants.h
// Data source: https://www.mymathtables.com/calculator/others/precise-gemstone-carat-weight-calculator.html
RedGem getRedGemKind(float mohs_hardness, float specific_gravity)
{
    // TODO: check if the provided values match known values/ranges in
    // https://www.mymathtables.com/calculator/others/precise-gemstone-carat-weight-calculator.html to identify the type.
    // For now, here's a dummy return value so the program compiles.
    return RedGem::UNIDENTIFIED_RED_GEM;
}
