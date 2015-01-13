#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

// global constant
const int MAX = 10000;
const int SIZE = 0;

// global variable
int penNum[MAX];

// init penNum
void initNum() {
	for (int i = 0; i < MAX; ++i)
		penNum[i] = 0;
}

// get pentagon number's nth value
int getN(unsigned long number) {
	int value = round(sqrt(1.0 + 24.0 * (double) number) + 1)/6; 
	return value;
}

// calculate a pentagonal number
unsigned long getPenNumber(int n) {
	unsigned long x = (unsigned long) n;
	unsigned long result = (3 * x - 1) * x / 2;
	if (!penNum[n])
		penNum[n] = result;
	return result;
}



// verify pentagon number
bool isPenNumber(unsigned long number) {
	return getPenNumber(getN(number)) == number;
}

/*
// verify minD after finding a D
unsigned long findMinD(unsigned long minD, int start) {
	int i = start + 1;
	bool isFound = false;
	unsigned long pi = 0;
	unsigned long pj = 0;
	unsigned long result = minD;

	while (!isFound) {
		if (penNum[i]) 
			pi = penNum[i];
		else
			pi = getPenNumber(i);

		int j = i - 1;
		while (!isFound && j > 0) {
			if (penNum[j])
				pj = penNum[j];
			else
				pj = getPenNumber(j);
			
			int d = pi - pj;
			if (i == (j+1) && d > result)
				isFound = true;
			
			if (isPenNumber(pi+pj) && isPenNumber(d) && (d < result)) {
				result = d;
			}

			--j;
		}
		++i;
	}

	return result;

}
*/

// find D
unsigned long findD() {
	int i = 2;
	bool isFound = false;
	unsigned long pi = 0;
	unsigned long pj = 0;
	unsigned long result = 0;
	
	while (!isFound && i < MAX) {
		if (penNum[i]) 
			pi = penNum[i];
		else
			pi = getPenNumber(i);

		int j = i - 1;
		while (!isFound && j > 0) {
			if (penNum[j])
				pj = penNum[j];
			else
				pj = getPenNumber(j);

			if (isPenNumber(pi+pj) && isPenNumber(pi-pj)) {
				isFound = true;
				result = pi -pj;
			}

			--j;
		}
		++i;
	}

	return result;
//	return findMinD(result, getN(pi));
}

// main program
int main () 
{
/*
	cout << isPenNumber(145) << endl;
	cout << "Should be: ";
	cout << 1 << endl;

	cout << isPenNumber(117) << endl;
	cout << "Should be: ";
	cout << 1 << endl;

	cout << isPenNumber(118) << endl;
	cout << "Should be: ";
	cout << 0 << endl;	

	cout << MAX << endl;
*/
	unsigned long result = findD();
	
	cout << "The result = " << result << endl;

	return 0;
}

