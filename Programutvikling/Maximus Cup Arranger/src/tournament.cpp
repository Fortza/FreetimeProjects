#include "tournament.h"

#include <algorithm>
#include <iomanip>

#include "helperFunctions.h"
#include "teams.h"

using namespace std;

Tournament::Tournament() {}

Tournament::~Tournament() {}

/**
 * @brief Prints out relevant data members to terminal.
 *
 * @see getStringFromEnum().
 */
void Tournament::printData() {
    int command = 0;
    do {
        cout << "\n..:::Tournament info:::.." << '\n'
             << "Name: " << name << '\n'
             << "Start date (dd/mm/yyyy): " << startDay << '/' << startMonth
             << '/' << startYear << '\n'
             << "End date (dd/mm/yyyy): " << endDay << '/' << endMonth << '/'
             << endYear << '\n'
             << "Format: " << getStringFromEnum(type) << "\n\n";
        matches.printData(totalNumberOfTeams);
    } while (command != 0);
}

/**
 * @brief Sets all relevant data members belonging to a
 * tournament object based on user input from CLI.
 *
 * @param id - Unique interger id of tornament.
 * @see HelperFunctions::sanetizeInput().
 * @see HelperFunctions::readInt().
 * @see checkIntForEvenNumber().
 */
bool Tournament::readData(const int & id) {
    if (tournamentTeams.howManyTeams() == 0) {
        cout << "\n\n\tThere are no teams added!\n";
        cout << "\tPlease add teams before you create tournament\n\n";
        return false;
    } else {
        this->id = id;
        cout << "\nCreating tournament...\n";
        cout << "\tEnter tournament name: ";
        getline(cin, name);
        name = help.sanetizeInput(name);
        cout << "\nWhen does tournament start?\n";
        cout << "\tStart year";
        startYear = help.readInt(MIN_YEAR, MAX_YEAR);
        cout << "\tStart month";
        startMonth = help.readInt(MIN_MONTH, MAX_MONTH);
        cout << "\tStart day";
        startDay = help.readInt(MIN_DAY, MAX_DAY);
        cout << "\nWhen does tournament end?\n";
        cout << "\tEnd year";
        endYear = help.readInt(startYear, MAX_YEAR);

        if (startYear == endYear) {
            cout << "\tEnd month";
            endMonth = help.readInt(startMonth, MAX_MONTH);
        } else {
            cout << "\tEnd month";
            endMonth = help.readInt(MIN_MONTH, MAX_MONTH);
        }

        if (startMonth == endMonth && startYear == endYear) {
            cout << "\tEnd day";
            endDay = help.readInt(startDay, MAX_DAY);
        } else {
            cout << "\tEnd day";
            endDay = help.readInt(MIN_DAY, MAX_DAY);
        }

        type = static_cast<tournamentType>(0);  // Always cup DO NOT REMOVE!

        do {
            cout << "\nHow many teams in tournament? (2/4/8/16)\n";
            cout << "\tChoose";
            totalNumberOfTeams = help.readInt(2, 16);
            if (totalNumberOfTeams > tournamentTeams.howManyTeams()) {
                cout << "\nNot enough teams for a tournament this large!\n";
            }

        } while (totalNumberOfTeams != 2 && totalNumberOfTeams != 4 &&
                 totalNumberOfTeams != 8 && totalNumberOfTeams != 16 ||
                 totalNumberOfTeams > tournamentTeams.howManyTeams());
        cout << "\n";

        if (tournamentTeams.howManyTeams() >= totalNumberOfTeams) {
            vector<int>
                teamsId;  // all teamIDs in tournament stored right here :D

            cout << "Pick teams for tournament\n";
            tournamentTeams.printTeamName();
            cout << "\n";

            for (int i = 0; i < totalNumberOfTeams; i++) {
                int temp = 0;
                cout << "Teams picked (" << i << "/" << totalNumberOfTeams
                     << ")\n";
                do {
                    cout << "\tPick team";
                    temp = help.readInt(1, tournamentTeams.howManyTeams()) - 1;
                    if (find(teamsId.begin(), teamsId.end(), temp) !=
                        teamsId.end()) {
                        cout << "\tTeam is already in tournament!\n";
                    }
                } while (find(teamsId.begin(), teamsId.end(), temp) !=
                         teamsId.end());
                teamsId.push_back(temp);
            }

            int tournamentMatches = totalNumberOfTeams / 2;

            cout << "\nConfigure tournament brackets manually or randomize?" << '\n'
                 << "1 - Manual configuration\n2 - Randomize" << '\n';
            cout << "Command";
            autoConfigure = help.readInt(1, 2) - 1;

            int teamNr1, teamNr2;
            Team *team1;
            Team *team2;

            // Random
            if (autoConfigure) {  // Automatic random config of match setups.
                vector<int> test;
                int nummer;
                do {
                    nummer = help.rnd(0, teamsId.size() - 1);
                    if (test.size() == 0) {
                        test.push_back(nummer);
                    } else if (find(test.begin(), test.end(), nummer) ==
                               test.end()) {
                        test.push_back(nummer);
                    }
                } while (test.size() != teamsId.size());
                int j = 0;
                for (int i = 0; i < tournamentMatches; i++) {
                    cout << "\n";
                    team1 = tournamentTeams.allTeams[test[j]];
                    team2 = tournamentTeams.allTeams[test[j + 1]];
                    matches.addRandomMatch(team1, team2);
                    j += 2;
                }
            } else if (!autoConfigure) {  // Manuel config of setting up
                                          // matches.
                for (int i = 0; i < tournamentMatches; i++) {
                    cout << "\n\nWhich teams will be in match " << i + 1 <<" ?";
                    cout << "\n" << setw(10);
                    for (int j = 0; j < teamsId.size(); j++) {
                        cout << j + 1 << "."
                             << tournamentTeams.returnName(teamsId[j]);
                        int temp =
                            25 -
                            tournamentTeams.returnName(teamsId[j]).length();
                        cout << setw(temp);
                        // For hver tredje element, \n
                        if (j % 3 == 2) {
                            cout << "\n" << setw(10);
                        }
                    }

                    cout << "\n\nChoose first team";
                    teamNr1 = help.readInt(1, teamsId.size());
                    team1 = tournamentTeams.allTeams[teamsId[teamNr1 - 1]];
                    do {
                        cout << "Choose second team";
                        teamNr2 = help.readInt(1, teamsId.size());
                        team2 = tournamentTeams.allTeams[teamsId[teamNr2 - 1]];
                        if (teamNr2 == teamNr1) {
                            cout << "Same team cannot be chosen.\n";
                        }
                    } while (teamNr2 == teamNr1);
                    matches.addMatch(team1, team2);

                    // Removes used teams from list of choices.
                    teamsId[teamNr2 - 1] = teamsId.back();
                    teamsId.pop_back();
                    teamsId[teamNr1 - 1] = teamsId.back();
                    teamsId.pop_back();
                }
            }
        }
    }
    return true;
}

