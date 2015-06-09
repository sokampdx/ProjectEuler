#include <iostream> 
#include <sstream>
#include "lib/mathutil.h"
 
using namespace std; 

template <class T>
T findN(T max, T divisor) {
	return ((max - 1) / divisor);
}

template <class T>
T findSolution(T max) {
	T i, j, k;
	T sum = 0;
	MathUtil<T> mathutil;

	i = findN(max, 3);
	j = findN(max, 5);
	k = findN(max, 15);

	sum += (3 * mathutil.sumP1(0, i));
	sum += (5 * mathutil.sumP1(0, j));
	sum -= (15 * mathutil.sumP1(0, k));

	return sum;
}
 
int main(int argc, char *argv[]) {
	if (argc == 2) {
		istringstream ss(argv[1]);
		int n;
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
  

