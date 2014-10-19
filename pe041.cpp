#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

using namespace std;

const unsigned long MAX7 = 7654321;
const unsigned long MIN7 = 1234567;
const unsigned long MAX4 = 4321;
const unsigned long MIN4 = 1234;
const unsigned long MAX = 987654321;
const unsigned long MIN = 12;
const unsigned long LIMIT = 10000000;
const unsigned long SQRTLIMIT = 10000;
const int SIZE = 8;

bool digits[SIZE];
bool prime[LIMIT];


void initialize() {
	for (unsigned long i = 0; i < LIMIT; ++i) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for (unsigned long i = 4; i < LIMIT; i+=2)
		prime[i] = false;
}


void primeSieve() {
	for (unsigned long i = 3; i < SQRTLIMIT; i+=2) {
		if (prime[i]) {
			for (unsigned long j = (i+i); j < LIMIT; j+=i)
				prime[j] = false;
		}
	}
}


bool isPrime(unsigned long number) {
	return prime[number];
}


void printPrime() {
	cout << 2 << endl;
	for (unsigned long i = 3; i < LIMIT; i+=2) {
		if (prime[i])
			cout << i << endl;
	}
}


int length(unsigned long number) {
	unsigned long current = number;
	int count = 0;
	
	while (current > 0) {
		++count;
		current /= 10;
	}

	return count;
}


void resetDigit() {
	for (int i = 0; i < SIZE; ++i)
		digits[i] = false;
}


bool isAllDigitFilled(int len) {
	bool isFull = true;

	for (int i = 1; i <= len; ++i)
		isFull = isFull && digits[i];

	return isFull;
}

bool isPandigital(unsigned long number) {
	if ((number > MAX) || (number < MIN))
		return false;

	unsigned long current = number;
	resetDigit();
	int len = length(number);

	for (int i = 1; i <= len; ++i) {
		digits[current % 10] = true;
		current /= 10;
	}
	
	return isAllDigitFilled(len);
}

bool isWithinRange(unsigned long number) {
	if ((number > MAX7) || (number < MIN4) 
		|| ((number > MAX4) && (number < MIN7)))
		return false;
	return true;
}

unsigned long findLargestPandigitalPrime() {
	unsigned long i = MAX7;

	while (!(isPrime(i) && isWithinRange(i) && isPandigital(i))) {
		--i;
	}

	return i;
}


void test() {
	cout << "Length(1000) is 4 = " << length(1000) << endl;
	cout << "IsPandigital(1234) is true = " << isPandigital(1234) << endl;
	cout << "IsPandigital(1111) is falue = " << isPandigital(1111) << endl;
	cout << "IsPandigital(123456789) is true = " << isPandigital(123456789) << endl;
	cout << "IsPandigital(124456789) is false = " << isPandigital(124456789) << endl;
	cout << "isWithinRange(12) is false = " << isWithinRange(12) << endl;
	cout << "isWithinRange(1234) is true = " << isWithinRange(1234) << endl;
	cout << "isWithinRange(54321) is false = " << isWithinRange(54321) << endl;
	cout << "isWithinRange(4321567) is true = " << isWithinRange(4321567) << endl;
	cout << "isPrime(2143) is true = " << isPrime(2143) << endl;
	cout << "isPrime(4296311) is false = " << isPrime(4296311) << endl;
}


int main () 
{
	unsigned long result = 0;

	initialize();
	primeSieve();
//	printPrime();

	result = findLargestPandigitalPrime();	

	cout << "The result is: " << result << endl;

	return 0;
}

