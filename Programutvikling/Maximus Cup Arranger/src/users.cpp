#include "users.h"

using namespace std;

/**
 * @brief Construct a new Users:: Users object
 * 
 * @see readFromFile().
 */
Users::Users() {
    readFromFile();
}

/**
 * @brief Destroy the Users:: Users object and cleans memory.
 * 
 * @see writeToFile().
 * @see clearUsers().
 */
Users::~Users() {
    writeTofile();
    clearUsers();
}

/**
 * @brief Checks if the provided usename and password 
 * input is correct
 * 
 * @param userName - Pointer to userName string.
 * @param password - Pointer to password string.
 * @return User* - Pointer to user object if existing, nullptr otherwise.
 */
User *Users::checkUserDetails(const string *userName, const string *password) {
    if (allUsers.size() > 0) {
        for (const auto &val : allUsers) {
            if (*val->getUserName() == *userName && *val->getPassword() == *password)
                return val;
        }
    } else
        cout << "\nError: No users found!" << '\n';
    return nullptr;
}

/**
 * @brief Logs a user into their account, takes user input from CLI.
 * 
 * @see User::logIn().
 * @see checkUserDetails().
 * @see User::getUserName().
 * @see User::getPassword()
 * @see HelperFunctions::readChar().
 */
void Users::logIn() {
    char abort;
    User tmpUser;
    do {
        abort = '\0';
        tmpUser.logIn();
        currentSessionUser = checkUserDetails(tmpUser.getUserName(), tmpUser.getPassword());
        if (!currentSessionUser) {
            cout << "\nIncorrect username or password!" << '\n'
                 << "\tTry again (Y/n)?: ";
            abort = help.readChar();
        }
    } while (!currentSessionUser && abort != 'N');
    if (abort == 'N') cout << "\nLogin aborted" << '\n';
    if (currentSessionUser) {
        currentSessionUser->loggedIn = true;
        cout << "\n\nWelcome " << currentSessionUser->getFirstName() << "!" << "\n\n";
    }
}

/**
 * @brief Logs a user out of their account.
 * 
 * @see User::logOut().
 */
void Users::logOut() {
    if (currentSessionUser) {
        currentSessionUser->logOut();
        cout << "Goodbye " << currentSessionUser->getFirstName() << "!" << "\n\n";
    }
}

/**
 * @brief Adds a new user object pointer, which is then pushed onto
 * the allUsers vector.
 * 
 * @see User::readData()
 */
void Users::add() {
    allUsers.push_back(new User);
    allUsers.back()->readData(allUsers.size()-1);
}

/**
 * @brief Clears and cleans the User object pointers from memory.
 * 
 */
void Users::clearUsers() {
    for (int i = 0; i < allUsers.size(); i++) {
        delete allUsers[i];
    }
    allUsers.clear();
}

/**
 * @brief Prints all of the users relevant datamembers.
 * 
 * @see User::printData().
 */
void Users::printData() {
    for (const auto &val : allUsers) {
        val->printData();
    }
}

void Users::readData() {
}

/**
 * @brief Writes all users to file.
 * 
 * @see User::writeToFile()
 */
void Users::writeTofile() {
    ofstream file(USERS_FILE_PATH);
    file << allUsers.size() << '\n';
    for (const auto &user : allUsers) {
        user->writeToFile(file);
        //file << "*\n";
    }
}

/**
 * @brief Reads all users from file and adds the user
 * object pointer to the allUsers vector.
 * 
 * @see User::User()
 */
void Users::readFromFile() {
    int totalAmount, i;
    totalAmount = i = 0;
    ifstream file(USERS_FILE_PATH);
    if (file) {
        file >> totalAmount;
        file.ignore();
        while (!file.eof() && i < totalAmount) {
            allUsers.push_back(new User(file, i));
            i++;
        }
        file.close();
    } else
        cout << "\nWarning: " << USERS_FILE_PATH << " could not be found!\n";
}

/**
 * @brief Prints the menu choices to CLI.
 * 
 */
void Users::printMenu() {
    cout << "..:::User Menu:::.. "<< '\n'
         << "1 - Login" << '\n'
         << "2 - Create new account" << '\n'
         << "0 - Quit and Save!" << '\n';
}

/**
 * @brief Gets the current session user object's pointer.
 * 
 * @return User* - Pointer to user object, nullptr if no object.
 */
User *Users::getUser() {
    return currentSessionUser;
}

/**
 * @brief Main menu which prints the menu choices
 * to terminal and waits for user input.
 * 
 * @return true - User is logging out.
 * @return false - User is not logging out.
 * @see logIn()
 * @see printMenu().
 * @see HelperFunctions::readChar().
 */
bool Users::menu() {
    bool loggedIn, logOut;
    int choice;
    do {
        loggedIn = false;
        logOut = false;
        printMenu();
        cout << "Command";
        choice = help.readInt(0, 2);
        switch (choice) {
            case 1:
                logIn();
                break;
            case 2:
                add();
                break;
            case 0:
                logOut = true;
                break;
            default:
                cout << "\nIllegal choice!" << '\n';
                break;
        }
        if (currentSessionUser != nullptr) loggedIn = currentSessionUser->loggedIn;
    } while (choice != 0 && !loggedIn);
    return logOut;
}