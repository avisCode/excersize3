/*
File: Rational.h
Description: This is the Rational header file .
Course: 150018 C++ Workshop,
Exercise 2, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#ifndef __RATIONAL_
#define __RATIONAL_

#include"mytypes.h"
#include<iostream>
using namespace std;

struct Rational {
	int numerator;
	uint denominator;
};

Rational & rationalCtor(int , uint  = 1);

uint gcd(uint a, uint b);

void reductFraction(Rational &tempRrational, uint gcd);

void addRational(void *, const void *, const void *);

void subRational(void *, const void *, const void *);

void multRational(void *, const void *, const void *);

int compareRational(const void *, const void *);

Rational operator + (const  Rational & lhs, const Rational & rhs);

Rational operator - (const  Rational & lhs, const Rational & rhs);

Rational operator * (const  Rational & lhs, const Rational & rhs);

bool operator == (const  Rational & lhs, const Rational & rhs);

bool operator != (const  Rational & lhs, const Rational & rhs);

bool operator > (const  Rational & lhs, const Rational & rhs);

bool operator < (const  Rational & lhs, const Rational & rhs);

bool operator >= (const  Rational & lhs, const Rational & rhs);

bool operator <= (const  Rational & lhs, const Rational & rhs);

istream& operator >> (istream& input, Rational& rationalIn);

ostream& operator << (ostream &output, const Rational& rationalOut);

#endif // !__RATIONAL_
