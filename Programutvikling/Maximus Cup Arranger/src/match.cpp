#include "match.h"

#include <iomanip>
using namespace std;

/**
 * @brief Construct a new Match:: Match object
 * Constructor.
 */
Match::Match(const int groupId) {
    // ctor
    id = 0;
    grpId = groupId;
    homeTeamName = "TBD";
    abroadTeamName = "TBD";
    homeScore = abroadScore = playTime = day = month = year = startTimeHour =
        startTimeMinute = 0;
    ongoing = finished = false;
}

Match::~Match() {
    // dtor
}

void Match::printData() {
    cout << "\n";
    cout << "\tHome: " << homeTeamName << " - Score: " << homeScore << '\n';
    cout << "\tAway: " << abroadTeamName << " - Score: " << abroadScore << '\n';
    if (ongoing) {
        cout << "\tMatch ongoing.\n";
    } else if (finished) {
        cout << "\tMatch finished.\nLasted: " << playTime << " minutes.\n";
    } else {
        cout << "\tMatch not started yet.";
    }
    cout << "\n";
}

/**
 * @brief Prints rough match info
 */
void Match::printMatch() {
    cout << homeTeamName << " vs " << abroadTeamName << " - ";
    if (ongoing) {
        cout << " ongoing ";
    } else if (finished) {
        cout << "finished ";
    } else {
        cout << "upcoming ";
    }
}

/**
 * @brief Prints playtime for match
 */
void Match::printPlaytime() {
    cout << "Playtime: " << setw(3) << playTime << " minutes ";
}

/**
 * @brief
 * file format
 * <id>
 * <Homename> <abroadTeamName> <homeScore>
 * <abroadScore> <playTime> <day> <month>
 * <year> <startTimeHour> <StartTimeMinute>
 * <ongoing> <finished>
 */
void Match::readFromFile(ifstream &inn) {
    string temp;
    getline(inn, temp);

    int i = 0;
    for (const auto &val : help.splitString('*', temp)) {
        switch (i) {
            case 0:
                homeTeamId = stoi(val);
                break;
            case 1:
                homeTeamName = val;
                break;
            case 2:
                awayTeamId = stoi(val);
                break;
            case 3:
                abroadTeamName = val;
                break;
            case 4:
                homeScore = stoi(val);
                break;
            case 5:
                abroadScore = stoi(val);
                break;
            case 6:
                playTime = stoi(val);
                break;
            case 7:
                day = stoi(val);
                break;
            case 8:
                month = stoi(val);
                break;
            case 9:
                year = stoi(val);
                break;
            case 10:
                startTimeMinute = stoi(val);
                break;
            case 11:
                startTimeMinute = stoi(val);
                break;
            case 12:
                ongoing = stoi(val);
                break;
            case 13:
                finished = stoi(val);
                break;
            default:
                cout << "\nWarning, incorrect data stored in matches database!"
                     << '\n';
                break;
        }
        i++;
    }
    homeTeam = teams.getTeam(homeTeamId);
    awayTeam = teams.getTeam(awayTeamId);
    setWinningTeam();
}
/**
 * @brief
 * file format
 * <id>
 * <Homename> <abroadTeamName> <homeScore>
 * <abroadScore> <playTime> <day> <month>
 * <year> <startTimeHour> <StartTimeMinute>
 * <ongoing> <finished>
 */
void Match::writeToFile(ofstream &out, const int groupId) {
    out << homeTeamId << "*" << homeTeamName << "*" << awayTeamId << "*"
        << abroadTeamName << "*" << homeScore << "*" << abroadScore << "*"
        << playTime << "*" << day << "*" << month << "*" << year << "*"
        << startTimeHour << "*" << startTimeMinute << "*" << ongoing << "*"
        << finished << "*"
        << "\n";
}

/**
 * @brief Reads new match data from user.
 */
