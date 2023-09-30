#ifndef __MATCHES_H
#define __MATCHES_H

#include <vector>
#include "match.h"
#include <fstream>
#include <iostream>
#include <cstdlib>   // atoi, atof


class Matches {
    private:
    int groupId;
    HelperFunctions help;
    int prevVecPos = 0;

   public:
    std::vector <Match*> allMatches;  ///< Vector with all matches
    //std::vector<pair<Match*, int>> stupid;

    Matches();
    Matches(const int grpId);
    ~Matches();
    void addMatch(Team * team1, Team * team2);
    void addRandomMatch(Team * team1, Team * team2);
    void clearMatcher();
    void printData(const int teams);
    void printMatch(const int match);
    void printPlaytime(const int match);
    void writeToFile(std::ofstream & out);
    void readFromFile(std::ifstream & inn);
    void printUpcomming();
    void printFinished();
    void printOngoing();
    int selectMatch(const int & id);
    void updateMatchesVectorWithNewMatch(const int & id, const int & numOfMatches, const bool rnd);
};


#endif //__MATCHES_H
