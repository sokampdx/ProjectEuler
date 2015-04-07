#include <iostream> 
#include <sstream>
#include "lib/summation.h"
 
using namespace std; 
 
int main(int argc, char *argv[]) {
	if (argc == 2) {
		istringstream ss(argv[1]);
		int n;
		if (!(ss >> n)) {
			cerr << "Invalid number" << argv[1] << endl;
      	} else {
			Summation<int> sum(n);
			cout << "The result is = " << sum.getResult() << endl;
		}
	} else {
		cout << "usage: " << argv[0] << " <input> " << endl;
	}

	return 0;
}
  

