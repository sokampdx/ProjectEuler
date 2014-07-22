#include <iostream>
#include <cmath>

using namespace std;

const unsigned long long MAX = 1000000;
const unsigned long long END = 1;

// return length of chain 
int getLength(unsigned long long value) {

	int evenLen = 0;
	int oddLen = 0;;

	if (value == END)
		return 1;

	if (value % 2)
		oddLen = getLength(3 * value + 1);
	else
		evenLen = getLength(value / 2);

	return max(oddLen, evenLen) + 1;
}

// find which start number has the longest chain
unsigned long long findLongest(unsigned long long limit) {
	unsigned long long maxStart = 0;
	int maxChain = 0;
	int current;
	
	for (unsigned long long i = 2; i <= MAX; ++i) {
		current = getLength(i);
		if (current > maxChain) {
			maxStart = i;
			maxChain = current;
			cout << i << ":" << current << endl;
		}
	}	
	return maxStart;
}

// main function
int main()
{
	unsigned long long result = findLongest(MAX);
		
	cout << "Result = " << result << endl;


	return 0;
}
		
