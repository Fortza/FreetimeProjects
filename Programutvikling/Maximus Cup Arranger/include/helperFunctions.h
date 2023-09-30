#ifndef __HELPER_FUNCTIONS_H
#define __HELPER_FUNCTIONS_H

#include <cctype>    // toupper
#include <cstdlib>   // atoi, atof
#include <iostream>  // cin, cout
#include <regex>     // regular expression replace
#include <string>    // string
#include <vector>    // vector

#include "constants.h"

/**
 * Class which holds functions that is used frequently in
 * other classes. For avoiding unnecessary code duplication.
 * 
 */
class HelperFunctions {
   public:
    char readChar();
    int readInt(const int min, const int max);
    std::string sanetizeInput(const std::string &str);
    bool checkForIllegalCharacters(const std::string &str);
    std::vector<std::string> splitString(const char splitOn, const std::string str);
    int rnd(int low, int high);
};

#endif  // __HELPER_FUNCTIONS_H