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
//int prime[] = {2,3,5,7,11,13,17};
int prime[] = {17, 13, 11, 7, 5, 3, 2};

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

bool isDivisible (int number, int prime) {
	return !(number % prime);
}

int getLastThreeDigit(long number) {
	return (int) (number % 1000);
}

bool isAllDivisible(long number) {
	long temp = number;
	bool result = true;

	for (int i = 6; i >= 0; --i) {
		int lastThree = (int) (temp % 1000);
		temp /= 10;
				
		result &= isDivisible(lastThree, prime[i]);
	}
	
	return result;
}

long sumAllDivisible() {
	long sum = 0;
	long number = 0;
	int next;

	int i = 0;
	for (int d10 = prime[i]; d10 < 1000; d10+=prime[i]) {
		number = (long) d10;
		for (int d7 = 0; d7 < 10; ++d7) { 			
			next = d7*100 + d10/10;
			if (next % prime[i+1]) {
				number = (long) (d7*1000 + d10);
				for (int d6 = 0; d6 < 10; d6+=5) {
					number
				} 
			}
		}
	}
		
		
		

	for (long i = MIN; i <= MAX; ++i) {	
			
		
		cout << i << endl;
		if (isPandigit(i) && isAllDivisible(i)) {
			sum += i;
		}
	}

	return sum;
}

int main () {
/*
	long n = 9876543210;
	
	cout << isPandigit(n) << endl;

	n = 9999999999;
	cout << isPandigit(n) << endl;

	int threeDigits = getLastThreeDigit(n);
	cout << threeDigits << endl;
	cout << isDivisible(threeDigits, 2) << endl;
	cout << isDivisible(threeDigits, 3) << endl;
	
	n = 1406357289;
	cout << isAllDivisible(n) << endl;
	n = 9876543210;
	cout << isAllDivisible(n) << endl;
*/
	cout << "The result is " << sumAllDivisible() << endl;
	
	return 0;
}

