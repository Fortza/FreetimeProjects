#include "matches.h"
using namespace std;

/**
 * Constructor for matches, creates a new Matches object.
 * */
Matches::Matches(){
}

Matches::Matches(const int grpId)
{
    groupId = grpId;
}
/**
 * Destructor for matches object.
 * */
Matches::~Matches() {
}

/**
 * @brief Creates a new match for teams sent in.
 *
 * @param team1 - Team in match
 * @param team2 - Team in match
 * @see Match::ReadData(...)
 */
void Matches::addMatch(Team * team1, Team * team2){
    Match *newMatch;
    newMatch = new Match(groupId);
    newMatch->readData(team1, team2);
    allMatches.push_back(newMatch);
}

void Matches::addRandomMatch(Team * team1, Team * team2){
    Match *newMatch;
    newMatch = new Match(groupId);
    newMatch->readDataRandom(team1, team2);
    allMatches.push_back(newMatch);
}

/**
 * Clears the allMatches vector.
 * */
void Matches::clearMatcher()
{
    for (Match *&match : allMatches)
    {
        delete match;
    }
    allMatches.clear();
}

/**
 * @brief
 * Prints data for all matches
 *
 * @param teams - Number of teams in the tournament
 * @see Match::printMatch(...)
 */
void Matches::printData(const int teams)
{
    int matchCounter = 0;
    switch(teams) {
        case(16):
            for (int i = 0; i < 2; i++) {
                cout << " -----------------------  ----------------------- "
                     << " -----------------------  -----------------------\n";
                for (int j = 0; j < 4; j++) {
                    cout << "| ";
                    printMatch(matchCounter);
                    matchCounter++;
                    cout << "|";
                }
                cout << "\n";
                matchCounter -= 4;
                for (int j = 0; j < 4; j++) {
                    cout << "| ";
                    printPlaytime(matchCounter);
                    matchCounter++;
                    cout << "|";
                }
                cout << "\n";
                cout << " -----------------------  ----------------------- "
                     << " -----------------------  -----------------------\n";
            }
            cout << "\n";
        case(8):
            for (int i = 0; i < 2; i++) {
                cout << " -----------------------  -----------------------\n";
                for (int j = 0; j < 2; j++) {
                    cout << "| ";
                    printMatch(matchCounter);
                    matchCounter++;
                    cout << "|";
                }
                cout << "\n";
                matchCounter -= 2;
                for (int j = 0; j < 2; j++) {
                    cout << "| ";
                    printPlaytime(matchCounter);
                    matchCounter++;
                    cout << "|";
                }
                cout << "\n";
                cout << " -----------------------  -----------------------\n";
            }
            cout << "\n";
        case(4):
            cout << " -----------------------  -----------------------\n";
            for (int j = 0; j < 2; j++) {
                cout << "| ";
                printMatch(matchCounter);
                matchCounter++;
                cout << "|";
            }
            cout << "\n";
            matchCounter -= 2;
            for (int j = 0; j < 2; j++) {
                cout << "| ";
                printPlaytime(matchCounter);
                matchCounter++;
                cout << "|";
            }
            cout << "\n -----------------------  -----------------------\n\n";
        case(2):
            cout << " -----------------------\n";
            cout << "| ";
            printMatch(matchCounter);
            cout << "|\n| ";
            printPlaytime(matchCounter);
            cout << "|\n";
            cout << " -----------------------\n";
    }
}

/**
 * @brief Prints match if it is set up.
 *        If not prints "TBD".
 *
 * @param match
 */
void Matches::printMatch(const int match) {
    if (match < allMatches.size()) {
        allMatches[match]->printMatch();
    } else {
        cout << "      Match TBD       ";
    }
}

void Matches::printPlaytime(const int match) {
    if (match < allMatches.size()) {
        allMatches[match]->printPlaytime();
    } else {
        cout << string(22, ' ');
    }
}

/**
 * @brief
 *  write too file.
 * @param out
 */
void Matches::writeToFile(ofstream & out) {
    //ofstream out(MATCHES_FILE_PATH);
    out << allMatches.size() << "\n";
    for (int i = 0; i < allMatches.size(); i++)
    {
        allMatches[i]->writeToFile(out, groupId);
    }
}

void Matches::readFromFile(ifstream &inn) {
    string tmp;
    getline(inn, tmp);
    for (int i = 0; i < stoi(tmp); i++) {
        allMatches.push_back(new Match(groupId));
        allMatches.back()->readFromFile(inn);
    }
}

void Matches::printUpcomming()
{
    for (int i = 0; i < allMatches.size(); i++)
    {
        if (allMatches[i]->ongoing == false && allMatches[i]->finished == false)
        {
            allMatches[i]->printMatch();
        }
    }
}

/**
 * @brief
 *  Prints all finished matches
 */
void Matches::printFinished()
{
    for (int i = 0; i < allMatches.size(); i++)
    {
        if (allMatches[i]->finished == true)
        {
            allMatches[i]->printMatch();
        }
    }
}

/**
 * @brief
 * Prints all ongoing matches
 */
void Matches::printOngoing()
{
    for (int i = 0; i < allMatches.size(); i++)
    {
        if (allMatches[i]->ongoing == true)
        {
            allMatches[i]->printMatch();
        }
    }
}

/**
 * Prints all matches to console and ask user to select one of them.
 *
 * @param id - The rournamnet's unique id number
 *
 * @returns - -1 if error otherwise the match's vector pos.
 * */
int Matches::selectMatch(const int & id) {
    int i = 1;
    for (const auto & val : allMatches) {
            std::cout << "Match number: " << i;
            val->printData();
            cout << '\n';
            i++;
    }
    cout << "\tSelect match";
    if (allMatches.size() <= 0) {
        cout << "Warning: No matches found!" << '\n';
        return -1;
    }
    return help.readInt(1, allMatches.size()) -1;
}

/**
 * Adds X amount of matches to the allMatches vector
 * based on the numOfMatches parameter.
 *
 * @param id - Unique tournament id.
 * @param numOfMatches - number of new matches to create.
 *
 * @see addMatch()
 * */
void Matches::updateMatchesVectorWithNewMatch(const int & id, const int & numOfMatches, const bool rnd) {
    for (int i = 0; i < numOfMatches; i++) {
        cout << "\n\nPlease configure new match.\n";
        if (rnd){
            addRandomMatch(allMatches[prevVecPos]->winningTeam, allMatches[prevVecPos+1]->winningTeam);
        }else if (!rnd){
            addMatch(allMatches[prevVecPos]->winningTeam, allMatches[prevVecPos+1]->winningTeam);
        }
        prevVecPos+=2;
    }

    for (const auto & val : allMatches) {
        cout << "\n";
        val->printMatch();
        cout << "\n";
    }

}