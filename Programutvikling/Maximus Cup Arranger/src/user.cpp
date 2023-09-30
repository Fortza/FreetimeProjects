#include "user.h"

using namespace std;

/**
 * Construct a new User:: User object
 */
User::User() {
    id = 0;
    firstName = "";
    lastName = "";
    day = 0;
    month = 0;
    year = 0;
    userName = "";
    password = "";
}

/**
 * @brief Construct a new User:: User object from file.
 * 
 * @param in - input file stream.
 * @param id - user ID integer.
 * @see readFromFile().
 */
User::User(ifstream& in, const int& id) {
    readFromFile(in, id);
}
/**
 * Destroys the User:: User object
 */
User::~User() {
}

/**
 * Logs a user into their account.
 * 
 * @see HelperFunctions::sanetizeInput().
 */
void User::logIn() {
    userName = "";
    password = "";
    cout << "\n\tEnter username: ";
    getline(cin, userName);
    userName = help.sanetizeInput(userName);
    cout << "\tEnter password: ";
    getline(cin, password);
    password = help.sanetizeInput(password);
}

/**
 * @brief Logs a user out of their account.
 * 
 */
void User::logOut() {
    cout << "\nLogging out.." << '\n';
    loggedIn = false;
}

/**
 * @brief Reads a user from file and sets the users
 * datamembers.
 * 
 * @param in - Input file stream.
 * @param id - User ID integer.
 * @see HelperFunctions::SplitString().
 */
void User::readFromFile(ifstream& in, const int id) {
    this->id = id;
    string allOfLine = "";
    getline(in, allOfLine);
    int i = 0;
    for (const auto& val : help.splitString('*', allOfLine)) {
        switch (i) {
            case 0:
                break;
            case 1:
                firstName = val;
                break;
            case 2:
                lastName = val;
                break;
            case 3:
                day = stoi(val);
                break;
            case 4:
                month = stoi(val);
                break;
            case 5:
                year = stoi(val);
                break;
            case 6:
                userName = val;
                break;
            case 7:
                password = val;
                break;
            default:
                cout << "\nWarning, incorrect data stored in user database!" << '\n';
                break;
        }
        i++;
    }
}

/**
 * @brief Writes a user object's datamembers to file.
 * 
 * @param out - Output file stream.
 */
void User::writeToFile(ofstream& out) {
    out << id << '*' << firstName << '*' << lastName << '*'
        << day << '*' << month << '*' << year << '*'
        << userName << '*' << password << '*' << '\n';
}

/**
 * @brief Reads user input from terminal and
 * sets the user object's datamembers.
 * 
 * @param id - User ID integer.
 */
void User::readData(const int id) {
    this->id = id;
    cout << "\nAccount creation started...";
    do {
        cout << "\nEnter name (not username)"
             << "\nFirst name: ";
        getline(cin, firstName);
    } while (help.checkForIllegalCharacters(firstName));
    do {
        cout << "\tLast name: ";
        getline(cin, lastName);
    } while (help.checkForIllegalCharacters(lastName));
    cout << "\nDate of birth...";
    cout << "\n\tBirth year";
    year = help.readInt(MIN_YEAR, MAX_YEAR);
    cout << "\tBirth Month";
    month = help.readInt(MIN_MONTH, MAX_MONTH);
    cout << "\tBirth day";
    day = help.readInt(MIN_DAY, MAX_DAY);
    
    do {
        cout << "\nUser account information...";
        cout << "\n\tNew username: ";
        getline(cin, userName);
    } while (help.checkForIllegalCharacters(userName));
    do {
        cout << "\tNew password: ";
        getline(cin, password);
    } while (help.checkForIllegalCharacters(password));
    cout << "\nUser account '"<< userName <<"' created!\n\n";
}

/**
 * @brief Prints out all relavant data beloning to the 
 * user obejct to terminal.
 * 
 */
void User::printData() {
    cout << "Username: " << userName << '\n'
         << "First name: " << firstName << '\n'
         << "Last name: " << lastName << '\n'
         << "Date of birth (dd/mm/yyyy): "
         << day << '/'
         << month << '/'
         << year << '\n';
}

/**
 * @brief Gets the user obejct's userName.
 * 
 * @return string* - Pointer to userName string.
 */
string* User::getUserName() {
    return &userName;
}

/**
 * @brief Gets the user object's password.
 * 
 * @return string* - Pointer to password string.
 */
string* User::getPassword() {
    return &password;
}

string User::getFirstName(){
    return firstName;
}