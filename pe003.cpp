// project euler problem 3
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

template <class T>
T findLargestPrimeFactor(T number) {
	T current = number;
	T largest = 0;

	int i = 2;
	while (i * i <= number) {
		if (current % i == 0) {
			current /= i;
			largest = i;
		} else {
			++i;
		}
	}

	if (current > largest)
		return current;
	return largest;
}


template <class T>
T findSolution(T number) {
	return findLargestPrimeFactor(number);
}


int main(int argc, char *argv[]) {
	if (argc == 2) {
		istringstream ss(argv[1]);
		unsigned long long n;
		if (!(ss >> n)) {
			cerr << "Invalid number" << argv[1] << endl;
      	} else {
			cout << "The result is = " << findSolution(n) << endl;
		}
	} else {
		cout << "usage: " << argv[0] << " <input> " << endl;
	}

	return 0;
}
