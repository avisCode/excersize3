/*
File: common.cpp
Description: This is the common cpp file that holds a function that is used to call other functions in the menu .
Course: 150018 C++ Workshop,
Exercise 2, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include"common.h"

//a function that is called to call other functions and anonym functions
void operation(void * result, const void * pramA, const void *pramB, void(*ptrFunc)(void*, const void*, const void*)) {
	(*ptrFunc)(result, pramA, pramB);
}

