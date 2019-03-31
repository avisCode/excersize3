/*
File: Complex.cpp
Description: This is the Complex cpp file with .
Course: 150018 C++ Workshop,
Exercise 2, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include"Complex.h"

// Creating a Complex 
Complex & complexCtor(float real, float imaginary) {
	Complex  tempComplex;
	tempComplex.real = real;
	tempComplex.imaginary = imaginary;
	return tempComplex;
}

// Creating a Complex form a rational  
Complex & complexCtor(Rational & rational, float imaginary ) {
	Complex  tempComplex;
	tempComplex.real = (float)(rational.numerator/rational.denominator);
	tempComplex.imaginary = imaginary;
	return tempComplex;
}

//Function that returns the absolute value of a complex element
float abs(const Complex &tempComplex) {
	return sqrt((tempComplex.real*tempComplex.real) + (tempComplex.imaginary*tempComplex.imaginary));
}

//the function that calculates the sum of + from  2  complex elements
void addComplex(void* sum, const void * complexA, const void * complexB) {
	*(Complex*)sum = (*(Complex*)complexA) + (*(Complex*)complexB);
}

//the function that calculates the sum of - from  2  complex elements
void subComplex(void* sum, const void * complexA, const void * complexB) {
	*(Complex*)sum = (*(Complex*)complexA) - (*(Complex*)complexB);
}

//the function that calculates the sum of * from  2  complex elements
void multComplex(void* sum, const void * complexA, const void * complexB) {
	*(Complex*)sum = (*(Complex*)complexA) * (*(Complex*)complexB);
}
//the function compare 2 complex elements and giving the result.
int compareComplex(const void *complexA, const void *complexB) {
	if (*(Complex*)complexA == *(Complex*)complexB)
		return 0;
	else if (*(Complex*)complexA > *(Complex*)complexB)
		return 1;
	else
		return -1;
}

//all operators for the type Complex  
#pragma region operators
Complex operator + (const  Complex & lhs, const Complex & rhs) {
	Complex result;
	result.real = lhs.real + rhs.real;
	result.imaginary = lhs.imaginary + rhs.imaginary;
	return result;
}

Complex operator - (const  Complex & lhs, const Complex & rhs) {
	Complex result;
	result.real = lhs.real - rhs.real;
	result.imaginary = lhs.imaginary - rhs.imaginary;
	return result;
}

Complex operator * (const  Complex & lhs, const Complex & rhs) {
	Complex result;
	result.real = lhs.real * rhs.real - lhs.imaginary * rhs.imaginary;
	result.imaginary = lhs.real * rhs.imaginary + rhs.real * lhs.imaginary;
	return result;
}

bool operator == (const  Complex & lhs, const Complex & rhs) {
	if (abs(lhs) == abs(rhs))
		return true;
	else
		return false;
}

bool operator != (const  Complex & lhs, const Complex & rhs) {
	if (abs(lhs) != abs(rhs))
		return true;
	else
		return false;
}

bool operator > (const  Complex & lhs, const Complex & rhs) {
	if (abs(lhs) > abs(rhs))
		return true;
	else
		return false;
}

bool operator < (const  Complex & lhs, const Complex & rhs) {
	if (abs(lhs) < abs(rhs))
		return true;
	else
		return false;
}

bool operator >= (const  Complex & lhs, const Complex & rhs) {
	if (abs(lhs) >= abs(rhs))
		return true;
	else
		return false;
}

bool operator <= (const  Complex & lhs, const Complex & rhs) {
	if (abs(lhs) <= abs(rhs))
		return true;
	else
		return false;
}

istream& operator >> (istream& input, Complex& complexIn) {
	cout << "Enter Real Part: "; 
	input >> complexIn.real;
	cout << "Enter Imagenory Part: ";
	input >> complexIn.imaginary;
	return input;
}

ostream& operator << (ostream& output,  const Complex& complexOut) {
	output << complexOut.real << " + (" << complexOut.imaginary<<")i";
	return output;
}
#pragma endregion

