#include <iostream>			//Input output
#include <vector>			//Vector
#include <string>			//String
//#include <random>			//Randomize for contest/tournament
#include "LesData2.h"
using namespace std;


class Contendor{		///< Team Contendors info
	private: 
		string name;
		int age;
	public:
		void writeData() const;
		void readData();
};


class Team {			///< Team info
	private:
		int numMembers;					//Number of team members (contendors)
		string teamName;				//Team name
		vector <Contendor*> Contendors;	//All teamMembers/contendors
	public:
		void writeData() const;						//Writes data
		void readData();							//Reads data
};
	
	void writeMeny();		// Writes switch meny
	void newTeam();			// Adds new team
	void writeTeams();		// Outputs all teams info

	vector <Team*> gTeams;	//All teams (with contendors) stored in vector


int main () {

	char command;			//Temp variable;
	
	writeMeny();			// Writes meny
	command = lesChar("Which command?");	//Reads command choice

	while (command != 'Q') {
		switch (command) {
			case 'A': writeTeams();	break;
			case 'N': newTeam()	;	break;
			default: writeMeny();
		}
		writeMeny();
		command = lesChar("Which command?");
	}


	cout << "\n\nKapasitet:" << gTeams.size();

	return 0;
}
//-----------------------------------------------------------------------------------------------
//									CLASS FUNCTIONS DEFINITION
//-----------------------------------------------------------------------------------------------

/**
 *	Reads data about team
 *	@Look Contendor::readData
 */
void Team::readData(){
	string tempName;		//temp variable
	
	numMembers = lesInt("Number Of Members", 0, 25);	//reads number of members
	cout << "Write team name:"; getline (cin,teamName);	//Tean name

	for (int i = 0; i < numMembers; i++) {				//Read names for every team member
		Contendor* c; c = new Contendor;
		c->readData();
		Contendors.push_back(c);
	}
}


/**
 *	writes output on a team
 *	@Look Contendor::writeData
 */ 
void Team::writeData() const{	
	cout << "\n\n\tTeam Name: " << teamName << "\n";		// outputs Team name
	cout << "\tNumber of team members: " << numMembers << "\n";	// Outputs number of team members
	
	for (int i = 0; i < Contendors.size(); i++) {			// Outputs names of every member
		cout << "\tTeam Member Nr" << i+1 << "\t";
		Contendors[i]->writeData();
	}
}


/**
 *	reads data about contendors
 */
void Contendor::readData() {
	cout << "Participant names: "; getline(cin, name);
	age = lesInt("Participants age", 6, 100);
}


/**
 *	writes output on contendors
 */
void Contendor::writeData() const{
	cout << "\tContendor name: " << name;
	cout << "\tContendor age: " << age << "\n";
}

//-----------------------------------------------------------------------------------------------
//									OTHER FUNCTIONS DEFINITION
//-----------------------------------------------------------------------------------------------


/**
 * Makes new team
 * @Look Team::readData();
 */
void newTeam() {
	Team* t; t = new Team;
	t->readData();
	gTeams.push_back(t);
}


/**
 * Writes all info of teams
 * @Look Team::WriteData();
 */
void writeTeams() {
	for (int i = 0; i < gTeams.size(); i++) {
		gTeams[i]->writeData();
	}
}


/**
 * Writes switch meny
 */
void writeMeny (){
	cout << "\n These commands can be used:\n"
		 << "\tN - Add New Team\n"
		 << "\tA - Write All Teams Information\n";
}
