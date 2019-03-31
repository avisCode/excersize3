/*
File: common.h
Description : This is the common header file .
Course : 150018 C++ Workshop,
Exercise 2, Question 1
Author : Avrumi Rosenberg ID : 208509653 == zevi abramovich id 313583460
*/

#ifndef __COMMON_
#define __COMMON_
#include"mytypes.h"

void operation(void * result, const void * pramA, const void* pramB, void(*ptrFunc)(void*, const void*, const void*));

#endif // !__COMMON_
