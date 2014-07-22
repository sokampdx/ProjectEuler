#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int SIZE = 20;

// global array
unsigned long long path[SIZE][SIZE];

// initialize path array
void initializePath()
{
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			path[i][j] = 0;
		}
	}
}


// enumerate route
unsigned long long  enumRoute(int bottom, int right) {
	if (bottom == 0 || right == 0)
		return 1;

	if (path[bottom][right] == 0)
		path[bottom][right] =  enumRoute(bottom - 1, right) + enumRoute(bottom, right - 1);

	return path[bottom][right];
}


// Main program
int main () 
{
	unsigned long long routeLength;

	initializePath();
	routeLength = enumRoute(SIZE, SIZE);
		

	cout << "Result = " << routeLength << endl;	

	return 0;
}

