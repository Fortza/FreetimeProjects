#include "teams.h"

#include <iomanip>

using namespace std;

/**
 * @brief Constructor for class Teams.
 */
Teams::Teams() { readFromFile(); }

/**
 * @brief Deconstructor for class Teams.
 */
Teams::~Teams() {
    writeToFile();
    for (Team*& team : allTeams) {
        delete team;
    }
    allTeams.clear();
}

/**
 * @brief Creates new team and adds to vector of teams.
 *
 * @see Team::readData();
 */
void Teams::addTeam() {
    string tempName;
    bool okName;
    Team* newTeam;
    newTeam = new Team;

    do {
        okName = true;
        do {
        cout << "\n\tEnter name for new team: ";
        getline(cin, tempName);
        if (tempName.length() > 21){
            cout << "\nMax 20 characters!\n";
        }
        }while(tempName.length() > 21);
        
        if (help.checkForIllegalCharacters(tempName)) {
            okName = false;
            cout << "Name contains bad characters.\n";
        }
        for (auto& team : allTeams) {
            if (tempName == team->returnName()) {
                okName = false;
                cout << "Team name already exists.\n";
            }
        }
    } while (okName == false || tempName == "");
    newTeam->readData(tempName, allTeams.size());
    allTeams.push_back(newTeam);
}

/**
 * @brief Same function as Teams::~Teams().
 */
void Teams::clearTeams() {
    for (Team*& team : allTeams) {
        delete team;
    }
    allTeams.clear();
}


/**
 * @brief Writes teams to file.
 *
 * @param out  - File object that writes teams to file.
 * @see Team::writeToFile(...)
 */
void Teams::writeToFile() {
    ofstream out(TEAMS_FILE_PATH);
    out << allTeams.size() << '\n';
    for (Team*& team : allTeams) {
        team->writeToFile(out);
    }
}

/**
 * @brief Reads teams from file.
 *
 * @param in  - File object that reads from file.
 * @see Team::readFromFile(...);
 */
void Teams::readFromFile() {
    ifstream in(TEAMS_FILE_PATH);
    if (in) {
        int numberOfTeams = 0;
        in >> numberOfTeams;
        in.ignore();
        for (int i = 0; i < numberOfTeams; i++) {
            Team *newTeam;
            newTeam = new Team;
            newTeam->readFromFile(in);
            allTeams.push_back(newTeam);
        }
        in.close();
    } else cout << "\nWarning: " << TEAMS_FILE_PATH << " could not be found!\n";
}

void Teams::printMenu() {
    cout << "\n..:::Teams Menu:::.." << '\n'
         << "1 - Add teams" << '\n'
         << "2 - Show teams" << '\n'
         << "0 - Back to Main Menu";
}

void Teams::menu() {
    int choice;
    do {
        printMenu();
        cout << "\nCommand";
        choice = help.readInt(0, 2);
        switch (choice) {
            case 0:
                break;
            case 1:
                addTeam();
                break;
            case 2:
                printData();
                break;
            default:
                cout << "\nIllegal input!" << '\n';
                break;
        }
    } while (choice != 0);
}
/**
 * @brief
 * Returns the amount of teams added
 * @return int
 */
int Teams::howManyTeams() { 
    return allTeams.size(); 
}

/**
 * @brief
 * Prints the name of all teams
 */
void Teams::printTeamName() {
    cout << setw(10);
    for (int i = 0; i < allTeams.size(); i++) {
        cout << i + 1 << "." << allTeams[i]->printTeamName();
        int temp = 25 - allTeams[i]->printTeamName().length();
        cout << setw(temp);
        // For hver tredje element, \n
        if (i % 3 == 2) {
            cout << "\n" << setw(10);
        }
    }
    cout << "\n";
}

/**
 * @brief Prints data from all teams to screen.
 *
 * @see Team::printData();
 */
void Teams::printData() {
    int i = 3;
    int j = 0;
    int k = 0;
    int f = 0;
    int g = 0;
    int temp = 0;
    cout << "\n\n";
    if (allTeams.size() > 0) {
        for (i; i < allTeams.size(); i += 3) {
            for (k; k < i; k++) {
                cout << "Team: " << allTeams[k]->printTeamName();
                int temp = 27 - allTeams[k]->printTeamName().length();
                cout << setw(temp);
            }
            cout << "\n";
            for (j; j < k; j++) {
                cout << "Abbrv: " << allTeams[j]->returnAbbrv();
                int temp = 27 - 3;
                cout << setw(temp);
            }
            cout << "\n";
            for (f; f < j; f++) {
                cout << "Players: " << allTeams[f]->returnPlayers();
                int temp = 27 - 2;
                cout << setw(temp);
            }
            /*
            cout << "\n";
            for (g; g < f; g++) {
                cout << "Goals: " << allTeams[g]->returnGoals();
                int temp = 27 - 1;
                cout << setw(temp);
            }
            */
            cout << "\n\n";
        }
        i -= 3;
        // Printing last remaining teams.
        for (i; i < allTeams.size(); i++) {
            cout << "Team: " << allTeams[i]->printTeamName();
            int temp = 27 - allTeams[i]->printTeamName().length();
            cout << setw(temp);
        }
        cout << "\n";
        for (j; j < i; j++) {
            cout << "Abbrv: " << allTeams[j]->returnAbbrv();
            int temp = 27 - 3;
            cout << setw(temp);
        }
        cout << "\n";
        for (f; f < j; f++) {
            cout << "Players: " << allTeams[f]->returnPlayers();
            int temp = 27 - 2;
            cout << setw(temp);
        }
        /*cout << "\n";
        for (g; g < f; g++) {
            cout << "Goals: " << allTeams[g]->returnGoals();
            int temp = 27 - 1;
            cout << setw(temp);
        }
        */
        cout << "\n\n";
    } else {
        cout << "No teams saved.\n";
    }
}

/**
 * @brief 
 * 
 * @param nr 
 * @return int 
 */
int Teams::returnTeamId(const int nr){
    return allTeams[nr]->returnTeamId();
}

/**
 * @brief 
 * 
 * @param nr 
 */
void Teams::printTeamName(const int nr){
    for (int i = 0; i < allTeams.size(); i++){
        if (nr == allTeams[i]->returnTeamId()){
            cout << allTeams[i]->printTeamName() << "\n";
        }
    }
}

/**
 * @brief 
 * 
 * @param nr 
 */
string Teams::returnName(const int nr){
    string temp = "";
    for (int i = 0; i < allTeams.size(); i++){
        if (nr == allTeams[i]->returnTeamId()){
            return allTeams[i]->printTeamName();
        }
    }
    return temp;
}

/**
 * @brief 
 * Returns place in vector 
 * @param id 
 * @return int 
 */
int Teams::returnPlaceInVector(const int id){
    for (int i = 0; i < allTeams.size(); i++){
        if (id == allTeams[i]->returnTeamId()){
            return i;
        }
    }
    return -1;
}


Team* Teams::getTeam(const int & id){
    if (allTeams.size() >= id){
        return allTeams[id];
    }
    return nullptr;
}