#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int SIZE = 28123;

// global array
bool abundant[SIZE];
bool sumAbundant[SIZE];

// initialize  array
void initialize() {
	for (int i = 0; i < SIZE; ++i) {
		abundant[i] = false;
		sumAbundant[i] = false;
	}
}

// print digits
void printDigit() {
	for (int i = 0; i<SIZE; ++i) {
		if (sumAbundant[i]==false)
			cout << i << ":" << sumAbundant[i] << endl;
	}
}


// test check
void test() {
	for (int i = 0; i<SIZE; i+=5) {
		abundant[i] = true;
	}
}


// find divisor sum
int divisorSum(int current) {
	int sum = 1;
	int limit = (int) sqrt(current);
	int temp = 0;

	for (int i = 2; i <= limit; ++i) {
		if (current % i == 0) {
			temp = current / i;
			if (i != temp)
				sum += temp;
			sum += i;
		}
	}
	return sum;		
}


// check if number is abundant
void checkAbundant() {
	for (int i = 1; i < SIZE; ++i) {
		if (i < divisorSum(i))
			abundant[i] = true;
	}
}



// find the two abundant
void twoAbundant() {
	for (int i = 1; i < SIZE; ++i) {
		for (int j = i; j < SIZE; ++j) {
			if ((i+j < SIZE) && abundant[i] && abundant[j])
				sumAbundant[i+j] = true;
		}
	}
}
				

// sum of of all non-two-abundant
unsigned long long sumOfNonAbundant() {
	unsigned long long sum = 0;
	for (int i = 1; i < SIZE; ++i) {
		if (sumAbundant[i] == false)
			sum += (unsigned long long) i;
	}

	return sum;
}


// Main program
int main () 
{
	unsigned long long result = 0;

	initialize();
	checkAbundant();
	twoAbundant();
	printDigit();
	result = sumOfNonAbundant();

	cout << "Result = " << result << endl;	

	return 0;
}