void Match::readData(Team *team1, Team *team2) {
    std::string temp;
    int choice;
    // Reads team names.
    do {
        cout << "\nWhich team is home team?\n";
        cout << "1 - " << team1->returnName() << "\n"
             << "2 - " << team2->returnName() << "\n";

        cout << "\tChoose";
        choice = help.readInt(1, 2);
        switch (choice) {
            case (1):
                homeTeamName = team1->returnAbbrv();
                abroadTeamName = team2->returnAbbrv();
                break;
            case (2):
                homeTeamName = team2->returnAbbrv();
                abroadTeamName = team1->returnAbbrv();
                break;
        }

    } while (homeTeamName ==
             abroadTeamName);  // Loops as long as abroadTeamName and HomeName
                               // are the same
    // Reads time started.
    cout << "\nWhen does match start?\n";
    cout << "\tWrite start hour";
    startTimeHour = help.readInt(0, 24);
    cout << "\tWrite start minute";
    startTimeMinute = help.readInt(0, 59);

    homeScore = abroadScore = playTime = 0;
    ongoing = finished = false;
    homeTeam = team1;
    awayTeam = team2;
    homeTeamId = homeTeam->returnTeamId();
    awayTeamId = awayTeam->returnTeamId();
}
/**
 * @brief
 *
 * @param team1
 * @param team2
 */
void Match::readDataRandom(Team *team1, Team *team2) {
    homeTeamName = team1->returnAbbrv();
    abroadTeamName = team2->returnAbbrv();
    cout << "Home team: " << team1->returnName() << "\n";
    cout << "Away team: " << team2->returnName() << "\n";
    // Reads time started.
    cout << "\nWhen does match start?\n";
    cout << "\tStart hour";
    startTimeHour = help.readInt(0, 24);
    cout << "\tStart minute";
    startTimeMinute = help.readInt(0, 59);
    homeScore = abroadScore = playTime = 0;
    ongoing = finished = false;
    homeTeam = team1;
    awayTeam = team2;
    homeTeamId = homeTeam->returnTeamId();
    awayTeamId = awayTeam->returnTeamId();
}

/**
 * @brief Allows user to update scores and status (Upcoming, ongoing, finished)
 *
 * @see Match::printData()
 * @see HelperFunctions::readInt(...)
 */
bool Match::editMatch() {
    int command;
    do {
        do {
            cout << "\n1 - Edit score\n"
                 << "2 - Change match status\n"
                 << "0 - Back to tournament menu\n"
                 << "Command";
            command = help.readInt(0, 2);
            if (command == 1 && !ongoing){
                cout << "\nMatch has not started yet!\n";
            }
        } while (command == 1 && !ongoing);
        printData();
        switch (command) {
            case 0:
                break;
            case 1:
                cout << "Which team to update score ";
                command = help.readInt(1, 2);
                switch (command) {
                    case (1):
                        cout << homeTeamName << " - Score: " << homeScore
                             << '\n'
                             << "Please write new score";
                        homeScore = help.readInt(0, 99);
                        cout << "\nScore has been set to " << homeScore
                             << ".\n";
                        break;
                    case (2):
                        cout << abroadTeamName << " - Score: " << abroadScore
                             << '\n'
                             << "Please write new score";
                        abroadScore = help.readInt(0, 99);
                        cout << "\nScore has been set to " << abroadScore
                             << ".\n";
                        break;
                }
                printData();
                break;
            case 2:
                cout << "\n1 - Match upcoming\n"
                     << "2 - Match ongoing\n"
                     << "3 - Match finished\n";
                cout << "Command";
                command = help.readInt(1, 3);
                cout << "\n";
                if (command == 1) {
                    ongoing = false;
                    finished = false;

                } else if (command == 2) {
                    ongoing = true;
                    finished = false;
                } else if (command == 3 && homeScore > abroadScore ||
                           homeScore < abroadScore) {
                    cout << "\nSet the total match time in minutes";
                    playTime = help.readInt(0, 999);
                    cout << '\n';
                    ongoing = false;
                    finished = true;
                } else {
                    cout << "\nError: You need to set the score first!\n";
                }
                // printData();
                break;
        }
        if (command == 3) {
            setWinningTeam();
            return true;
        }
    } while (command != 0);
    return false;
}

int Match::getId() { return grpId; }

void Match::setWinningTeam() {
    if (homeScore > abroadScore)
        winningTeam = homeTeam;
    else
        winningTeam = awayTeam;
}
