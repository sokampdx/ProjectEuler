#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int MAX = 1000;


// global array
int decimal[MAX];


// initialize
void initialize() {
	for (int i = 0; i < MAX; ++i)
		decimal[i] = 0;
}



// find maximum recipical cycle
int findAnswer () {
	int longestCycle = 0;
	int maximum = 0;

	for (int i = MAX; i > 1; --i) {
		if (longestCycle >= i)
			break;

		initialize();
		int value = 1;
		int position = 0;
		
		while (decimal[value] == 0 && value != 0) {
			decimal[value] = position;
			value = (value * 10) % i;
			++position;
		}

		if ((position - decimal[value]) > longestCycle) {
			longestCycle = position - decimal[value];
			maximum = i;
		} 
	}

	return maximum;
}






// Main program
int main () 
{
	int result = findAnswer();

	cout << "The result is: " << result << endl;

	return 0;
}

