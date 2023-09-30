#ifndef __CONSTANTS_H
#define __CONSTANTS_H

#include <string>


const int MAXCHAR = 200;                                      ///< Max number of characters in input buffer.
const std::string USERS_FILE_PATH = "users.dta";              ///< File name for user database.
const std::string TOURNAMENTS_FILE_PATH = "tournaments.dta";  ///< File name for tournaments database.
const std::string TEAMS_FILE_PATH = "teams.dta";              ///< File name for teams database.
const int MAX_YEAR = 2100;                                    ///< Max year
const int MIN_YEAR = 1900;                                    ///< Min year
const int MAX_DAY = 31;                                       ///< Max day
const int MIN_DAY = 1;                                        ///< Min day
const int MAX_MONTH = 12;                                     ///< Max month
const int MIN_MONTH = 1;                                      ///< Min month
const int MAX_TEAMS_IN_TOURNAMENT = 16;                       ///< Max number of teams in a tournament.
const int MIN_TEAMS_IN_TOURNAMENT = 2;                        ///< Min number of teams in a tournament.


#endif  // __CONSTANTS_H