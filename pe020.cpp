#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int FACT = 100;
const int SIZE = 200;

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




// calculate the factorial 
void calculateFact(int value) {

	int carry = 0;
	digit[0] = 1;
	
	for (int j = 1; j <= value; ++j) {
		carry = 0;
		cout << "j = " << j << endl;
		cout << "------------------ " << endl;

		for (int i = 0; i < SIZE; ++i) {
			digit[i] = (digit[i] * j) + carry;
			if (digit[i] > 9) {
				carry = digit[i] / 10;
				digit[i] %= 10;
				cout << "carry --->" << endl;
			} else {
				carry = 0;
			}
		}
		printDigit();
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
	calculateFact(FACT);
	printDigit();
	result = calculateSum(); 		

	cout << "Result = " << result << endl;	

	return 0;
}

