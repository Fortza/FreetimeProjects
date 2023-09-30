#ifndef __TOURNAMENT_H
#define __TOURNAMENT_H

#include <fstream>   // Fil input/output
#include <iostream>  // cout, cin
#include <list>      // list
#include <string>    // string
#include <vector>    // vector

#include "matches.h"
#include "helperFunctions.h"

enum tournamentType {
    cup,
    other
};

/**
 * @brief Baseclass Tournament, holds relevant 
 * datamembers for a tournament object.
 * 
 */

class Tournament {
   private:
    HelperFunctions help;
    Teams tournamentTeams;

    int id;
    std::string name;
    int startDay;
    int startMonth;
    int startYear;
    int endDay;
    int endMonth;
    int endYear;
    int totalNumberOfTeams;
    int bracketLevel = 0;

   public:
    tournamentType type;
    bool autoConfigure;
    Matches matches;

    Tournament();
    virtual ~Tournament();
    virtual void printData();
    virtual bool readData(const int & id);
    virtual void writeToFile(std::ofstream& out);
    virtual void readFromFile(std::ifstream& in, const int & id);
    std::string getStringFromEnum(const int & tournamentTypeNumber);
    bool checkIntForEvenNumber(const int & number);
    std::string* getName();
    void editMatch();
};


#endif  // __TOURNAMENT_H
