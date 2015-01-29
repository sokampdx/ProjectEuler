#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

typedef int dtype;

using namespace std;

const dtype LIMIT = 100;
const dtype SQRTLIMIT = 10;

bool prime[LIMIT];


void initialize() {
	for (dtype i = 0; i < LIMIT; ++i) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for (dtype i = 4; i < LIMIT; i+=2)
		prime[i] = false;

}


void primeSieve() {
	for (dtype i = 3; i < SQRTLIMIT; i+=2) {
		if (prime[i]) {
			for (dtype j = (i+i); j < LIMIT; j+=i)
				prime[j] = false;
		}
	}
}


bool isPrime(dtype number) {
	return prime[number];
}


void printPrime() {
	cout << 2 << endl;
	for (dtype i = 3; i < LIMIT; i+=2) {
		if (prime[i])
			cout << i << endl;
	}
}


void test() {
	
}


int main () 
{
	dtype result = 0;

	initialize();
	primeSieve();
	//printPrime();

	//test();

	cout << "The result is: "  << result << endl;

	return 0;
}

