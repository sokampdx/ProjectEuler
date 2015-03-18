#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

typedef int dtype;

using namespace std;

const dtype LIMIT = 1000000;
const dtype SQRTLIMIT = (dtype) sqrt(LIMIT) + 1;
const dtype FOUND = 8;
const dtype SIZE = 4;

bool prime[LIMIT];

dtype digit[] = {1,3,7,9};


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

dtype nextPrimeAbove(dtype number) {
	if (number == 2)
		return 3;

	dtype value = number + 2;
	while (!isPrime(value))
		value += 2;
	return value;
}

dtype nextPrimeBelow(dtype number) {
	if (number == 3)
		return 2;

	dtype value = number - 2;
	while (!isPrime(value))
		value -= 2;
	return value;
}

dtype findInNdigits() {
	dtype result = 0;
	dtype index = 0;
	bool isFound = false;

	dtype base = 1110;
	
	while ((index < SIZE) && (!isFound)) {
		dtype count = 0;
		dtype min = 0;
		dtype varying = 0;
		dtype constant = 0;
		dtype value = 0;	

		constant = digit[index];
		if (constant % 3 != 0) {
	
			for (dtype i = 1; i < 10; ++i) {
				varying += base;
				value = varying + constant;
			
				if (isPrime(value)) {
					cout << constant << ":" << value << endl;
					if (count == 0) {
						min = value;
					} 
					++count;
				}
			}

			if (count >= FOUND) {
				isFound = true;
				result = min;
			}
		}
		++index;
	}
	return result;
}



dtype find8PrimeFamily() {
	dtype result = 0;

	result = findInNdigits(); 

	return result;
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
	result = find8PrimeFamily();
	cout << "The result is: "  << result << endl;

	return 0;
}

