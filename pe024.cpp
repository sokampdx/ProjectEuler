#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const unsigned long LIMIT = 1000000;
const int SIZE = 10;

// global array
int digit[SIZE];
int used[SIZE];
int final[SIZE];
unsigned long current = LIMIT;


// initialize 
void initialize() {
	for (int i = 0; i < SIZE; ++i) {
		digit[i] = -1;
		used[i] = -1;
		final[i] = -1;
	}
}



// factorial
unsigned long factorial (int value) {
	unsigned long product = 1;
	for (int i = 1; i <= value; ++i) {
		product *= (unsigned long) i;
	}
	
	return product;
}


// check the limit
int checkLimit(int level) {
	unsigned long sum = 0;
	int repeat = 0;

	while (sum < current) {
		sum += factorial(SIZE-level);
		++repeat; 
	}
	current -= (sum - factorial(SIZE-level));
	
	return (repeat - 1) ;
}


// permutation
void permutation() {
	for (int i = 0; i < SIZE; ++i) {
		 digit[i] = checkLimit(i);
	}
}


// print array
void printArray() {
	for (int i = 0; i < SIZE; ++i) {
		cout << digit[i] << endl;
	}
}

// find answer
void findAnswer() {
	int i, j, k;

	for (i = 1; i < SIZE; ++i) {
		j = 0;
		k = 0;
		while (j <= digit[i]) {
			if (used[k] < 0)
				++j;
			++k;
		}
		used[k-1] = 1;
		final[i-1] = k-1;
	} 

	i = 0;
	while (used[i] < 0) {
		++i;
	}
	final[SIZE-1] = i-1;
}	


// print answer
void printAnswer() {
	for (int i = 0; i < SIZE; ++i) {
		cout << final[i];
	}
	cout << endl;
}


// Main program
int main () 
{
	unsigned long result = 0;
	initialize();
	permutation();
	findAnswer();
	printAnswer();

//	cout << "Result = " << result << endl;	

	return 0;
}

