#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

using namespace std;

// global const
const unsigned int MAX = 9;
const unsigned int SIZE = 100;

// global variable
bool used[MAX+1];
list<unsigned int> products;

// check if the sequence of digit are pandigital
bool isPandigital() {
	int i = 1;

	while (used[i])
		++i;

	if (i > MAX)
		return true;
	return false;
}


// initialize array
void initialize() {
	for (int i = 1; i <= MAX; ++i)
		used[i] = false;
	used[0] = true;
}

// set digit
void setDigits(unsigned int num) {
	while (num > 0) {
		unsigned int i = num % 10;
		num /= 10;
		used[i] = true;
	}		
}

// set test pandigital
void testDigits(unsigned int num) {
	initialize();
	setDigits(num);
	cout << num << " is";
	if (!isPandigital())
		cout << " not";
	cout << " Pandigital." << endl;
}

// test pandigitals
bool isPandigital(unsigned int num) {
	initialize();
	setDigits(num);
	return isPandigital();
}



// concatenate integer
unsigned int concat(unsigned int a, unsigned int b) {
	unsigned int temp = b;
	while (temp > 0) {
		a *= 10;
		temp /= 10;
	}

	return a + b;
}


// find sum of product
unsigned int findSum() {
	unsigned int sum = 0;
	unsigned int product = 0;
	unsigned int digits = 0;	

	for (unsigned int i = 2; i < 999; ++i) {
		unsigned int begin = 123;
		unsigned int end = 10000 / i + 1; 
		if (i < 10) {
			begin = 1234;
		}

		for (unsigned int  j = begin; j < end; ++j) {
			product = i * j;
			digits = concat(concat(i, j), product);
			if ((digits > 100000000) && (digits < 1000000000) && (isPandigital(digits))) {
				products.push_back(product);
				cout << i << ":" << j << ":" << digits << endl;
			}
		}
	}

	products.sort();
	products.unique();

	for (list<unsigned int>::iterator it = products.begin(); it!= products.end(); ++it)
		sum += *it;

	return sum;
}


// Main program
int main () 
{
	unsigned int result = 0;

	initialize();
	result = findSum();

	cout << "The result is: " << result << endl;

	return 0;
}

