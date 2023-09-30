#ifndef __MATCH_H
#define __MATCH_H

#include <fstream>
#include <string>
#include "helperFunctions.h"
#include "teams.h"

/**
 * Main class for matches which keeps
 * track of a single match
 */
class Match
{
   private:
    Teams teams;
    HelperFunctions help;
    int id;                                 ///< Match number
    int grpId = 0;                              ///< Group Id
    std::string homeTeamName;               ///< Name on home team
    std::string abroadTeamName;             ///< Name on away team
    int homeScore;                          ///< Goal tracker for home team
    int abroadScore;                        ///< Goal tracker for away team
    int playTime;                           ///< How long the match lasted
    int day, month, year;                   ///< Date of match
    int startTimeHour, startTimeMinute;     ///< What time the match started
    Team *homeTeam;
    Team *awayTeam;
    int homeTeamId;
    int awayTeamId;

   public:
    bool ongoing;           ///< Says if a match is going on or not
    bool finished;          ///< Says if a match in finished or not
    Team *winningTeam;
    //Team awayTeam;


    Match(const int groupId);
    virtual ~Match();
    virtual void printData();
    void printMatch();
    void printPlaytime();
    virtual void readFromFile(std::ifstream & inn);
    virtual void writeToFile(std::ofstream & out, const int groupId);
    virtual void readData(Team * team1, Team * team2);
    void readDataRandom(Team * team1, Team * team2);
    bool editMatch();
    int getId();
    void setWinningTeam();
};

#endif // __MATCH_H
