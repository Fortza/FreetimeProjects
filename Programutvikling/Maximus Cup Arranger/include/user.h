#ifndef __USER_H
#define __USER_H

#include <fstream>   // Fil input/output
#include <iostream>  // cout, cin
#include <list>      // list
#include <string>    // string
#include <vector>    // vector

#include "helperFunctions.h"

/**
 * Main class for users which holds the
 * relevant datamembers for a spesfic user.
 */
class User {
   private:
    HelperFunctions help;
    // Unique ID number
    int id;
    // Name
    std::string firstName;
    std::string lastName;
    // Date of birth
    int day;
    int month;
    int year;
    // Username
    std::string userName;
    // Password
    std::string password;

   public:
    bool loggedIn;

    User();
    User(std::ifstream& in, const int& id);
    virtual ~User();
    virtual void logIn();
    virtual void logOut();
    virtual void readFromFile(std::ifstream& in, const int idNumber);
    virtual void writeToFile(std::ofstream& out);
    virtual void readData(const int id);
    virtual void printData();
    std::string* getUserName();
    std::string* getPassword();
    std::string getFirstName();
};

#endif  //__USER_H