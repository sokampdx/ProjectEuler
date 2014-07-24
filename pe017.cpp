#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int UNIT[10] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
const int TEEN[10] = {3, 6,6, 8, 8, 7, 7, 9, 8, 8};
const int TENTH[10] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};
const int HUNDRED = 7;
const int THOUSAND = 8;
const int AND = 3;
const int TEN = 10;

// calculate 0-9
int calculateUnit() {
	int subTotal = 0;

	for (int i = 1; i < TEN; ++i)
		subTotal += UNIT[i];

	cout << "1-9: " << subTotal << endl;
	return subTotal;
}

// calculate 10-19
int calculateTeen() {
	int subTotal = 0;

	for (int i = 0; i < TEN; ++i)
		subTotal += TEEN[i];

	cout << "10-19: " << subTotal << endl;
	return subTotal;
}

// calculate 20-99
int calculateTenth() {
	int subTotal = 0;
	int unit = calculateUnit();	

	for (int i = 2; i < TEN; ++i)
		subTotal += TENTH[i] * 10 + unit;
		
	cout << "20-99: " << subTotal << endl;
	return subTotal;
}

// calculate 100-999
int calculateHundred() {
	int subTotal = 0;
	int unit = calculateUnit();
	int tenth = calculateTenth() + calculateTeen() ;

	for (int i = 1; i < TEN; ++i) {
		subTotal += (UNIT[i] + HUNDRED) * 100;
		subTotal += AND * 99;
		subTotal += unit + tenth;
	}

	cout << "100-999: " << subTotal << endl;
	return subTotal;
}

// calculate 1000
int calculateThousand() {
	return UNIT[1] + THOUSAND;
}


// Main program
int main () 
{
	int result = 0;

	result += calculateUnit();
	result += calculateTeen();
	result += calculateTenth();
	result += calculateHundred();
	result += calculateThousand();;

	cout << "Result = " << result << endl;	

	return 0;
}

