/*
File: menu.cpp
Description: This is the menu cpp file that holds all the function for the menu   .
Course: 150018 C++ Workshop,
Exercise 2, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include"menu.h"
//This is the menu cpp file that holds all the function for the menu 

// all the functions for input a value to an array for all kind types 
#pragma region inputs

bool inputToInt(int number, int index, int * arr, int length) {
	if (index >= length)
		return false;
	arr[index] = number;
	return true;
}

bool inputToFloat(float number, int index, float * arr, int length) {
	if (index >= length)
		return false;
	arr[index] = number;
	return true;
}

bool inputToRational(int numerator, uint denominator, int index, Rational * arr, int length) {
	if (index >= length)
		return false;
	arr[index] = rationalCtor(numerator, denominator);
	return true;
}

bool inputToComplex(float real, float imaginary, int index, Complex * arr, int length) {
	if (index >= length)
		return false;
	arr[index] = complexCtor(real, imaginary);
	return true;
}

#pragma endregion

// all the functions  for outputs the values from an array for all kind types 
#pragma region outputs

void outputInt(int *arr, int length) {
	for (int i = 0; i < length; i++)
		cout << "in index " << i << " is stored value: " << arr[i] << endl;
}

void outputFloat(float *arr, int length) {
	for (int i = 0; i < length; i++)
		cout << "in index " << i << " is stored value: " << arr[i] << endl;
}

void outputRational(Rational* arr, int length) {
	for (int i = 0; i < length; i++)
		cout << "in index " << i << " is stored value: " << arr[i] << endl;
}

void outputComplex(Complex* arr, int length) {
	for (int i = 0; i < length; i++)
		cout << "in index " << i << " is stored value: " << arr[i] << endl;
}

#pragma endregion

// all the functions that calculate the sum of the all array elements for all kind types .
#pragma region sum

int arrIntSum(int * arr, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return sum;
}

float arrFloatSum(float * arr, int length) {
	float sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return sum;
}

Rational arrRationalSum(Rational * arr, int length) {
	Rational sum = arr[0];
	for (int i = 1; i < length; i++)
		sum = sum + arr[i];
	return sum;
}

Complex arrComplexSum(Complex *arr, int length) {
	Complex sum = arr[0];
	for (int i = 1; i < length; i++)
		sum = sum + arr[i];
	return sum;
}
#pragma endregion

//// all the functions that calculate the multiplication of the all array elements for all kind types .
#pragma region mult

int arrIntMult(int * arr, int length) {
	int sum = 1;
	for (int i = 0; i < length; i++)
		sum *= arr[i];
	return sum;
}

float arrFloatMult(float *arr, int length) {
	float sum = 1;
	for (int i = 0; i < length; i++)
		sum *= arr[i];
	return sum;
}

Rational arrRationalMult(Rational * arr, int length) {
	Rational sum = arr[0];
	for (int i = 1; i < length; i++)
		sum = sum * arr[i];
	return sum;
}

Complex arrComplexMult(Complex * arr, int length) {
	Complex sum = { 1,1 };
	for (int i = 0; i < length; i++)
		sum = sum * arr[i];
	return sum;
}
#pragma endregion

//all the functions that calculate the sum of 2  elements in a array  for all kind types .
#pragma region add 2 elements

void add2IntElemants(int* arr, const int index1, const int index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], [](void*result, const void * vIndex1, const void * vIndex2)
	{(*(int*)result) = (*(int*)vIndex1) + (*(int*)vIndex2); });
}

void add2FloatElemants(float *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], [](void*result, const void * vIndex1, const void * vIndex2)
	{(*(float*)result) = (*(float*)vIndex1) + (*(float*)vIndex2); });
}

void add2RationalElemants(Rational *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], addRational);
}

void add2ComplexElemants(Complex *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], addComplex);
}

#pragma endregion

//all the functions that calculate the subtraction of 2  elements in a array  for all kind types .
#pragma region sub 2 elements

void sub2IntElemants(int* arr, const int index1, const int index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], [](void*result, const void * vIndex1, const void * vIndex2)
	{(*(int*)result) = (*(int*)vIndex1) - (*(int*)vIndex2); });
}

void sub2FloatElemants(float *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], [](void*result, const void * vIndex1, const void * vIndex2)
	{(*(float*)result) = (*(float*)vIndex1) - (*(float*)vIndex2); });
}

void sub2RationalElemants(Rational *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], subRational);
}

void sub2ComplexElemants(Complex *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], subComplex);
}

#pragma endregion

//all the functions that calculate the multiplication of 2  elements in a array  for all kind types .
#pragma region mult 2 elements

void mult2IntElemants(int* arr, const int index1, const int index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], [](void*result, const void * vIndex1, const void * vIndex2)
	{(*(int*)result) = (*(int*)vIndex1) * (*(int*)vIndex2); });
}

void mult2FloatElemants(float *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], [](void*result, const void * vIndex1, const void * vIndex2)
	{(*(float*)result) = (*(float*)vIndex1) * (*(float*)vIndex2); });
}

void mult2RationalElemants(Rational *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], multRational);
}

void mult2ComplexElemants(Complex *arr, const int index1, const int  index2, int index3) {
	operation(&arr[index3], &arr[index1], &arr[index2], multComplex);
}
#pragma endregion

//all the operators for the menu and for the submenu
#pragma region operators

MenuOption operator ++(MenuOption& chosen) {
	return chosen = (MenuOption)((int)chosen + 1);
}

SubMenuOption operator ++(SubMenuOption& chosen) {
	return chosen = (SubMenuOption)((int)chosen + 1);
}

ostream& operator <<(ostream& output, const MenuOption &chosen) {
	output << setw(menuIndent) << " " << setw(2) << (int)chosen << " -- " << menuOptionStrings[chosen];
	return output;
}

ostream& operator <<(ostream& output, const SubMenuOption &chosen) {
	output << setw(menuIndent) << " " << setw(2) << (int)chosen << " -- " << subMenuOptionString[chosen];
	return output;
}

istream& operator >>(istream& input, MenuOption &chosen) {
	float tmp;
	if (input >> tmp)
		chosen = static_cast<MenuOption>((int)(tmp));
	return input;
}

istream& operator >>(istream& input, SubMenuOption &chosen) {
	float tmp;
	if (input >> tmp)
		chosen = static_cast<SubMenuOption>((int)(tmp));
	return input;
}

#pragma endregion


