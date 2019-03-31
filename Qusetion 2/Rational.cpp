/*
File: Rational.cpp
Description: This is the Rational cpp file .
Course: 150018 C++ Workshop,
Exercise 2, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/
#include"Rational.h"
using namespace std;



//Creating a rationale and reducing it to the smallest
Rational & rationalCtor(int numerator, uint denominator) {

	Rational tempRational;
	tempRational.numerator = numerator;
	tempRational.denominator = denominator;
	if (numerator < 0)
		reductFraction(tempRational, gcd(numerator *-1, denominator));
	else
		reductFraction(tempRational, gcd(numerator, denominator));
	return tempRational;
}

//A function that receives a numerator and a denominator finds the greatest possible reduction
uint gcd(uint a, uint b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

//A function that receives a counter and a denominator and the reduction  that was found and performs the reduction.
void reductFraction(Rational &tempRrational, uint gcd) {
	if (gcd <= 1)
		return;
	if (!tempRrational.numerator)
		tempRrational.denominator = 1;
	else {
		tempRrational.numerator /= (int)gcd;
		tempRrational.denominator /= gcd;
	}
}

//the function that calculates the sum of + from  2  ratioanl elements
void addRational(void * sum, const void * rationalA, const void * rationalB) {
	*(Rational*)sum = *(Rational*)rationalA + *(Rational*)rationalB;
}

//the function that calculates the sum of - from  2 elements
void subRational(void * sum, const void * rationalA, const void * rationalB) {
	*(Rational*)sum = *(Rational*)rationalA - *(Rational*)rationalB;
}

//the function that calculates the sum of * from  2 ratioanl elements
void multRational(void * sum, const void * rationalA, const void * rationalB) {
	*(Rational*)sum = (*(Rational*)rationalA) * (*(Rational*)rationalB);
}

//the function compare 2 ratioanl elements and giving the result.
int compareRational(const void * rationalA, const void * rationalB) {
	if ((*(Rational*)rationalA) == (*(Rational*)rationalB))
		return 0;
	else if ((*(Rational*)rationalA) > (*(Rational*)rationalB))
		return 1;
	else
		return -1;
}


//all operators for the type Rational  
#pragma region operators

Rational  operator + (const  Rational & lhs, const Rational & rhs) {
	Rational result;
	result.numerator = lhs.numerator * rhs.denominator + lhs.denominator * rhs.numerator;
	result.denominator = lhs.denominator * rhs.denominator;

	if (result.numerator < 0)
		reductFraction(result, gcd(result.numerator *-1, result.denominator));
	else
		reductFraction(result, gcd(result.numerator, result.denominator));
	return result;
}

Rational operator - (const  Rational & lhs, const Rational & rhs) {
	Rational result;
	result.numerator = lhs.numerator * rhs.denominator - lhs.denominator * rhs.numerator;
	result.denominator = lhs.denominator * rhs.denominator;
	if (result.numerator < 0)
		reductFraction(result, gcd(result.numerator *-1, result.denominator));
	else
		reductFraction(result, gcd(result.numerator, result.denominator));
	return result;
}

Rational operator * (const  Rational & lhs, const Rational & rhs) {
	Rational result;
	result.numerator = lhs.numerator * rhs.numerator;
	result.denominator = lhs.denominator * rhs.denominator;
	if (result.numerator < 0)
		reductFraction(result, gcd(result.numerator *-1, result.denominator));
	else
		reductFraction(result, gcd(result.numerator, result.denominator));
	return result;
}

bool operator == (const  Rational & lhs, const Rational & rhs) {
	if (!((lhs - rhs).numerator))
		return true;
	else
		return false;
}

bool operator != (const  Rational & lhs, const Rational & rhs) {
	if ((lhs - rhs).numerator)
		return false;
	else
		return true;
}

bool operator > (const  Rational & lhs, const Rational & rhs) {
	if ((lhs - rhs).numerator > 0)
		return true;
	else
		return false;
}

bool operator < (const  Rational & lhs, const Rational & rhs) {
	if ((lhs - rhs).numerator < 0)
		return true;
	else
		return false;
}

bool operator >= (const  Rational & lhs, const Rational & rhs) {
	if ((lhs - rhs).numerator >= 0)
		return true;
	else
		return false;
}

bool operator <= (const  Rational & lhs, const Rational & rhs) {
	if ((lhs - rhs).numerator <= 0)
		return true;
	else
		return false;
}

istream& operator >> (istream& input, Rational& rationalIn) {
	cout << "Enter numerator part : ";
	input >> rationalIn.numerator;
	cout << "Enter denominator Part: ";
	input >> rationalIn.denominator;
	return input;
}

ostream& operator << (ostream& output, const Rational& rationalOut) {
	output << rationalOut.numerator << "/" << rationalOut.denominator;
	return output;
}
#pragma endregion

