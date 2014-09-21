#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

// global constant
const unsigned long MAX = 1000000;
const unsigned long LIMIT = 1000;
const string FILENAME = "prime.txt";

bool prime[MAX];


void initialize() {
	for (unsigned long i = 0; i < MAX; ++i)
		prime[i] = true;
	
	for (unsigned long i = 4; i < MAX; i+=2)
		prime[i] = false;
}


void primeSieve() {
	for (unsigned long i = 3; i < LIMIT; i+=2) {
		if (prime[i]) {
			for (unsigned long j = (i+i); j < MAX; j+=i)
				prime[j] = false;
		}
	}
}


void printPrime() {
	cout << 2 << endl;
	for (unsigned long i = 3; i < MAX; i+=2) {
		if (prime[i])
			cout << i << endl;
	}
}


// main program
int main () 
{
	initialize();
	primeSieve();
	printPrime();

	return 0;
}

