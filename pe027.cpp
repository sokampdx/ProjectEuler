#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const long MAX = 1000;
const long PRIMEMAX = 1000000;

// global array
long prime[PRIMEMAX];	// generate a list prime < 1000
long ab[2];			// 0 = a, 1 = b

// initialize
void initialize() {
	for (long i = 0; i < PRIMEMAX; ++i)
		prime[i] = 1;
	ab[0] = 0;
	ab[1] = 0;
}

// prime sieve
void primeSieve() {
	long limit = (long) sqrt(PRIMEMAX);

	for (long i = 2; i <= limit; ++i) {
		if (prime[i] == 1) {
			for (long j = i+i; j < PRIMEMAX; j+=i)
				prime[j] = 0;
		}		
	}
}

// print prime list
void printPrime() {
	for (long i = 2; i < PRIMEMAX; ++i) {
		if (prime[i] == (long) 1) {
			cout << i << " ";
		
			if ((i+1) % 13 == 0)
				cout << endl;
		}
	}
	cout << endl;
}	

// check consecutive n
long checkAB(long a, long b) {
	long n = 1;
	long current = n*n + a*n + b;
	long count = 1;
	long temp;

	if (current < 0)
		temp = -1*current;
	else
		temp = current;
	while (prime[temp] == 1) {
		++count;
		++n;
		current = n*n + a*n + b;
		if (current < 0)
			temp = -1*current;
		else
			temp = current;
	}

	return count;
}




// choose a & b
long findResult() {
	long count = 0;
	long maxVal = 0;
	long i = -999;
	long a,b; 
	long temp;

	for (a = -999; a < MAX; a+=2) {
		i = -999;
		while (i < MAX) {
			temp = abs(i);
			if (prime[temp] == 1) {
				b = i;
				count = checkAB(a,b);

				if (count > maxVal) {
					maxVal = count;
					ab[0] = a;
					ab[1] = b;
				}
			}
			++i;
		}
	}

	return ab[0] * ab[1];
}


// Main program
int main () 
{
	long result = 0;
	initialize();
	primeSieve();
//	printPrime();

	result = findResult();
//	result = checkAB(-79, 1601);

	cout << "The result is: " << result << endl;

	return 0;
}

