#include "tournaments.h"

using namespace std;

/**
 * @brief Construct a new Tournaments:: Tournaments object
 * Main menu for tournaments.
 */
Tournaments::Tournaments() {
    int choice;
    readFromFile();
    do {
        printMenu();
        cout << "Command";
        choice = help.readInt(0, 2);
        switch (choice) {
            case 0:
                break;
            case 1:
                add();
                break;
            case 2:
                spesificTournament();
                break;
            default:
                cout << "\nIllegal input!" << '\n';
                break;
        }
    } while (choice != 0);
}

/**
 * @brief Destroy the Tournaments:: Tournaments object
 * 
 * @see clearTournaments().
 */
Tournaments::~Tournaments() {
    writeToFile();
    clearTournaments();
}

/**
 * @brief Adds a new tournament object pointer which is then 
 * pushed into the allTournaments vector.
 * 
 * @see Tournament::readData().
 */
void Tournaments::add() {
    allTournaments.push_back(new Tournament);
    if(!allTournaments.back()->readData(allTournaments.size())){
        delete allTournaments.back();
        allTournaments.pop_back();
    }
}


/**
 * @brief Clears and cleans the Tournaments object pointers from 
 * memory.
 * 
 */
void Tournaments::clearTournaments() {
    for (int i = 0; i < allTournaments.size(); i++) {
        delete allTournaments[i];
    }
    allTournaments.clear();
}

/**
 * @brief Prints all tournaments and their data members
 * to CLI.
 * 
 * @see Tournament::printData().
 */
void Tournaments::printData() {
    for (const auto& val : allTournaments) {
        val->printData();
    }
}

void Tournaments::readData() {
}

/**
 * @brief Writes all tournaments to file.
 * 
 * @see Tournament::writeToFile().
 */
void Tournaments::writeToFile() {
    ofstream file(TOURNAMENTS_FILE_PATH);
    file << allTournaments.size() << '\n';
    for (const auto& val : allTournaments) {
        val->writeToFile(file);
    }
}

/**
 * @brief Reads tournaments from file.
 * 
 * @see Tournament::readFromFile().
 */
void Tournaments::readFromFile() {
    int numOfTournaments, i;
    numOfTournaments = i = 0;
    ifstream file(TOURNAMENTS_FILE_PATH);
    std::vector<string> tmp;
    if (file) {
        file >> numOfTournaments;
        file.ignore();
        while (!file.eof() && i < numOfTournaments) {
            allTournaments.push_back(new Tournament);
            allTournaments.back()->readFromFile(file, i);
            allTournaments.back()->matches.readFromFile(file);
            i++;
        }
        file.close();
    } else
        cout << "\nWarning: " << TOURNAMENTS_FILE_PATH << " could not be found!" << '\n';
}

/**
 * @brief Prints tournament menu options to CLI.
 * 
 */
void Tournaments::printMenu() {
    cout <<"\n\n..:::Tournament Menu:::.."<< "\n"
         << "1 - Add new tournament" << '\n'
         << "2 - Tournaments" << '\n'
         << "0 - Back to main menu" << '\n';
}

/**
 * @brief Prints all tournament names and lets
 * the user choose which spesific tournament to display.
 * 
 * @see Tournament::getName().
 * @see tournament::printData().
 */
int Tournaments::selectTournament() {
    int i = 1;
    int choice = 0;
    if (allTournaments.size() > 0) {
        cout << "\nAll tournaments:\n";
        for (const auto& val : allTournaments) {
            cout << i << " - " << *val->getName() << '\n';
            i++;
        }
        cout <<"0 - Back to Tournament menu\n";
        cout << "Command";
        choice = help.readInt(0, allTournaments.size());
        if (choice > 0) {
            return choice;
        }
    } else
        cout << "\nWarning: No tournaments found!" << '\n';
    return -1;
}

/**
 * Asks if user wants to edit the match.
 *
 * @see Tournaments::editMatch().
 * */
void Tournaments::spesificTournament() {
    int choice = selectTournament() - 1;
    if (choice >= 0) {
        allTournaments[choice]->printData();

        cout << "\nDo you wish to edit a match? (Y/n): ";
        char c = help.readChar();
        cout << "\n";
        if (c == 'Y') {
            allTournaments[choice]->editMatch();
        }

    }
}

/**
 * Edits a specific match.
 * */
void Tournaments::editSpesificMatch() {
    int choice = selectTournament() - 1;
    if (choice <= 0) {
        allTournaments[choice]->editMatch();
    }
}