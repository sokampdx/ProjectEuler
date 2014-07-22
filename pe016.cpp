#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int EXP = 1000;
const int BASE = 2;
const int SIZE = 330;

// global array
int digit[SIZE];

// initialize path array
void initialize() {
	for (int i = 0; i < SIZE; ++i) {
		digit[i] = 0;
	}
}

// print digits
void printDigit() {
	for (int i = SIZE - 1; i >= 0; --i) {
		cout << digit[i];
		if ((i % 30) == 0)
			cout << endl;
	}
	cout << endl;
}


// calculate the base^exponent
void calculatePower(int base, int exponent) {

	int carry = 0;
	digit[0] = 1;
	
	for (int j = 1; j <= exponent; ++j) {
		carry = 0;
		for (int i = 0; i < SIZE; ++i) {
			digit[i] = digit[i] * base + carry;
//			cout << i << ":" << digit[i];
			if (digit[i] > 9) {
				digit[i] %= 10;
				carry = 1;
//				cout << "XXXXX";
			} else {
				carry = 0;
			}
//			cout << "---- i vs i+1-----" << digit[i] << " VS " << digit[i+1] << endl;

		}
	}	
}


// calculate digit sum
int calculateSum() {
	int sum = 0;	

	for (int i = 0; i < SIZE; ++i) {
		sum += digit[i];
	}
	
	return sum;
}


// Main program
int main () 
{
	int result = 0;

	initialize();
	calculatePower(BASE, EXP);
	printDigit();
	result = calculateSum(); 		

	cout << "Result = " << result << endl;	

	return 0;
}