/**
 * @brief Writes relvant tournament data members to file.
 *
 * @param out - Out file stream.
 */
void Tournament::writeToFile(ofstream &out) {
    out << 'T' << '*' << id << '*' << name << '*' << startDay << '*'
        << startMonth << '*' << startYear << '*' << endDay << '*' << endMonth
        << '*' << endYear << '*' << totalNumberOfTeams << '*' << type << '*'
        << autoConfigure << '*' << '\n';
    matches.writeToFile(out);
}

/**
 * @brief Reads and sets the appropriate Tournament data members.
 *
 * @param in - In file stream.
 * @param id - Uniqe tournament interger id.
 */
void Tournament::readFromFile(ifstream &in, const int & id) {
    this->id = id;
    string allOfLine;
    getline(in, allOfLine);
    int i = 0;
    for (const auto &val : help.splitString('*', allOfLine)) {
        switch (i) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                name = val;
                break;
            case 3:
                startDay = stoi(val);
                break;
            case 4:
                startMonth = stoi(val);
                break;
            case 5:
                startYear = stoi(val);
                break;
            case 6:
                endDay = stoi(val);
                break;
            case 7:
                endMonth = stoi(val);
                break;
            case 8:
                endYear = stoi(val);
                break;
            case 9: {
                totalNumberOfTeams = stoi(val);
                break;
            }
            case 10:
                type = static_cast<tournamentType>(stoi(val));
                break;
            case 11:
                autoConfigure = stoi(val);
                break;

            default:
                cout << "\nWarning, incorrect data stored in tournament "
                        "database!"
                     << '\n';
                break;
        }
        i++;
    }
}

/**
 * @brief Gets name of enum type based on provided input.
 *
 * @param tournamentTypeNumber - enum type value.
 * @return string - name of enum.
 */
string Tournament::getStringFromEnum(const int & tournamentTypeNumber) {
    string typeStrName[] = {"cup", "other"};
    return typeStrName[tournamentTypeNumber];
}

/**
 * @brief Checks if provided number is a even number or not.
 *
 * @param number - Number to be checked.
 * @return true - Number is even.
 * @return false - Nu,ber is not even.
 */
bool Tournament::checkIntForEvenNumber(const int & number) {
    if (number % 2 == 0) return true;
    return false;
}

/**
 * @brief Gets name of tournament.
 *
 * @return string* - Pointer to name string.
 */
string *Tournament::getName() { return &name; }

/**
 * Sets the amount of new matches to be created after x amount of
 * matches are finished.
 *
 * @see Matches::editMatch
 * @see Matches::updateMatchesVectorWithNewMatch
 * @sse HelperFunctions::readChar
 * */
void Tournament::editMatch() {
    char answer = 'Y';
    int finishedMatches = 0;
    int numToMeet;
    do {
        numToMeet = 0;
        finishedMatches = 0;
        int choice = matches.selectMatch(id);
        if (choice != -1) {
            // Edits existing match
            if (matches.allMatches[choice]->editMatch()) {
                for (int i = 0; i < matches.allMatches.size(); i++) {
                    if (matches.allMatches[i]->finished) {
                        finishedMatches++;
                    }
                }
                switch (totalNumberOfTeams) {
                    case 2: {
                        numToMeet = 0;
                        break;
                    }
                    case 4: {
                        if (finishedMatches == 2) numToMeet = 1;
                        break;
                    }
                    case 8: {
                        if (finishedMatches == 4)
                            numToMeet = 2;
                        else if (finishedMatches == 6)
                            numToMeet = 1;
                        break;
                    }
                    case 16: {
                        if (finishedMatches == 8)
                            numToMeet = 4;
                        else if (finishedMatches == 12)
                            numToMeet = 2;
                        else if (finishedMatches == 14)
                            numToMeet = 1;
                        break;
                    }
                }
                matches.updateMatchesVectorWithNewMatch(id, numToMeet,
                                                        autoConfigure);
            }
        }
        cout << "Continue editing match? (Y/n): ";
        answer = help.readChar();
    } while (answer == 'Y');
}
