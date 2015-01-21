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

bool isPerfectSquare(unsigned long x) {
	return x == round(sqrt(x)) * round(sqrt(x));
}

unsigned long nextPrimeBelow(unsigned long n) {
	unsigned long p = n - 2;
	while (!prime[p]) {
		p-=2;
	}
	return p;
}

unsigned long nextCompositeAbove(unsigned long n) {
	unsigned long x = n + 2;
	while (prime[x]) {
		x+=2;
	}
	return x;
}

unsigned long findSmallest() {
	unsigned long answer = 0;
	unsigned long n = 9;
	unsigned long p = 3;
	bool found = false;

	while (!answer && n < MAX) {
		p = nextPrimeBelow(n);
		found = false;
		while (!found && p > 2) {
			if (isPerfectSquare( (n-p) / 2)) {
				found = true;
			}
			p = nextPrimeBelow(p);
		}
		if (!found) {
			answer = n;
		}
		n = nextCompositeAbove(n);
	}
	return answer;
}	

		

void test() {
	unsigned long x = 1;
	cout << isPerfectSquare(x) << endl;
	cout << "Expect: 1" << endl;
	x = 4;
	cout << isPerfectSquare(x) << endl;
	cout << "Expect: 1" << endl;
	x = 122;
	cout << isPerfectSquare(x) << endl;
	cout << "Expect: 0" << endl;
	x = 120;
	cout << isPerfectSquare(x) << endl;
	cout << "Expect: 0" << endl;

	unsigned long p = 384547;
	cout << prime[p] << endl;
	cout << "Expect: 1" << endl;
	
	x = p;
	cout << nextPrimeBelow(x) << endl;
	cout << "Expect: 384533" << endl;
	x = 121;
	cout << nextPrimeBelow(x) << endl;
	cout << "Expect: 113" << endl;
	x = 27;
	cout << nextPrimeBelow(x) << endl;
	cout << "Expect: 23" << endl;
	
	x = 119;
	cout << nextCompositeAbove(x) << endl;
	cout << "Expect: 121" << endl;
	x = 3;
	cout << nextCompositeAbove(x) << endl;
	cout << "Expect: 9" << endl;
	x = 7545;
	cout << nextCompositeAbove(x) << endl;
	cout << "Expect: 7551" << endl;
		
}


// main program
int main () 
{
	initialize();
	primeSieve();
	//printPrime();

	//test();	

	cout << "The result = " << findSmallest() << endl;
	return 0;
}

