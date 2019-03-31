/*
File: menu.h
Description: This is the menu header file .
Course: 150018 C++ Workshop,
Exercise 2, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#ifndef __MENU_

#define __MENU_

#include<iostream>
#include <iomanip>
#include"mytypes.h"
#include"Rational.h"
#include"Complex.h"
#include"common.h"
using namespace std;

enum MenuOption {
	EXIT_MENU,
	INPUT_NUMBER,
	OUTPT_NUMBERS,
	CALCULATE_ALL_NUMBERS_IN_ARRAY,
	CALCULATE_MULTIPLICATOIN_ALL_NUMBERS_IN_ARRAY,
	CALCULATE_SUM_2NUMBERS_IN_ARRAY,
	CALCULATE__SUBTRACTOIN_2NUMBERS_IN_ARRAY,
	CALCULATE_MULTIPLICATOIN_2NUMBERS_IN_ARRAY,
	SORT_ALL_NUMBERS_IN_ARAAY,
	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = SORT_ALL_NUMBERS_IN_ARAAY,
};

enum SubMenuOption {
	INT = 1,
	FLOAT,
	RATIONAL,
	COMPLEX,
	FIRST_SUBMENU_OPTION = INT,
	LAST_SUBMENU_OPTION = COMPLEX,
};

const int menuIndent = 10;

// These strings will be seen by the user, on the main menu.They
// must be kept consistent with the operations of menu_option
// above.
const char * const menuOptionStrings[] = {
	"exit the program",
	"Input a number into a array of a specific type",
	"Print all numbers in the array of a spesific type",
	"Calculate sum of all the numbers in the array of a specific type",
	"Calculate multiplication of all numbers in the array of a specific type",
	"Calculate sum of two numbers and save the result into a chosen index in the array",
	"Calculate subtraction of two numbers and save the result into a chosen index in the array",
	"Calculate multiplication of two numbers and save the result into a chosen index in the array",
	"sorting an array of a specific type",
};

//These strings will be seen by the user, on the  submenu.They
// must be kept consistent with the operations of submenu_option
const char * const subMenuOptionString[] = {
	"",
	"Int numbers",
	"Float numbers",
	"Rational numbers",
	"Complex numbers",
};
//input
bool inputToInt(int number, int index, int * arr, int length);

bool inputToFloat(float number, int index, float * arr, int length);

bool inputToRational(int numerator, uint denominator, int index, Rational * arr, int length);

bool inputToComplex(float real, float imaginary, int index, Complex * arr, int length);

//output
void outputInt(int *arr, int length);

void outputFloat(float *arr, int length);

void outputInt(int *arr, int length);

void outputRational(Rational* arr, int length);

void outputComplex(Complex* arr, int length);

//array sum
int arrIntSum(int * arr, int length);

float arrFloatSum(float * arr, int length);

Rational arrRationalSum(Rational * arr, int length);

Complex arrComplexSum(Complex *arr, int length);

//array mult
int arrIntMult(int * arr, int length);

float arrFloatMult(float *arr, int length);

Rational arrRationalMult(Rational * arr, int length);

Complex arrComplexMult(Complex * arr, int length);

//add 2 elements
void add2IntElemants(int* arr, const int index1, const int index2, int index3);

void add2FloatElemants(float *arr, const int, const int, int);

void add2RationalElemants(Rational *arr, const int, const int, int);

void add2ComplexElemants(Complex *arr, const int, const int, int);

//sub 2 elemnts
void sub2IntElemants(int* arr, const int, const int, int);

void sub2FloatElemants(float *arr, const int, const int, int);

void sub2RationalElemants(Rational *arr, const int, const int, int);

void sub2ComplexElemants(Complex *arr, const int, const int, int);

//mult 2 elements
void mult2IntElemants(int* arr, const int index1, const int index2, int index3);

void mult2FloatElemants(float *arr, const int index1, const int  index2, int index3);

void mult2RationalElemants(Rational *arr, const int index1, const int  index2, int index3);

void mult2ComplexElemants(Complex *arr, const int index1, const int  index2, int index3);



//operators
MenuOption operator ++(MenuOption & chosen);

SubMenuOption operator ++(SubMenuOption& chosen);

ostream& operator <<(ostream& output, const MenuOption& chosen);

ostream& operator <<(ostream& output, const SubMenuOption &chosen);

istream& operator >>(istream& input, MenuOption &chosen);

istream& operator >>(istream& input, SubMenuOption &chosen);
#endif // !__MENU_

