/*
File: main.cpp
Description: This is the main cpp file.
Course: 150018 C++ Workshop,
Exercise 2, Question 1
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cstdlib>
#include"menu.h"
using namespace std;

int const sizeOfArr = 4;
int number, index1, index2, index3;
int arrInt[sizeOfArr];
float arrFloat[sizeOfArr];
float numberFloat;
Rational arrRatoinal[sizeOfArr], ratoinal;
Complex arrComplex[sizeOfArr], complex;
void subMenuCall();
SubMenuOption chosenB;

int main(void) {
	srand((unsigned)time(NULL));
	//filling by randomly all arrays
	for (int i = 0; i < sizeOfArr; i++) {
		arrInt[i] = rand() % 21 - 10;
		arrFloat[i] = (rand() % 20 - 10) + (float)rand() / RAND_MAX;
		arrRatoinal[i] = rationalCtor(rand() % 21 - 10, rand() % 30 + 1);
		arrComplex[i] = complexCtor((rand() % 20 - 10 + (float)rand() / RAND_MAX), (rand() % 20 - 10 + (float)rand() / RAND_MAX));
	}
	MenuOption chosen;
	// Everything happens inside of this do-while loop, until the user
	//     has decided to exit (or an error occurs).
	do {
		cout << endl << "Menu options:" << endl << endl;
		// The user will see:
		//           0 -- exit
		//           1 -- ...
		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION; ++chosen)
			cout << chosen << endl;
		cout << endl;
		cout << "Please choose a menu option: ";
		cin >> chosen;
		switch (chosen) {
		case EXIT_MENU:
			cout << "Thanxs for using Bus Fleet Management Program!" << endl;
			break;
		case INPUT_NUMBER:
			subMenuCall();
			switch (chosenB) {
			case INT:
				cout << "enetr a int value: ";
				cin >> number;
				cout << "enter the index in array to save to: ";
				cin >> index1;
				if (inputToInt(number, index1, arrInt, sizeOfArr))
					cout << "Successfully added";
				else
					cout << "ERROR index is invalid";
				break;
			case FLOAT:
				cout << "enetr a float value: ";
				cin >> numberFloat;
				cout << "enter the index in array to save to: ";
				cin >> index1;
				if (inputToFloat(numberFloat, index1, arrFloat, sizeOfArr))
					cout << "Successfully added";
				else
					cout << "ERROR index is invalid";
				break;
			case RATIONAL:
				cout << "enter the index in array to save to: ";
				cin >> index1;
				cin >> ratoinal;
				if (inputToRational(ratoinal.numerator, ratoinal.denominator, index1, arrRatoinal, sizeOfArr))
					cout << "Successfully added";
				else
					cout << "ERROR index is invalid";
				break;
			case COMPLEX:
				cout << "enter the index in array to save to: ";
				cin >> index1;
				cin >> complex;
				if (inputToComplex(complex.real, complex.imaginary, index1, arrComplex, sizeOfArr))
					cout << "Successfully added";
				else
					cout << "ERROR index is invalid";
				break;
			default:
				cout << "ERROR\n";
				break;
			}
			break;
		case OUTPT_NUMBERS:
			subMenuCall();
			switch (chosenB)
			{
			case INT:
				cout << "in array of type int of size " << sizeOfArr << " Stored values:\n";
				outputInt(arrInt, sizeOfArr);
				break;
			case FLOAT:
				cout << "in array of type float of size " << sizeOfArr << " Stored values:\n";
				outputFloat(arrFloat, sizeOfArr);
				break;
			case RATIONAL:
				cout << "in array of type Rational of size " << sizeOfArr << " Stored values:\n";
				outputRational(arrRatoinal, sizeOfArr);
				break;
			case COMPLEX:
				cout << "in array of type complex of size " << sizeOfArr << " Stored values:\n";
				outputComplex(arrComplex, sizeOfArr);
				break;
			default:
				cout << "ERROR\n";
				break;
			}
			break;
		case CALCULATE_ALL_NUMBERS_IN_ARRAY:
			subMenuCall();
			switch (chosenB) {
			case INT:
				cout << "the sum is : " << arrIntSum(arrInt, sizeOfArr);
				break;
			case FLOAT:
				cout << "the sum is : " << arrFloatSum(arrFloat, sizeOfArr);
				break;
			case RATIONAL: {
				cout << "the sum is : " << arrRationalSum(arrRatoinal, sizeOfArr);
				break;
			}
			case COMPLEX: {
				cout << "the sum is : " << arrComplexSum(arrComplex, sizeOfArr);
				break;
			}
			default:
				cout << "ERROR\n";
				break;
			}
			break;
		case CALCULATE_MULTIPLICATOIN_ALL_NUMBERS_IN_ARRAY:
			subMenuCall();
			switch (chosenB) {
			case INT:
				cout << "the sum is : "<<arrIntMult(arrInt, sizeOfArr);
				break;
			case FLOAT:
				cout << "the sum is : " << arrFloatMult(arrFloat, sizeOfArr);
				break;
			case RATIONAL: {
				cout << "the sum is : " << arrRationalMult(arrRatoinal, sizeOfArr);;
				break;
			}
			case COMPLEX: {
				cout << "the sum is : " << arrComplexMult(arrComplex, sizeOfArr);;
				break;
			}
			default:
				cout << "ERROR\n";
				break;
			}
			break;
		case CALCULATE_SUM_2NUMBERS_IN_ARRAY:
			subMenuCall();
			switch (chosenB) {
			case INT:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				add2IntElemants(arrInt, index1, index2, index3);
				cout << "the sum is : " << arrInt[index3];
				break;
			case FLOAT:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				add2FloatElemants(arrFloat, index1, index2, index3);
				cout << "the sum is : " << arrFloat[index3];
				break;
			case RATIONAL:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				add2RationalElemants(arrRatoinal, index1, index2, index3);
				cout << "the sum is : " << arrRatoinal[index3];
				break;
			case COMPLEX:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				add2ComplexElemants(arrComplex, index1, index2, index3);
				cout << "the sum is : " << arrComplex[index3];
				break;
			default:
				cout << "ERROR\n";
				break;
			}
			break;
		case CALCULATE__SUBTRACTOIN_2NUMBERS_IN_ARRAY:
			subMenuCall();
			switch (chosenB) {
			case INT:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				sub2IntElemants(arrInt, index1, index2, index3);
				cout << "the sum is : " << arrInt[index3];
				break;
			case FLOAT:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				sub2FloatElemants(arrFloat, index1, index2, index3);
				cout << "the sum is : " << arrFloat[index3];
				break;
			case RATIONAL:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				sub2RationalElemants(arrRatoinal, index1, index2, index3);
				cout << "the sum is : " << arrRatoinal[index3];
				break;
			case COMPLEX:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				sub2ComplexElemants(arrComplex, index1, index2, index3);
				cout << "the sum is : " << arrComplex[index3];
				break;
			}
			break;
		case CALCULATE_MULTIPLICATOIN_2NUMBERS_IN_ARRAY: {
			subMenuCall();
			switch (chosenB) {
			case INT:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				mult2IntElemants(arrInt, index1, index2, index3);
				cout << "the sum is : " << arrInt[index3];
				break;
			case FLOAT:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				mult2FloatElemants(arrFloat, index1, index2, index3);
				cout << "the sum is : " << arrFloat[index3];
				break;
			case RATIONAL:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				mult2RationalElemants(arrRatoinal, index1, index2, index3);
				cout << "the sum is : " << arrRatoinal[index3];
				break;
			case COMPLEX:
				cout << "enter the first index: ";
				cin >> index1;
				cout << "enter the secund index: ";
				cin >> index2;
				cout << "enter the index in array to save to: ";
				cin >> index3;
				if (index1 >= sizeOfArr || index2 >= sizeOfArr || index3 >= sizeOfArr) {
					cout << "EROOR one of the indexes are to0 big\n";
					break;
				}
				mult2ComplexElemants(arrComplex, index1, index2, index3);
				cout << "the sum is : " << arrComplex[index3];
				break;
			}
			break;
		}
		case SORT_ALL_NUMBERS_IN_ARAAY: {subMenuCall();
			switch (chosenB)
			{
			case INT:
				qsort(arrInt, sizeOfArr, sizeof(int), [](const void * a, const void * b)->int {
					if (*(int*)a < *(int*)b) return -1;
					if (*(int*)a == *(int*)b) return 0;
					if (*(int*)a > *(int*)b) return 1;
				});
				cout << "after sort :\n";
				outputInt(arrInt, sizeOfArr);
				break;
			case FLOAT:
				qsort(arrFloat, sizeOfArr, sizeof(float), [](const void * a, const void * b)->int {
					if (*(float*)a < *(float*)b) return -1;
					if (*(float*)a == *(float*)b) return 0;
					if (*(float*)a > *(float*)b) return 1;
				});
				cout << "after sort :\n";
				outputFloat(arrFloat, sizeOfArr);
				break;
			case RATIONAL:
				qsort(arrRatoinal, sizeOfArr, sizeof(Complex), compareRational);
				cout << "after sort :\n";
				outputRational(arrRatoinal, sizeOfArr);
				break;
			case COMPLEX:
				qsort(arrComplex, sizeOfArr, sizeof(Rational), compareComplex);
				cout << "after sort :\n";
				outputComplex(arrComplex, sizeOfArr);
				break;
			default:
				cout << "ERROR\n";
				break;
			}
			break;
		}
		default:
			cout << "ERROR\n";
			break;
		}
	} while (chosen != EXIT_MENU);
	system("pause");
	return 0;
}

//the function that calls the prints the submenu options and gets the user selection for the switch case submenu.
void subMenuCall() {
	cout << endl << "Type options:" << endl;
	for (chosenB = FIRST_SUBMENU_OPTION; chosenB <= LAST_SUBMENU_OPTION; ++chosenB)
		cout << chosenB << endl;
	cout << endl;
	cout << "Please choose a type :";
	cin >> chosenB;
}
