#include <iostream>

#include "LesData2.h"

using namespace std;

void skrivMenyStart();
void skrivMenyTurnering();
void skrivMenyLag();
void skrivAlleTurneringer();
void skrivAlleLag();
void lagNyTurnering();
void visTurnering();
void changeMatch();
void removeMatch();
void displayAllMatches();
void removeTournament();
void editTournament();
void addNewTeam();
void removeTeam();
void changeTeam();
void displayTeam();

int main() {
    char svar;
    do {
        svar = '\0';
        skrivMenyStart();
        svar = lesChar("Command");
        switch (svar) {
            case 'T':
                skrivMenyTurnering();
                svar = lesChar("Command");
                switch (svar) {
                    case 'A':
                        lagNyTurnering();
                        break;
                    case 'D':
                        visTurnering();
                        break;
                    case 'R':
                        removeTournament();
                        break;
                    case 'E':
                        editTournament();
                        break;
                    case 'B':
                        break;
                    default:
                        cout << "\nIllegal input!" << '\n';
                        break;
                }
                break;
            case 'E':
                skrivMenyLag();
                svar = lesChar("Command");
                switch (svar) {
                    case 'A':
                        addNewTeam();
                        break;
                    case 'C':
                        changeTeam();
                        break;
                    case 'R':
                        removeTeam();
                        break;
                    case 'D':
                        displayTeam();
                        break;
                    case 'B':
                        break;
                    default:
                        cout << "\nIllegal input!" << '\n';
                        break;
                }
                break;
            case 'Q':
                break;
            default:
                cout << "\nIllegal input!" << '\n';
                break;
        }
    } while (svar != 'Q');
    return 0;
}

void skrivMenyStart() {
    cout << "\nT - Tournament" << '\n'
         << "E - tEam" << '\n'
         << "Q - Quit" << '\n';
}

void skrivMenyTurnering() {
    skrivAlleTurneringer();
    cout
        << "\nA - Add new tournament" << '\n'
        << "D - Display spesific tournament" << '\n'
        << "R - Remove tournament" << '\n'
        << "E - Edit tournament" << '\n'
        << "B - Back" << '\n';
}

void skrivMenyLag() {
    skrivAlleLag();
    cout
        << "\nA - Add new team" << '\n'
        << "C - Change an existing team" << '\n'
        << "R - Remove team" << '\n'
        << "D - Display spesific team" << '\n'
        << "B - Back" << '\n';
}

void skrivAlleTurneringer() {
    cout << "\nCurrent added tournaments:" << '\n';
    cout
        << "Nr.1 - Tournament x.a" << '\n'
        << "Nr.2 - Tournament x.b" << '\n'
        << "Nr.3 - Tournament x.c" << '\n';
}

void skrivAlleLag() {
    cout << "\nAll teams:" << '\n';
    cout
        << "Nr.1 - Arsenal" << '\n'
        << "Nr.2 - Aston Villa" << '\n'
        << "Nr.3 - Chelsea" << '\n'
        << "Nr.4 - Leicester City" << '\n'
        << "Nr.5 - Manchester United" << '\n'
        << "Nr.6 - Watford" << '\n'
        << "Nr.7 - West Ham United" << '\n'
        << "Nr.8 - Liverpool" << '\n';
}

void lagNyTurnering() {
    char valg;
    int lag;
    string navn = "";
    cout << "\nEnter name: ";
    getline(cin, navn);
    do {
        cout << "\nChoose format:" << '\n'
             << "B - Brackets" << '\n'
             << "R - Round Robin" << '\n';
        valg = lesChar("Command");
    } while (valg != 'B' && valg != 'R');

    skrivAlleLag();
    cout << "\nWhich teams should be added to the tournament?";
    do {
        lag = lesInt("", 1, 8);
        cout << "\nAdd another team? (J/n): ";
        valg = lesChar("Command");
    } while (valg == 'J');

    cout << "\nTournement added" << '\n';
}

void visTurnering() {
    lesInt("\nWhich tournament?", 1, 3);
    cout << "\nTournament x.a" << '\n';
    displayAllMatches();
    cout
        << "\nC - Change match" << '\n'
        //<< "M - update Match" << '\n'
        << "D - Delete match" << '\n'
        // << "H - cHange tournament" << '\n'
        // << "E - dElete tournament" << '\n'
        << "B - Back" << '\n';
    char svar = lesChar("Command");
    switch (svar) {
        case 'C':
            changeMatch();
            break;
        case 'D':
            removeMatch();
            break;
        case 'B':
            break;
        default:
            cout << "\nIllegal input!" << '\n';
            break;
    }
}

