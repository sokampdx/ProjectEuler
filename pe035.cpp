#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const unsigned long MAX = 1000000;
const unsigned long LIMIT = 1000;

bool prime[MAX];
bool cirPrime[MAX];


void initialize() {
	for (unsigned long i = 0; i < MAX; ++i) {
		prime[i] = true;
		cirPrime[i] = false;
	}
	
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


int digitLen(unsigned long number) {
	unsigned current = number;
	int count = 0;

	while (current > 0) {
		++count;
		current /= 10;
	}
	
	return count;
}


void recordCirPrime(unsigned long aPrime) {
	int length = digitLen(aPrime);
	int powerOfTen = pow(10, length-1);
	int i = 1;
	unsigned long temp[length];
	unsigned long current;

	temp[0] = current = aPrime;

	while ((prime[current]) && (i < length)) {
		current = powerOfTen*(current%10) + current/10;
		temp[i] = current;
		++i;
	}

	if ((i == length) && (prime[current])) {
		for (int i = 0; i < length; ++i) {
			cirPrime[temp[i]] = true;
			prime[i] = false;
		}
	}
}


void printCirPrime() {
	cout << 2 << endl;
	for (unsigned long i = 3; i < MAX; i+=2) {
		if (cirPrime[i])
			cout << i << endl;
	}
}

int countCirPrime() {
	int count = 1; // 2
	for (unsigned long i = 3; i < MAX; i+=2) {
		if (cirPrime[i])
			++count;
	}
	return count;
}


void checkCirPrime() {
	for (int i = 2; i < 10; ++i) {
		if (prime[i]) {
			cirPrime[i] = true;
		}
	}

	for (unsigned long i = 11; i < MAX; i+=2) {
		recordCirPrime(i);
	}

}


int main () 
{
	int result = 0;

	initialize();
	primeSieve();
//	printPrime();

	checkCirPrime();
//	printCirPrime();

	result = countCirPrime();	

	cout << "The result = " << result << endl;

	return 0;
}

