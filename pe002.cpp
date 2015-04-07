#include <iostream> 
#include <sstream>
#include "lib/fibonacci.h"

using namespace std; 
 

template <class T>
T findSolution(T max) {
	Fibonacci<T> fibonacci(max);

	return fibonacci.getSumOfEvenTerm();
}

 
int main(int argc, char *argv[]) {
	if (argc == 2) {
		istringstream ss(argv[1]);
		unsigned long n;
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
 
