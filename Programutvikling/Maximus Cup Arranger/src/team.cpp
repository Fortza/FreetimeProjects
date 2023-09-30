#include "team.h"
using namespace std;

/**
 * @brief Constructor for class Team.q
 *
 */
Team::Team() {
    id = 0;
    name = "";
    numberOfPlayers = 0;
    goals = 0;
}

/**
 * @brief Deconstructor for class Team.
 */
Team::~Team() { }

/**
 * @brief Writes all info about team to user
 */
void Team::printData() {
    cout << "Team name: " << name << '\n'
         << "Abbrv:     " << abbrv << '\n'
         << "Players:   " << numberOfPlayers << '\n'
         << "Goals:     " << goals << '\n';
}

/**
 * @brief Collects input about new team from user
 */
void Team::readData(const string newName, const int number) {
    id = number;
    name = newName;
    do {
        cout << "\tWrite abbreviation of team name (3 characters): ";
        getline(cin, abbrv);
    } while (abbrv.size() != 3);
    cout << "\tWrite amount of players on team: ";
    numberOfPlayers = help.readInt(1, 99);
}

/**
 * @brief Writes team data to file.
 *
 * @param out  - File object that writes to file.
 */
void Team::writeToFile(ofstream & out) {
    out << id << '*' << name << '*' << abbrv << '*' << numberOfPlayers << '*' << '\n';
}

/**
 * @brief Reads team data from file.
 *
 * @param in  - File object that reads from file.
 */
void Team::readFromFile(ifstream & in) {
    string data;
    getline(in, data);
    vector<string> splitData;
    splitData = help.splitString('*', data);
    id = stoi(splitData[0]);
    name = splitData[1];
    abbrv = splitData[2];
    numberOfPlayers = stoi(splitData[3]);
    // To-do Needs error handling!


    /*vector <string> splitData;
    in >> data;
    splitData = help.splitString('*', data);
    id = stoi(splitData[0]);
    name = splitData[1];
    numberOfPlayers = stoi(splitData[2]);*/
}

/**
 * @brief Returns team name.
 *
 * @return String 'name'.
 */

string Team::returnName() {
    return name;
}

string Team::returnAbbrv() {
    return abbrv;
}

int Team::returnGoals() {
    return goals;
}

int Team::returnPlayers() {
    return numberOfPlayers;
}

string Team::printTeamName(){
    return name;
}

int Team::returnTeamId(){
    return id;
}