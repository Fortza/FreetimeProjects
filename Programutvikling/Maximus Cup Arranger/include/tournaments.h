#ifndef __TOURNAMENTS_H
#define __TOURNAMENTS_H

#include "tournament.h"
#include "teams.h"

class Tournaments : public Tournament {
   private:
   Teams teams;
    HelperFunctions help;

   public:
    std::vector<Tournament*> allTournaments;
    Tournaments();
    virtual ~Tournaments();
    void add();
    void clearTournaments();
    void printData();
    void readData();
    void writeToFile();
    void readFromFile();
    void printSpesificTournamentData();
    void printMenu();
    int selectTournament();
    void spesificTournament();
    void editSpesificMatch();
};


#endif // __TOURNAMENTS_H
