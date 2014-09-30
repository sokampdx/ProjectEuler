#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

using namespace std;

const unsigned long MAX = 1000;

bool isRightTriangle(unsigned long a, unsigned long b,
					unsigned long perimeter) {
	unsigned long c = perimeter - a - b;
	
	return ((c*c) == ((a*a) + (b*b)));
}


unsigned long findNumberSolution(unsigned long perimeter) {
	unsigned long count = 0;
	unsigned long limit = perimeter / 2;

	for (unsigned a = 1; a <= limit; ++a ) {
		for (unsigned b = a + 1; b < limit; ++b) {
			if (isRightTriangle(a,b,perimeter))
				++count;
		}
	}
	return count;
}

unsigned long findMaxSolution() {
	unsigned long maxSolution = 0;
	unsigned long pValueMax = 0;	

	for (unsigned long i = MAX; i > 3; --i) {
		unsigned long numSolution = findNumberSolution(i);
		if (numSolution > maxSolution) {
			maxSolution = numSolution;
			pValueMax = i;
		} 
	}	


	return pValueMax;
}

int main () 
{
	unsigned long result = 0;

	result = findMaxSolution();

	cout << "The result is: " << result << endl;

	return 0;
}

