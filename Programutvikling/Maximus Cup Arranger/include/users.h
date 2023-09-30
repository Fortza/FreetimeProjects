#ifndef __USERS_H
#define __USERS_H

#include "user.h"

/**
 * @brief Subclass Users, inherits from User class.
 * 
 */
class Users : public User {
   private:
    User* currentSessionUser = nullptr;
    HelperFunctions help;

   public:
    std::vector<User*> allUsers;

    Users();
    virtual ~Users();
    User* checkUserDetails(const std::string* name, const std::string* password);
    void logIn();
    void logOut();
    void add();
    void clearUsers();
    void printData();
    void readData();
    void writeTofile();
    void readFromFile();
    void printMenu();
    User* getUser();
    bool menu();
};

#endif  // __USERS_H