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

//bool prime[MAX];
int composite[MAX];

void initialize() {

	for (unsigned long i = 0; i < MAX; ++i) {
//		prime[i] = true;
		composite[i] = 0;
	}
	
	for (unsigned long i = 4; i < MAX; i+=2) {
//		prime[i] = false;
		++composite[i];
	}
}


void primeSieve() {

	for (unsigned long i = 3; i < LIMIT; i+=2) {
/*		if (prime[i]) {
			for (unsigned long j = (i+i); j < MAX; j+=i)
				prime[j] = false;
		}
*/
		if (!composite[i]) {
			for (unsigned long j = (i+i); j < MAX; j+=i)
				++composite[j];
		}
	}
}

/*
void printPrime() {
	cout << 2 << endl;
	for (unsigned long i = 3; i < MAX; i+=2) {
		if (prime[i])
			cout << i << endl;
	}
}

unsigned long nextPrime(unsigned long p) {
	if (prime[p])
		return p;
	return nextPrime(p+2);
}


int distinct(int max, int count, unsigned long n, unsigned long p) {
	//cout << max << ":" << count << ":" << n << ":" << p << endl;
	if (count >= max || p > n)
		return count;
	
	if (n % p == 0)
		return distinct(max, count+1, n/p, nextPrime(p+2));

	return distinct(max, count, n, nextPrime(p+2));
}


bool hasDistinctPrime(int max, unsigned long n) {
	int count = 0;
	if (n % 2 == 0)
		count =  distinct(max, 1, n/2, 3);
	else
		count = distinct(max, 0, n, 3);

	//cout << count << endl;
	return count >= max;
}

unsigned long find(int max) {
	bool found = false;
	unsigned long n = 210;
	unsigned long lowest = 0;
	int count = 0;

	while (!found) {
		if (hasDistinctPrime(max, n)) {
			if (count == 0) {
				lowest = n;
			}
			++count;
		} else {
			count = 0;
		}

		if (count >= max) {
			found = true;
		}

		++n;
	}

	return lowest;
}
*/

unsigned long find2(int max) {
	bool found = false;
	unsigned long n = 14;
	unsigned long lowest = 0;
	int count = 0;

	while (!found) {
		if (composite[n] >= max) {
			if (count == 0) {
				lowest = n;
			}
			++count;
		} else {
			count = 0;
		}

		if (count >= max) {
			found = true;
		}

		++n;
	}

	return lowest;
}
			

		
/*
void test() {
	int max = 2;
	unsigned long n = 14;
	
	cout << hasDistinctPrime(max, n) << endl;
	cout << "Expected: 1" << endl;		

	n = 15;	
	cout << hasDistinctPrime(max, n) << endl;
	cout << "Expected: 1" << endl;		

	max = 3;
	n = 644;
	cout << hasDistinctPrime(max, n) << endl;
	cout << "Expected: 1" << endl;		
	++n;
	cout << hasDistinctPrime(max, n) << endl;
	cout << "Expected: 1" << endl;		
	++n;	
	cout << hasDistinctPrime(max, n) << endl;
	cout << "Expected: 1" << endl;		

	n = 643;
	cout << hasDistinctPrime(max, n) << endl;
	cout << "Expected: 0" << endl;		

	cout << find(2) << endl;
	cout << "Expected: 14" << endl;

	cout << find(3) << endl;
	cout << "Expected: 644" << endl;

}
*/

// main program
int main () 
{
	initialize();
	primeSieve();
	//printPrime();

	//	test();	
	int max = 4;

	unsigned long result = find2(max);
	cout << "The result = " << result << endl;

	return 0;
}

