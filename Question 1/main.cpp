/*
File: main.cpp
Description: This is the test program (main) for managing a bus fleet
Course: 150018 C++ Workshop,
Exercise 1, Question 1
Author: Avrumi Rosenberg ID:208509653
*/

#include <iostream>
#include <iomanip>
#include "bus.h"
#include "line.h" 

using namespace std;

// These are all of the main menu options.  Note that the numbers:
// 0, 1, 2, etc., show up /nowhere/ in the code, even though the
// user will see them on the screen, and will input them for
// choosing a menu option.
// Add your menu options according the the exercise requirements
enum MenuOption {
	EXIT_MENU,
	CREATE_BUS_50_SITS,
	CREATE_BUS_N_SITS,
	ASSIGN_LINE_TO_BUS,
	REMOVE_LINE_FROM_BUS,
	REMOVE_BUS,
	ADD_NAME_TO_BUS,
	SHOW_BUS_LINE,
	SHOW_LINE,
	SHOW_BUS,
	SHOW_ALL_BUSES,
	SHOW_NUM_BUS_IN_FLEET,
	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = SHOW_NUM_BUS_IN_FLEET,
};

// These strings will be seen by the user, on the main menu.  They
// must be kept consistent with the operations of menu_option
// above.
const char * const menuOptionStrings[] = {
	"exit the program",
	"create a bus without a nubmer of seats",
	"create a bus  a with number of seats ",
	"assign line to a bus",
	"remove line from a bus",
	"remove a bus from the fleet",
	"add or change a driver name to a bus",
	"show the line of the bus",
	"show line bus list",
	"show a bus information",
	"show all the the buses in the fleet",
	"show the number of the buses in the fleet",
};

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void) {
	MenuOption chosen;

	// Everything happens inside of this do-while loop, until the user
	//     has decided to exit (or an error occurs).
	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;

		// The user will see:
		//
		//           0 -- exit
		//           1 -- set dollars to shekkels conversion rate
		//           2 -- input an account
		// etc.
		//
		// The casts are for doing the "++" as an int type since
		// they are not allowed as a MenuOption type.
		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;
			chosen = (MenuOption)((int)chosen + 1)) {
			cout << setw(menuIndent) << " " << setw(2) << chosen << " -- ";
			cout << menuOptionStrings[chosen] << endl;
		}
		cout << endl;
		float chosenInt;
		int  busId, busSeats, lineNum;
		Bus *result = nullptr;
		cstring nameDriver = new char[80];
		char * temp = nullptr;
		bool flag = false;
		cout << "Please choose a menu option: ";
		cin >> chosenInt;
		// After the user has input an int, it is cast to a
		//   MenuOption variable.
		chosen = (MenuOption)((int)chosenInt);

		// additional preparations if needed
		// ...

		// Note how the individual cases, match nicely to the
		//     operations they will perform.
		switch (chosen) {
		case EXIT_MENU:
			busFleetDtor();
			cout << "Thanx for using Bus Fleet Management Program!" << endl;
			break;
		case CREATE_BUS_50_SITS:
			cout << "bus license plate: ";
			cin >> busId;
			try {
				busCtor(busId);
				cout << "Crated Successfully\n";
			}
			catch (char * id) {
				cout << "bus was not crated: id " << id << " not legal\n";
				delete[] id;
			}
			break;
		case CREATE_BUS_N_SITS:
			cout << "bus license plate: ";
			cin >> busId;
			cout << "number of seats: ";
			cin >> busSeats;
			try {
				busCtor(busId, busSeats);
				cout << "Crated Successfully\n";
			}
			catch (char * id) {
				cout << "bus was not crated: id " << id << " not legal\n";
				delete[] id;
			}
			catch (int i) {
				cout << "bus was not crated: " << i << " seats is not legal\n";
			}
			break;
		case ASSIGN_LINE_TO_BUS:
			cout << "enter bus licens plate : ";
			cin >> busId;
			try {
				getBus(busId);
				cout << "enter the line: ";
				cin >> lineNum;
				try {
					busLine(*getBus(busId), lineNum);
					cout << "teh bus was add to the line Successfully\n";
					busPrint(*getBus(busId));
				}
				catch (char * line) {
					cout << "The bus is already in line: " << line << endl;
				}
				catch (int i) {
					if (i == 5)
						cout << "there is no place in line number: " << lineNum << endl;
					else
						cout << "line number is illegal\n";
				}
			}
			catch (char *id) {
				cout << "bus " << id << " doesn't exist\n";
			}
			break;
		case REMOVE_LINE_FROM_BUS:
			cout << "enter bus licens plate : ";
			cin >> busId;
			try {
				getBus(busId);
				try {
					if (!getBus(busId)->_busLine)
						throw getBus(busId)->_busLine;
					busLine(*getBus(busId));
					cout << "teh bus was removed from the line Successfully\n";
					busPrint(*getBus(busId));
				}
				catch (char * id) {
					cout << "The bus does not exist in line number: " << id << endl;
				}
				catch (uint line) {
					cout << "ERROR cannot remove a bus with line: " << line << endl;
				}
			}
			catch (char *id) {
				cout << "bus " << id << " doesn't exist\n";
			}
			break;
		case REMOVE_BUS:
			cout << "enter bus licens plate : ";
			cin >> busId;
			try {
				getBus(busId);
				try {
					delBus(busId);
					cout << "the bus was removed Successfully\n";
				}
				catch (char *id) {
					cout << "ERROR cannot remove a bus without a line number \n";
				}
				catch (int i) {
					cout << "failed to delete the bus " << busId << " from the line: " << i << endl;
				}
			}
			catch (char *id) {
				cout << "bus " << id << " doesn't exist\n";
			}
			break;
		case ADD_NAME_TO_BUS: {
			cout << "bus license plate: ";
			cin >> busId;
			try {
				getBus(busId);
				cout << "enter drivers name: ";
				cstring nameDriver = new char[80];
				cin.getline(nameDriver, 80);
				cin.getline(nameDriver, 80);
				while (!flag) {
					try {
						busDriver(*getBus(busId), nameDriver);
						cout << "driver was added Successfully\n";
						busPrint(*getBus(busId));
						flag = true;
					}
					catch (...) {
						cout << "the bus must have a name please enter again :";
						cin.getline(nameDriver, 80);
						flag = false;
					}
				}
			}
			catch (char *id) {
				cout << "bus " << id << " doesn't exist\n";
			}
			break;
		}
		case SHOW_BUS_LINE:
			cout << "enter bus licens plate : ";
			cin >> busId;
			try {
				getBus(busId);
				cout << "the line of the bus is: " << getBus(busId)->_busLine << endl;
			}
			catch (char *id) {
				cout << "bus " << id << " doesn't exist\n";
			}
			break;
		case SHOW_LINE:
			cout << "enter the line number: ";
			cin >> lineNum;
			if (lineGetBuses(lineNum) != nullptr) {
				uint i = 0;
				cout << "\n""the licens plate of buses assigned to the line number: " << lineNum << endl;
				while (i < 5 && getBus(lineGetBuses(lineNum)[i]) != nullptr) {
					cout << (lineGetBuses(lineNum))[i++] << endl;
				}
			}
			else
				cout << "there is no buses assigned to line number " << lineNum << endl;
			break;
		case SHOW_BUS:
			cout << "enter bus licens plate : ";
			cin >> busId;
			if (getBus(busId) != nullptr)
				busPrint(*getBus(busId));
			else
				cout << "bus doesn't exist\n";
			break;
		case SHOW_ALL_BUSES: {
			uint *result = getBusList();
			if (result != nullptr) {
				for (uint i = 0; i < busFleetCount; i++) {
					cout << endl;
					busPrint(*getBus(result[i]));
				}
				delete[] result;
			}
			else
				cout << "\n""there is no buses in the fleet\n";
			break;
		}
		case SHOW_NUM_BUS_IN_FLEET:
			cout << "there is " << busFleetCount << "  buses in the fleet\n";
			break;
		default:
			cout << "ERORR\n";
			break;
		}
	} while (chosen != EXIT_MENU);

	// Do not forget here to request destroying all the data and freeing all the memory
	system("pause");
	return 0;
}
