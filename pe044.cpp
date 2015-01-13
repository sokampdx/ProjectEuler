#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

// global constant

// global variable

// get pentagon number's nth value
int getN(unsigned long number) {
	int value = round(sqrt(1.0 + 24.0 * (double) number) + 1)/6; 
	return value;
}

// calculate a pentagonal number
unsigned long getPenNumber(int n) {
	unsigned long x = (unsigned long) n;
	unsigned long result = (3 * x - 1) * x / 2;
	return result;
}



// verify pentagon number
bool isPenNumber(unsigned long number) {
	return getPenNumber(getN(number)) == number;
}

// verify minD after finding a D
unsigned long findMinD(unsigned long minD, int start) {
	int i = start + 1;
	bool isFound = false;
	unsigned long pi = 0;
	unsigned long pj = 0;
	unsigned long result = minD;

	while (!isFound) {
		pi = getPenNumber(i);

		int j = i - 1;
		bool isOver = false;
		while (!isFound && !isOver && j > 0) {
			pj = getPenNumber(j);
			
			int d = pi - pj;
			if (d < result) {
				//cout << i << endl;
				if (isPenNumber(pi+pj) && isPenNumber(d)) 
					result = d;
			} else {
				isOver = true;
				if (i == (j+1))
					isFound = true;
			}

			--j;
		}
		++i;
	}

	return result;

}


// find D
unsigned long findD() {
	int i = 2;
	bool isFound = false;
	unsigned long pi = 0;
	unsigned long pj = 0;
	unsigned long result = 0;
	
	while (!isFound) {
		pi = getPenNumber(i);

		int j = i - 1;
		while (!isFound && j > 0) {
			pj = getPenNumber(j);

			if (isPenNumber(pi+pj) && isPenNumber(pi-pj)) {
				isFound = true;
				result = pi -pj;
			}

			--j;
		}
		++i;
	}

	//	cout << "---> " << result << endl;

	return findMinD(result, getN(pi));
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