void changeMatch() {
    int valg, valg2;
    displayAllMatches();
    cout << "\nChoose match:";
    valg = lesInt("", 1, 3);

    char changeTeam = lesChar("Change teams? (Y/n)");
    if (changeTeam == 'Y') {
        skrivAlleLag();
        cout << "\nChoose team 1: ";
        valg = lesInt("", 1, 8);
        cout << "\nChoose team 2: ";
        valg2 = lesInt("", 1, 8);
    }
    char update = lesChar("Update score? (Y/n)");
    int scoreHome, scoreAway;
    if (update == 'Y') {
        scoreHome = lesInt("Enter score for home team", 0, 99);
        scoreAway = lesInt("Enter score for away team", 0, 99);
    }
    cout << "\nChanges added" << '\n';
}

void removeMatch() {
    displayAllMatches();
    lesInt("\nWhich match do you wish to remove?", 1, 4);
    char valg = lesChar("Confirm (Y/n)");
    if (valg == 'Y') {
        cout << "\nMatch deleted!" << '\n';
    } else
        cout << "\nOperation aborted!!" << '\n';
}

void displayAllMatches() {
    cout << "\nOngoing matches:" << '\n'
         << "Nr.\t\tH\t\t\t\tA\t\t\t\tResult" << '\n'
         << "2\t\t"
         << "Arsenal"
         << "\t\t\t\t"
         << "Chelsea"
         << "\t\t\t\tH: 1\tA: 0" << '\n'
         << "3\t\t"
         << "Leicester City"
         << "\t\t\t"
         << "Liverpool"
         << "\t\t\tH: 0\tA: 1" << '\n'
         << "4\t\t"
         << "West Ham United"
         << "\t\t\t"
         << "Watford"
         << "\t\t\t\tH: 0\tA: 0" << '\n'

         << "\nCompleted matches:" << '\n'
         << "Nr.\t\tH\t\t\t\tA\t\t\t\tResult" << '\n'
         << "1\t\t"
         << "Aston Villa"
         << "\t\t\t"
         << "Manchester United"
         << "\t\t"
         << "H: 2\tA: 0"
         << '\n';
}

void removeTournament() {
    skrivAlleTurneringer();
    lesInt("\nWhich tournament do you wish to remove?", 1, 3);
    char valg = lesChar("Confirm (Y/n)");
    if (valg == 'Y') {
        cout << "\nTournament deleted!" << '\n';
    } else
        cout << "\nOperation aborted!!" << '\n';
}

void editTournament() {
    string name;
    skrivAlleTurneringer();
    lesInt("\nWhich tournament do you wish to edit?", 1, 3);
    char valg;
    do {
        cout << "N - change Name" << '\n'
             << "T - change Teams" << '\n'
             << "B - Back" << '\n';
        valg = lesChar("Command");
        switch (valg) {
            case 'N': {
                cout << "Enter new name: ";
                getline(cin, name);
                break;
            }
            case 'T': {
                skrivAlleLag();
                char tmp = lesChar("A - Add new team\nR - Remove team");
                if (tmp == 'A')
                    lesInt("Enter team number to add", 1, 8);
                else if (tmp == 'R') {
                    lesInt("Enter team number to remove", 1, 8);
                    tmp = lesChar("Confirm deletion (Y/n)");
                    if (tmp == 'Y')
                        cout << "\nDeleted" << '\n';
                    else
                        cout << "\nOperation aborted!!" << '\n';
                }
                break;
            }
            default:
                cout << "\nIllegal input!" << '\n';
                break;
        }
    } while (valg != 'B');
}

void addNewTeam() {
    string name;
    cout << "\nEnter team name: ";
    getline(cin, name);
    cout << "\nTeam added" << '\n';
}

void removeTeam() {
    skrivAlleLag();
    lesInt("\nWhich team do you wish to remove?", 1, 8);
    char valg = lesChar("Confirm (Y/n)");
    if (valg == 'Y') {
        cout << "\nTeam deleted!" << '\n';
    } else
        cout << "\nOperation aborted!" << '\n';
}

void changeTeam() {
    string name;
    skrivAlleLag();
    lesInt("\nWhich team do you wish to change?", 1, 8);
    cout << "\nEnter team name: ";
    getline(cin, name);
    char valg = lesChar("Use new name? (Y/n)");
    if (valg == 'Y') {
        cout << "\nName successfully changed!" << '\n';
    } else
        cout << "\nOperation aborted!" << '\n';
}

void displayTeam() {
    int num = lesInt("\nWhich spesific team do you wish to see?", 1, 8);
    cout << "\nTeam Nr. " << num << " detailed team data here: -----------------" << '\n';
}