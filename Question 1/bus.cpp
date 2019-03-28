/*
File: bus.cpp
Description: This is the the file with all functoin to  managing a bus fleet
Course: 150018 C++ Workshop,
Exercise 1, Question 1
Author: Avrumi Rosenberg ID:208509653
*/


#include <iostream>
#include <iomanip>
#include "mytypes.h"
#include "bus.h"
#include"line.h"
using namespace std;

void busDtor(Bus *);
void addBus(Bus &);
bool checkBus(uint busId);

// holding all the buses that are in the fleet
Bus **buses = nullptr;
uint busFleetCount = 0;

// no need to this function because we made it in one function for both options
//Bus* busCtor(int busId) {             // 
//	if (0 > busId || busId > MAX_ID)
//		return nullptr;
//	else {
//		Bus *newBus = new Bus;
//		newBus->_busId = busId;
//		newBus->_busLine = 0;
//		newBus->_busSеаts = MAX_SEATS;
//		newBus->_busDriver = nullptr;
//		if (addBus(*newBus) == false) {
//			delete newBus;
//			return nullptr;
//		}
//		return newBus;
//	}
//}

// create a bus with or without a number of seats
Bus* busCtor(int busId, int busSеаts) {       // Create a bus with id and given number of seats  or  Create a bus with id and 50 seats
	if (busId <= 0 || busId > MAX_ID)
		throw numberToString(busId);
	if (busSеаts < 8 || busSеаts > 60)
		throw busSеаts;
	else {
		Bus *newBus = new Bus;
		newBus->_busId = busId;
		newBus->_busLine = 0;
		newBus->_busSеаts = busSеаts;
		newBus->_busDriver = nullptr;
		try {
			addBus(*newBus);
		}
		catch (char * id) {
			busDtor(newBus);
			throw id;
		}
	}
}

//adding the bus to the array / fleet of buses the function is called from function busCtor
void addBus(Bus & newBus) {
	if (busFleetCount > 0 && checkBus(newBus._busId))
		throw numberToString(newBus._busId);
	uint i;
	Bus **temp = new Bus*[busFleetCount + 1];
	for (i = 0; i < busFleetCount && buses[i]->_busId < newBus._busId; ++i)
		temp[i] = buses[i];

	temp[i] = const_cast<Bus*>(&newBus);
	++busFleetCount;
	for (++i; i < busFleetCount; i++)
		temp[i] = buses[i - 1];
	delete[]buses;
	buses = temp;
}

//delete a bus from the array/fleet of buses by taking a case to delete bus from the line if it was assigned to a line
void delBus(uint busId) {
	if (!checkBus(busId))
		throw numberToString(busId);
	uint i;
	Bus **temp = new Bus*[busFleetCount - 1];
	for (i = 0; i < busFleetCount && buses[i]->_busId < busId; i++)
		temp[i] = buses[i];

	if (buses[i]->_busLine == 0) {
		delete[]temp;
		throw numberToString(busId);
	}
	else {
		try{
			lineDelBus(buses[i]->_busLine, buses[i]->_busId);
			busDtor(buses[i]);
		}
		catch (char *id) {
			throw buses[i]->_busLine;
		}
	}
	busFleetCount--;
	for (i; i < busFleetCount; i++)
		temp[i] = buses[i + 1];

	delete[]buses;
	buses = temp;
}

//checking for a bus if exist in the fleet by checking if the license ID excite
bool checkBus(uint busId) {
	if (busFleetCount == 0)
		return false;
	int first = 0, last = busFleetCount - 1, mid = (first + last) / 2;
	while (first <= last) {
		if (busId > buses[mid]->_busId) {
			first = mid + 1;
			mid = (first + last) / 2;
		}
		else if (busId < buses[mid]->_busId) {
			last = mid - 1;
			mid = (first + last) / 2;
		}
		else
			return true;
	}
	return false;
}

//deleting bus information from the memory and in case  there is a driver name in the bus it will  delete it 
void busDtor(Bus *delBus) {
	if (delBus->_busDriver != nullptr)
		delete[] delBus->_busDriver;
	delete[] delBus;
}

//adding and changing a line to a bus an bus to a line(line struct) by checking if it can be added to the line
void busLine(Bus & newBus, int busLine) {		// Getter - Return line number assigned to the bus	
	if (busLine < 0 || busLine > 9 || &newBus == nullptr)
		throw busLine;
	if (busLine != 0) {
		if (newBus._busLine == 0) {
			try {
				lineAddBus(busLine, newBus._busId);
				newBus._busLine = busLine;
			}
			catch (char * line) {
				throw line;
			}
			catch (int i) {
				newBus._busLine = 0;
				throw i;
			}
		}
		else {
			try {
				lineDelBus(newBus._busLine, newBus._busId);
			}
			catch (char * id) {
				throw id;
			}
			try {
				lineAddBus(busLine, newBus._busId);
				newBus._busLine = busLine;
			}
			catch (char * line) {
				throw line;
			}
			catch (int i) {
				throw i;
			}
		}
	}
	else {
		try {
			lineDelBus(newBus._busLine, newBus._busId);
			newBus._busLine = 0;
		}
		catch (char * id) {
			throw id;
		}
	}
}

//checking if a bus exists in the array / fleet of buses and returning the line from the bus
int busLine(const Bus&newBus) {		 // if the line number is 0  
	if (checkBus(newBus._busId))
		return newBus._busLine;
	else
		return false;
}

//adding  or changeing a drivers name to a bus
void busDriver(Bus &bus, const cstring nameDriver) {		// Setter - Assign (set) the driver name for a bus (returns false if the name is nullptr)
	if (nameDriver == nullptr || strlen(nameDriver) == 0)
		throw nullptr;
	else {
		delete[]bus._busDriver;
		bus._busDriver = nameDriver;
		throw 1;
	}
}

//giveing back the drivers name 
cstring busDriver(const Bus &bus) {			// Getter - Return a string with a copy of bus's driver name
	return bus._busDriver;
}

//prints the bus information
void busPrint(const Bus &bus) {		// Prints information about the buses
	cout << "license plate: " << bus._busId << endl;
	cout << "line number: " << bus._busLine << endl;
	cout << "number of seats: " << bus._busSеаts << endl;
	if (bus._busDriver != nullptr)
		cout << "name of driver: " << bus._busDriver << endl;
}

// deletes all the buses  information from the fleet
void busFleetDtor() {
	for (uint i = 0; i < busFleetCount; ++i) {
		lineDelBus(buses[i]->_busLine, buses[i]->_busId);
		busDtor(buses[i]);
	}
	delete[]buses;
}

//creating and returning a dynamic array with all license plates in the fleet 
uint* getBusList() {
	if (!busFleetCount)
		return nullptr;
	uint * allBusIds = new uint[busFleetCount];
	for (uint i = 0; i < busFleetCount; i++)
		allBusIds[i] = buses[i]->_busId;
	return allBusIds;
}

//checking if the license plate exists in buses and returning the address on the bus
Bus* getBus(int busId) {
	if (!checkBus(busId))
		return nullptr;
	for (uint i = 0; i < busFleetCount; i++)
		if (buses[i]->_busId == busId)
			return buses[i];
	return nullptr;
}


