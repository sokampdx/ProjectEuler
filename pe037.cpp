/* pe37

prime.


*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const unsigned long MAX = 1000000;
const unsigned long LIMIT = 1000;
const unsigned long TOTAL = 100;

bool prime[MAX];
unsigned long truncated[TOTAL];
int countTruncated = 0;

void initialize() {
	for (unsigned long i = 0; i < MAX; ++i) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for (int i = 0; i < TOTAL; ++i) {
		truncated[i] = 0;
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
	unsigned long current = number;
	int count = 0;

	while (current > 0) {
		++count;
		current /= 10;
	}
	
	return count;
}

bool isPrime(unsigned long number) {
	return prime[number];
}

bool isNotInTruncatedList(unsigned long number) {
	bool isNotFound = true;
	int i = 0;	

	while (isNotFound && (i < TOTAL)) {
		if (number == truncated[i])
			isNotFound = false;
		++i;
	}

	return isNotFound;
}


void addNumberToTruncateList(unsigned long number) {
	if (isNotInTruncatedList(number) && (number > 10)) {
		truncated[countTruncated] = number;
		++countTruncated;
	}
}

void checkTruncate(unsigned long number) {
	int length = digitLen(number);
	unsigned long rightTruncateDigits[length];
	unsigned long leftTruncateDigits[length];
	bool isTruncated = true;

	for (int i = 1; i < length; ++i) {
		leftTruncateDigits[i] = (number % ((unsigned long) pow(10, i)));
		rightTruncateDigits[i] = (number / ((unsigned long) pow(10, i)));
		isTruncated = isTruncated && isPrime(leftTruncateDigits[i]) && isPrime(rightTruncateDigits[i]);
//		cout << leftTruncateDigits[i] << ":" << rightTruncateDigits[i] << endl;
	}

	if (isTruncated) {
		addNumberToTruncateList(number);
	}	
}

void printTruncateList() {
	for (int i = 0; i < countTruncated; ++i) {
		cout << truncated[i] << endl;
	}
}

void findAllTruncatePrime() {
	for (unsigned long i = 10; (i < MAX) && (countTruncated < TOTAL) ; ++i) {
		if (isPrime(i))
			checkTruncate(i);
	}
}
		
unsigned long addAllTruncatePrime() {
	unsigned long sum = 0;
	for (int i = 0; i < TOTAL; ++i) {
		sum += truncated[i];
	}

	return sum;
}

int main () 
{
	int result = 0;

	initialize();
	primeSieve();
//	printPrime();

	findAllTruncatePrime();
	printTruncateList();

	result = addAllTruncatePrime();
	cout << "The result = " << result << endl;

	return 0;
}

