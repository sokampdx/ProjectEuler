#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

using namespace std;

const long MAX = 9876543210;
const long MIN = 1023456789;
const int SIZE = 10;


bool hasDigit[SIZE];
int prime[] = {2,3,5,7,11,13,17};
//int prime[] = {17, 13, 11, 7, 5, 3, 2};

void initDigit() {
	for (int i = 0; i < SIZE; ++i)
		hasDigit[i] = false;
}


void setDigit(long number) {
	initDigit();
	long temp = number;
	int digit;
	for (int i = 0; i < SIZE; ++i) {
		digit = (int) (temp % 10);
		temp /= 10;
		hasDigit[digit] = true;
	}
}

		
bool isPandigit (long number) {
	bool result = true;
	setDigit(number);
	for (int i = 0; i < SIZE; ++i) { 
		result &= hasDigit[i];
	}
	return result;
}

bool isDivisible (int number, int divisor) {
	return !(number % divisor);
}

int getLastThreeDigit(long number) {
	return (int) (number % 1000);
}

bool isAllDivisible(long number) {
	long temp = number;
	bool isValid = true;

	int i = 6;
	while (i >= 0 && isValid) {
		int lastThree = (int) (temp % 1000);
		isValid &= isDivisible(lastThree, prime[i]);
		temp /= 10;		
		--i;
	}
	
	return isValid;
}


void printPerm(int perm[]) {
	for (int i = SIZE-1; i>=0; --i) {
		cout << perm[i];
	}
	cout << endl;
}

long nextPermutation(long number) {
	int perm[SIZE];
	long temp = number;


	// if number = 1023456789
	// perm[] = {9,8,7,6,5,4,3,2,0,1}
	for (int k = 0; k < SIZE; ++k) {
		perm[k] = (int) (temp % 10);
		temp /= 10;
	}

//	cout << "init:: ";
//	printPerm(perm);
//	cout << endl;

	// find the largest index i such that ai < ai-1 but ai-1 > ai-2 ... a0
	int i = 1;
	bool isIncreasing = true;
	while (i < SIZE-1 && isIncreasing)  {
		if (perm[i] > perm[i-1]) {
			++i;
		} else {
			isIncreasing = false;
		}
	}
	
	// find index j with min aj such that ai < aj and 0 <= j < i
	long nextMin = 10;
	int j;
	for (int k = 0; k < i; ++k) {
		if (perm[k] > perm[i] && perm[k] < nextMin) {
			j = k;
			nextMin = perm[j];
		}
	}

//	cout << "i:" << i << " j:" << j << endl;

	// swap i and j
	int digit = perm[i];
	perm[i] = perm[j];
	perm[j] = digit;	

//	cout << "swap:: ";
//	printPerm(perm);
//	cout << endl;

	// reverse ai+1 to an
	int limit = i - 1;
	int max = i /2;
	for (int k = 0; k < max; ++k) {
		digit = perm[k];
		perm[k] = perm[limit - k];
		perm[limit - k] = digit;
	}

//	cout << "revs:: ";
//	printPerm(perm);
//	cout << endl;

	temp = 0;
	for (int k = SIZE-1; k >= 0; --k) {
		temp = (temp * 10) + (long) perm[k];
	}

	return temp;
}


	
long sumAllDivisible() {
	long sum = 0;
	long next = MIN;
	
	while (next >= MIN && next <= MAX) {
		if (isAllDivisible(next)) {
//			cout << next << endl;
			sum += next;
		}
	
		next = nextPermutation(next);
	} 

	return sum;
}




int main () {

/*
	long n = 9876543210;
	cout << isPandigit(n) << endl;
	cout << "Should be = ";
	cout << 1 << endl;

	n = 9999999999;
	cout << isPandigit(n) << endl;
	cout << "Should be = ";
	cout << 0 << endl;

	int threeDigits = getLastThreeDigit(n);
	cout << threeDigits << endl;
	cout << "Should be = ";
	cout << 999 << endl;

	cout << isDivisible(threeDigits, 2) << endl;
	cout << "Should be = ";
	cout << 0 << endl;

	cout << isDivisible(threeDigits, 3) << endl;
	cout << "Should be = ";
	cout << 1 << endl;
	
	n = 1406357289;
	cout << isAllDivisible(n) << endl;
	cout << "Should be = ";
	cout << 1 << endl;

	n = 9876543210;
	cout << isAllDivisible(n) << endl;
	cout << "Should be = ";
	cout << 0 << endl;

	cout << nextPermutation(MIN) << endl;
	cout << "Should be = ";
	cout << 1023456798 << endl;	

	n = 9087362541;
	cout << nextPermutation(n) << endl;
	cout << "Should be = ";
	cout << 9087364125 << endl;	
*/

	cout << "The result is " << sumAllDivisible() << endl;
	
	return 0;
}

