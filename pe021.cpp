#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int SIZE = 10000;

// global array
unsigned int amicable[SIZE];

// initialize  array
void initialize() {
	for (int i = 0; i < SIZE; ++i) {
		amicable[i] = 0;
	}
}

// print digits
void printDigit() {
	for (int i = 0; i<SIZE; ++i) {
		if (amicable[i]==1)
			cout << i << ":" << amicable[i] << endl;
	}
}


// test check
void test() {
	for (int i = 0; i<SIZE; i+=5) {
		amicable[i] = 1;
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


// matching the pair
void matchPair (int current) {
	if (current >= SIZE)
		return;
	if (amicable[current] != 0)
		return;
	
	int match = divisorSum(current);
	int next = divisorSum(match);

	cout << current << "-" << match << "-" << next << endl;
	if ((current == next) && (match != current)) {
		amicable[current] = 1;
		amicable[next] = 1;
	} else if (match == current) {
		amicable[current] = -1;
	} else {
		amicable[current] = -1;
		matchPair(match);
	}
}



// amicable pair
void findAmicablePair() {
	for (int i = 2; i <= SIZE; ++i) {
		matchPair(i);
	}
}


// find sum
unsigned int findSum() {
	unsigned int sum = 0;

	for (int i = 2; i <= SIZE; ++i) {
		if (amicable[i] == 1) {
			sum += (unsigned int) i;
		}
	}

	return sum;
}


// Main program
int main () 
{
	unsigned int result = 0;

	initialize();
	findAmicablePair();
	printDigit();

	result = findSum();
	
	cout << "Result = " << result << endl;	

	return 0;
}

