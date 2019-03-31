/*
File: Complex.h
Description: This is the Complex header file .
Course: 150018 C++ Workshop,
Exercise 2, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#ifndef __COMPLEX_
#define __COMPLEX_

#include"mytypes.h"
#include"Rational.h"
#include<cmath>
#include<iostream>
using namespace std;

struct Complex {
	float real;
	float imaginary;
};

Complex & complexCtor(float, float = 0);

Complex & complexCtor(Rational &, float = 0);

float abs(Complex &tempComplex);

void addComplex(void*, const void *, const void *);

void subComplex(void*, const void *, const void *);

void multComplex(void*, const void *, const void *);

int compareComplex(const void *, const void *);

Complex operator + (const  Complex & lhs, const Complex & rhs);

Complex operator - (const  Complex & lhs, const Complex & rhs);

Complex operator * (const  Complex & lhs, const Complex & rhs);

bool operator == (const  Complex & lhs, const Complex & rhs);

bool operator != (const  Complex & lhs, const Complex & rhs);

bool operator > (const  Complex & lhs, const Complex & rhs);

bool operator < (const  Complex & lhs, const Complex & rhs);

bool operator >= (const  Complex & lhs, const Complex & rhs);

bool operator <= (const  Complex & lhs, const Complex & rhs);

istream& operator >> (istream& , Complex& );

ostream& operator << (ostream& ,  const Complex &);

#endif // !__COMPLEX_
