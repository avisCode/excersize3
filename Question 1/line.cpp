/*
File: line.cpp
Description: This is the  file with all functoin to  managing a lines of the bus fleet
Course: 150018 C++ Workshop,
Exercise 1, Question 1
Author: Avrumi Rosenberg ID:208509653
*/

#include "line.h"

//array of all the lines 
Line lineArr[MAX_LINES];

//adding a bus to a line if there is place in the line 
void lineAddBus(uint line, uint busId) {
	if (lineArr[line - 1].numOfBus == MAX_BUSES_IN_LINE)
		throw MAX_BUSES_IN_LINE;
	uint *temp = new uint[lineArr[line - 1].numOfBus + 1], i;
	for (i = 0; i < lineArr[line - 1].numOfBus && lineArr[line - 1].licensePlats[i] <= busId; i++) {
		if (lineArr[line - 1].licensePlats[i] == busId) {
			delete[]temp;
			throw numberToString(busId);
		}
		else
			temp[i] = lineArr[line - 1].licensePlats[i];
	}
	temp[i] = busId;
	lineArr[line - 1].numOfBus++;
	for (++i; i < lineArr[line - 1].numOfBus; i++) {
		temp[i] = lineArr[line - 1].licensePlats[i - 1];
	}
	delete[]lineArr[line - 1].licensePlats;
	lineArr[line - 1].licensePlats = temp;
}

//deleting a bus from a line (handling case of deleting the last line in the array it should not be a dangling pointer)
void lineDelBus(uint line, uint busId) {
	if (!lineArr[line - 1].numOfBus)
		throw numberToString(busId);
	bool flag = false;
	uint i;
	for (i = 0; i < lineArr[line - 1].numOfBus; i++) {
		if (lineArr[line - 1].licensePlats[i] == busId) {
			flag = true;
			break;
		}
	}
	if (!flag)
		throw numberToString(busId);
	else if (lineArr[line - 1].numOfBus == 1) {
		delete[] lineArr[line - 1].licensePlats;
		lineArr[line - 1].licensePlats = nullptr;
		lineArr[line - 1].numOfBus--;
		return;
	}
	uint *temp = new uint[lineArr[line - 1].numOfBus - 1];
	for (i = 0; i < lineArr[line - 1].numOfBus - 1; i++)
		if (lineArr[line - 1].licensePlats[i] == busId)
			break;
		else
			temp[i] = lineArr[line - 1].licensePlats[i];
	--lineArr[line - 1].numOfBus;
	for (i; i < lineArr[line - 1].numOfBus; ++i)
		temp[i] = lineArr[line - 1].licensePlats[i + 1];

	delete[] lineArr[line - 1].licensePlats;
	lineArr[line - 1].licensePlats = temp;
}

//returns all license plates in the line 
uint *lineGetBuses(uint line) {
	return lineArr[line - 1].licensePlats;
}