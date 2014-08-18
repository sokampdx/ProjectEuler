#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int MAX = 1000;

// global array

// initialize
void initialize(int *current, int value) {
	for (int i = 0; i < MAX; ++i) {
		current[i] = 0;
	}
	current[0] = value;
}


// print number array
void printNumber (int *current) {
	for (int i = 0; i < MAX; ++i) {
		cout << current[i];
		if (((i+1) % 50) == 0)
			cout << endl; 
	}
	cout << endl;
}


// add two int array
void add(int *prev, int*next) {
	for (int i = 0; i < MAX; ++i) {
		prev[i] = prev[i] + next[i];
	}

	for (int i = 0; i < MAX; ++i) {
		if ((prev[i] / 10) > 0) {
			prev[i+1] += prev[i] / 10;
			prev[i] = prev[i] % 10;
		}
	}
}




// fab
int fab(int *prev, int *next) {
	int *temp;
	int i=1;

	while(next[MAX-1] == 0) {
		add(prev, next);

		temp = prev;
		prev = next;
		next = temp;

		printNumber(next);
		++i;
	}
	return i;
}


// Main program
int main () 
{
	int *prev = new int[MAX];
	int *next = new int[MAX];
	int result = 0;

	initialize(prev, 0);
	initialize(next, 1);

	printNumber(prev);
	printNumber(next);
	result = fab(prev, next);
	cout << "The result is: " << result << endl;


	free(next);
	free(prev);

	return 0;
}

