#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int SIZE = 8;
const int MAX = 200;
const int VALUE[] = {1, 2, 5, 10, 20, 50, 100, 200};

// global variable
int countWay[MAX+1];

// initialize array
void initialize() {
	for (int i = 0; i <= MAX; ++i)
		countWay[i] = 0;
	countWay[0] = 1;
}

// count the number of coin
void countCoin() {
	for (int i = 0; i < SIZE; ++i) {
		for (int value = VALUE[i]; value <= MAX; ++value) {
			countWay[value] += countWay[value - VALUE[i]];
		}
	}
}


// print countWay
void printCount() {
	for (int i = 1; i <= MAX; ++i) {
		cout << countWay[i] << " ";
		if (i % 20 == 0) 
			cout << endl;
	}
	cout << endl;
}
		

// Main program
int main () 
{
	int result = 0;

	initialize();
	countCoin();	

	result = countWay[MAX];
	
	printCount();

	cout << "The result is: " << result << endl;

	return 0;
}

