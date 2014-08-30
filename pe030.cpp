#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const long EXP = 5;
const long MAX = 6*pow(9,EXP);
const long POW[] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};

// global variable


// find sum of fifth power
long findSum() {
	long sum = 0;
	long total = 0;
	long number = 0;

	for (long i = 2; i < MAX; ++i) {
		sum = 0;
		number = i;
		while (number > 0) {
			long digit = number % 10;
			number /= 10;

//			sum += pow(digit, EXP);
			sum += POW[digit];
		}
		
		if (sum == i) {
			cout << i << endl;
			total += i;
		}
	}

	return total;
}



// Main program
int main () 
{
	long result = 0;

	result = findSum();	

	cout << "The result is: " << result << endl;

	return 0;
}

