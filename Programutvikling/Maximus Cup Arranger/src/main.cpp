#include "tournaments.h"
#include "users.h"

using namespace std;

void printMenu();

int main() {
    Users users;
    HelperFunctions help;
    //Tournaments *tours;
    //Teams *teams;
    int choice;
    while (!users.menu()) {
        if (users.getUser()) {
            do {
                printMenu();
                cout << "\nCommand";
                choice = help.readInt(0, 2);
                switch (choice) {
                    case 0: break;
                    case 1: {
                        auto t = new Tournaments;
                        delete t;
                        break;
                    }
                    case 2: {
                        auto t = new Teams;
                        t->menu();
                        delete t;
                        break;
                    }
                }
            } while (choice != 0);
            users.logOut();
        }
    }

    return 0;
}

void printMenu() {
    cout << "\n..:::Main Menu:::.." << "\n"
         << "1 - Tournament Menu" << '\n'
         << "2 - Teams Menu" << '\n'
         << "0 - Log out";
}