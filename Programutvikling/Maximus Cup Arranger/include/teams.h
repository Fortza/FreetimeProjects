#ifndef __TEAMS_H
#define __TEAMS_H

#include "team.h"

/**
 * @brief Subclass Teams, inherits from Team class.
 */
class Teams : public Team {
   private:
    HelperFunctions help;

   public:
    std::vector <Team*> allTeams;      ///< Vector with all teams

    Teams();
    virtual ~Teams();
    void addTeam();
    void clearTeams();
    void printData();
    void writeToFile();
    void readFromFile();
    void printMenu();
    void menu();
    int howManyTeams();     //returns the amount of teams
    void printTeamName();
    int returnTeamId(const int nr);
    void printTeamName(const int id);
    int returnPlaceInVector(const int id);
    Team* getTeam(const int & id);
    std::string returnName(const int nr);


};


#endif //__TEAMS_H
