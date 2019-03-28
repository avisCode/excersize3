/*
File: line.h
Description: This is the header file of line.cpp
Course: 150018 C++ Workshop,
Exercise 1, Question 1
Author: Avrumi Rosenberg ID:208509653
*/




#ifndef __LINE_H_
#define __LINE_H_

#include"mytypes.h"


const uint MAX_BUSES_IN_LINE = 5;
const uint MAX_LINES = 9;


/*line struct :
	numOfBus :	    holds the number of the bus in the line up to 5 buses in a line.
	licensePlats:	holds the license plates of the buses that was added to the line.
*/
struct Line {
	uint numOfBus = 0;
	uint * licensePlats;
};

//deletes a bus from the line it was assigned to.
void lineDelBus(uint line, uint busId);

//adding the bus to the line it was assigned to.
void lineAddBus(uint line, uint busId);


uint *lineGetBuses(uint line);


#endif // !__LINE_H_
#pragma once
