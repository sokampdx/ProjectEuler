#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int MAX = 100;
const int MIN = 2;
const int SIZE = MAX * MAX;

// global variable
int term[MAX+1][MAX+1];
int limit;

// initialize
void initialize() {
	for (int i = 0; i <= MAX; ++i) {
		for (int j = 0; j <= MAX; ++j) {
			term[i][j] = 0;
		}
	}
}

// gcd
int gcd(int m, int n) {
	if (n == 0)
		return m;
	return gcd(n, m % n); 
}



// mark duplicate for a with b
void markDuplicate(int a, int exp) {
	int num = 0;
	int div = 0;
	int step = 0;
	int upperb;

	for (num = 1; num < exp; ++num) {
		upperb = (num * MAX) / exp;
		div = gcd(num, exp);
		if (div > 1)
			step = num / div;
		else
			step = num;

		for (int b = num; b <= upperb; b+=step) {
			term[a][b] = 1;
		}
	}
}



// find duplicate
void findDuplicate() {
	int root = 0;
	int value = 0;

	for (int exp = MIN; exp <= limit; ++exp) {
		for (int a = MIN; a <= MAX; ++a) {
			root = pow(a, 1.0/exp);
			value = pow(root, exp);

//			cout << "find:" << a << ":" << root << ":" << value << ":" << limit << endl;

			if (a == value) {
				cout << "find:" << a << endl;
				markDuplicate(a, exp);
			}		
		}
	}
}


// count all the duplicate
int countDuplicate() {
	int count = 0;

	for (int a = MIN; a <= MAX; ++a) {
		for (int b = MIN; b <= MAX; ++b) {
			count += term[a][b];
		}
	}
	
	return count;
}



// find limit
int findLimit() {
	int a = MIN;
	int exp = MIN-1;
	int result;

	do {
		++exp;
		result = (int) pow(a, exp);
	} while (result <= MAX);

	return exp-1;
}


// print terms
void printTerms() {
	for (int a = MIN; a <= MAX; ++a) {
		cout << a << " ";
		if ((a-1) % 33 == 0)
			cout << endl;
	}
	cout << endl;

	for (int a = MIN; a <= MAX; ++a) {
		cout << a << endl;
		for (int b= MIN; b <= MAX; ++b) {
			cout << term[a][b] << " ";
			if ((b-1) % 33 == 0)
				cout << endl;
		}
	}
	cout << endl;
}



// Main program
int main () 
{
	int result = (MAX-MIN+1)*(MAX-MIN+1);
	initialize();
	limit = findLimit();
	findDuplicate();

	printTerms();
	
	result -= countDuplicate();

	cout << "The result is: " << result << endl;

	return 0;
}

