#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

using namespace std;

const unsigned long MAX = 1000000;
const int MAXDIGIT = 8;
unsigned long digitLimit[MAXDIGIT];

void initialize () {
	digitLimit[0] = 0;

	for (int i = 1; i < MAXDIGIT; ++i) {
		unsigned long d = (unsigned long) i;
		unsigned long min = (unsigned long) pow(10,d-1);
		unsigned long max = (unsigned long) pow(10,d) - 1; 
		digitLimit[i] = ((max - min + 1) * d) 
			+ digitLimit[i-1];
	}
}

void printLimit() {
	for (int i = 0; i < MAXDIGIT; ++i) {
		cout << digitLimit[i] << endl;
	}
}

int length(unsigned long number) {
	int count = 0;
	unsigned long current = number;
	unsigned long previous = number;

	while (current > 0) {
		previous = current;
		current /= 10;
		++count;
	}

	return count;
}

unsigned long splitDigit(unsigned long number, 
						 int position) {
	int len = length(number);
	int limit = len - position - 1;
	unsigned long current = number;

	for (int i = 0; i < limit; ++i)
		current /= 10;

	return current % 10;
}


unsigned long findDigit(unsigned long position) {
	unsigned long current = position;
	unsigned long intValue;
	int digitPosition;
	int i = 0;

	if (position > MAX)
		return 0;

	if (position < 10)
		return position;

	while (current > digitLimit[i]) {
		++i;
	}	
	

	// find the value
	unsigned long d = (unsigned long) i; 
	current = (position - digitLimit[d-1] + d - 1);
	intValue = current / d;
	intValue += (unsigned long) pow(10, d-1) - 1;
	
	// find the digit
	digitPosition = (int) (current % d);
	
	current = splitDigit(intValue, digitPosition);

	return current;
}


int findProduct() {
	int product = 1;
	unsigned long current;

	for (int i = 0; i < 7; ++i) {
		current = (unsigned long) pow(10, i);
		product *= (int) findDigit(current);
	}
	
	return product;
}




int main () 
{
	int result = 0;
	initialize();

	result = findProduct();	

	cout << "The result is: " << result << endl;

/*
// test
	cout << "----- TEST ------- " << endl;
	cout << "Test the digitLimit " << endl;
	printLimit();

	cout << "test length" << endl;
	cout << length(10000) << " = 5" << endl;
	cout << length(1) << " = 1" << endl;

	cout << "test find Digit" << endl;
//	cout << findDigit(10000000) << " = 0" << endl;
	cout << findDigit(9) << " = 9 " << endl;
	cout << findDigit(10) << " = 1 " << endl;
	cout << findDigit(11) << " = 0 " << endl;
	cout << findDigit(12) << " = 1" << endl;
	cout << findDigit(187) << " = 8" << endl;
	cout << findDigit(188) << " = 9" << endl;
	cout << findDigit(189) << " = 9" << endl;
	cout << findDigit(190) << " = 1" << endl;
	cout << findDigit(191) << " = 0" << endl;
	cout << findDigit(192) << " = 0" << endl;
	cout << findDigit(193) << " = 1" << endl;
*/
	return 0;
}

