#include <iostream>
#include <cmath>
#include <sstream>
#include "lib/mathutil.h"

using namespace std;

template <class T>
T findSolution(T min, T max) {
	MathUtil<T> mathutil;
	T gcdvalue;
	T i;
	T result = max;

	for (i = max-1; i >= min; --i) {
		gcdvalue = mathutil.gcd(result, i);
		result *= i;
		
		if (gcdvalue != 1)
			result = (T) (result / gcdvalue);
	}

	return result;
}


void usage(char *argv) {
	cout << "usage: " << argv << " min max " << endl;
}


int main(int argc, char *argv[]) {
	bool isValid = true;

	if (argc == 3) {
		unsigned long n[2];
		for (int i = 1; i < argc; ++i) {
			istringstream ss(argv[i]);
			if (!(ss >> n[i-1])) {
				cerr << "Invalid number: " << argv[i] << endl;
				isValid = false;
			}
		}

		if (isValid) {
			if (n[0] > n[1]) {
				cerr << n[0] << " must be less than " << n[1] << endl;
				usage(argv[0]);
			} else {
				cout << "The result is = " << findSolution(n[0], n[1]) << endl;
			}
		} else {
			usage(argv[0]);
		}
	} else {
		usage(argv[0]);
	}

	return 0;
}
