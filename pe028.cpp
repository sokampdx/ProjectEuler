#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const long long MAX = 500;
const long long MIN = 1;

// sum constant
long long sumConst(long long lower, long long upper) {
	return upper - lower + 1;
}

// sum i
long long sumI(long long lower, long long upper) {
	if (lower == 1)
		return (upper * (upper + 1)) / 2;
	return sumI(1, upper) - sumI(1, lower-1);
}


// sum i2
long long sumI2(long long lower, long long upper) {
	if (lower == 1)
		return (upper * (upper + 1) * (2 * upper + 1)) / 6;
	return sumI2(1, upper) - sumI2(1, lower-1);
}


// Main program
int main () 
{
	long long result = 0;

	result = 1 + 4 * sumConst(MIN, MAX) + 4 * sumI(MIN, MAX) + 16 * sumI2(MIN,MAX);

	cout << "The result is: " << result << endl;

	return 0;
}

