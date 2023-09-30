#include "helperFunctions.h"
#include <random>
using namespace std;

/**
 * Reads the first character from the user input.
 *
 * Note: This function is heavily inspired by Frode Haugs
 * lesChar() function from LesData2.h which can be found here:
 * https://folk.ntnu.no/frh/ooprog/oppgaver/
 *
 * @return char - Returns capitalized character.
 */
char HelperFunctions::readChar() {
    char tmp;
    cin >> tmp;
    cin.ignore(MAXCHAR, '\n');
    return (toupper(tmp));
}

/**
 * Reads an interger from user input and returns it.
 *
 * Note: This function is heavily inspired by Frode Haugs
 * lesInt() function from LesData2.h which can be found here:
 * https://folk.ntnu.no/frh/ooprog/oppgaver/
 *
 * @param min - Minimum value the interger can be.
 * @param max - Maximum value the interger can be.
 * @return int - Returns an integer between the min and max value.
 */
int HelperFunctions::readInt(const int min, const int max) {
    char buffer[MAXCHAR] = "";
    int number;
    bool error;
    do {
        number = 0;
        error = false;
        cout << " (" << min << " - " << max << "): ";
        cin.getline(buffer, MAXCHAR);
        number = atoi(buffer);
        if (number == 0 && buffer[0] != '0') {
            error = true;
            cout << "\nError, character is not an integer!" << '\n';
        }
    } while (error || number < min || number > max);
    return number;
}

/**
 * Sanetizes input string, i.e. removes illegal/speacial characters
 * from said string and returns sanetized string.
 *
 * @param str - String to be sanetized.
 * @return string - Sanetized string.
 */
string HelperFunctions::sanetizeInput(const string &str) {
    if (checkForIllegalCharacters(str)) {
        string sanetizedStr;
        regex re("[^a-zA-Z0-9]");
        sanetizedStr = regex_replace(str, re, "");
        return sanetizedStr;
    }
    return str;
}

/**
 * Checks if string contains illegal characters.
 *
 * @param str - String to be checked.
 * @return true - If string has illegal characters.
 * @return false - If string is clean.
 */
bool HelperFunctions::checkForIllegalCharacters(const string &str) {
    regex re("[^a-zA-Z0-9 ]");
    if (regex_search(str, re)) {
        cout << "\nIllegal character(s) detected! Plase only use: A-z 0-9"
             << '\n';
        return true;
    }
    return false;
}

/**
 * Splits string based on provided input.
 *
 * @param splitOn - Character to split the string on.
 * @param str - String to be split.
 * @return vector<string> - Vector array of the split strings.
 */
vector<string> HelperFunctions::splitString(const char splitOn, const string str) {
    vector<string> split;
    string tmp = "";
    for (const auto &val : str) {
        if (val == splitOn) {
            split.push_back(tmp);
            tmp = "";
        } else
            tmp += val;
    }
    return split;
}

/**
 * @brief Returns random int from given area
 *
 * @param low - Smallest random number that can be returned
 * @param high - Highest random number that can be returned
 * @return dist(gen) - The random number
 */
int HelperFunctions::rnd(int low, int high) {
    static std::random_device device;
    static std::mt19937 gen(device());
    static std::uniform_int_distribution<int> dist(low, high);
    return dist(gen);
}