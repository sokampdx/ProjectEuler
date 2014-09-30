#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

using namespace std;

const unsigned long LARGEST = 987654321;
const unsigned long SMALLEST = 123456789;
const unsigned long MAX = 9999;
const unsigned long MIN = 9;
const int SIZE = 10;

bool digits[SIZE];

void initializeDigit() {
	for (int i = 0; i < SIZE; ++i)
		digits[i] = false;
}

bool isAllDigitFilled() {
	bool isFull = true;

	for (int i = 1; i < SIZE; ++i)
		isFull = isFull && digits[i];

	return isFull;
}

bool isPandigital(unsigned long number) {
	if ((number > LARGEST) || (number < SMALLEST)) 
		return false;
	
	unsigned long current = number;
	initializeDigit();		

	for (int i = 1; i < SIZE; ++i) {
		digits[current % 10] = true;
		current /= 10;
	}
	
	return isAllDigitFilled();
}


int length(unsigned long number) {
	unsigned long current = number;
	int count = 0;
	
	while (current > 0) {
		++count;
		current /= 10;
	}

	return count;
}


unsigned long concateList(unsigned long *digitList, int size) {
	unsigned long current = 0;

	for (int i = 0; i < size; ++i) {
		int currentLen = length(digitList[i]);
		current *= (pow(10, currentLen));
		current += digitList[i];
	}

	return current;
}

unsigned long findPandigitProduct(unsigned long number) {
	int availableLen = 9 - length(number);
	unsigned long *digitList = new unsigned long[SIZE];
	unsigned long i = 0;

	digitList[i++] = number;

	while (availableLen > 0) {
		unsigned long current = number * (i + 1);
		availableLen -= length(current);
		digitList[i++] = current;
	}

	return concateList(digitList, i);
}


unsigned long findMaxPandigit() {
	unsigned long max = 0;
	unsigned long current = 0;

	for (unsigned long i = MAX; i > MIN; --i) {
		current = findPandigitProduct(i);
		if (isPandigital(current) && (current > max))
			max = current;
	}

	return max;
}


int main () 
{
	unsigned long result = 0;
	
	result = findMaxPandigit();

	cout << "The result is: " << result << endl;

	return 0;
}

