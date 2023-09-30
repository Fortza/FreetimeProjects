#ifndef __TEAM_H
#define __TEAM_H

#include <fstream>
#include "helperFunctions.h"


class Team {
   private:
    HelperFunctions help;
    int id;                             ///< Team number
    std::string name;                   ///< Name on team
    std::string abbrv;                  ///< Abbreviation of team name
    int numberOfPlayers;                ///< Number of players on team
    int goals;                          ///< Number of goals the team has

   public:
    Team();
    virtual ~Team();
    virtual void printData();
    virtual void readData(const std::string newName, const int number);
    virtual void writeToFile(std::ofstream & out);
    virtual void readFromFile(std::ifstream & in);
    std::string printTeamName();
    int returnTeamId();
    virtual std::string returnName();
    std::string returnAbbrv();
    int returnPlayers();
    int returnGoals();
};


#endif //__TEAM_H
