/* Note for pe034

when 2 digit, < 5!
when 3 digit, < 7!
when 4 digit, < 8!
when 5 digit, < 9!

finding the upper limt for the seach.
9! = 362880
9! * 5 = 1814400
9! * 6 = 2177280
9! * 7 = 2540160 <- 7 digit must be the max
9! * 8 = 2903040
9! * 9 = 3265920
9! *10 = 3628800

   



*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

using namespace std;

const unsigned long MAX = 10000000;
unsigned long fact[10]; 


void initialize() {
	unsigned long product = 1;
	for (int i = 1; i < 10; ++i) {
		product *= (unsigned long) i;
		fact[i] = product;
	}
	fact[0] = 1;
}
	
void printFact() {
	for (int i = 1; i < 10; ++i)
		cout << i << ":" << fact[i] << endl;
}


bool isDigitFact(unsigned long num) {
	unsigned long result = 0;
	unsigned long current = num;
	unsigned long digit = num % 10;

	while (result <= num && current > 0) {
		result += fact[(int) digit];
		current /= 10;
		digit = current % 10;
	}

	return (result == num);
}

unsigned long sumDigitFact() {
	unsigned long result = 0;
	for (int i = 10; i < MAX; ++i) {
		if (isDigitFact( (unsigned long) i) ) {
			result += (unsigned long) i;
			cout << i << endl;
		}
	}

	return result;
}


// Main program
int main () 
{
	unsigned long result = 0;
	initialize();
	printFact();

//	cout << isDigitFact(145) << endl;
//	cout << isDigitFact(934) << endl;
	result = sumDigitFact();

	cout << "The result is: " << result << endl;

	return 0;
}

