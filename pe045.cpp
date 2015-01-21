#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

// global constant
const int HEX = 144;
const int PEN = 166;
const int TRI = 286;

// global variable

// return the nth s-sides-polygon number
unsigned long getPolygon(int s, int a) {
	unsigned long n = (unsigned long) a;
	return (n * n * (s - 2) - n * (s - 4)) / 2;
}

// return the nth triangle number
unsigned long getTriangle(int n) {
	return getPolygon(3, n);
}

// return the nth pentagon number
unsigned long getPentagon(int n) {
	return getPolygon(5, n);
}

// return the nth hexagon number
unsigned long getHexagon(int n) {
	return getPolygon(6, n);
}

// return the value of n for that nth-s-Polygon number
int getNFromPolygon(int s, unsigned long x) {
	int a = s - 4;
	int b = s - 2;
	return round((sqrt(8.0 * b * x + a * a) + a) / (2.0 * b)); 
} 

// return the value of n for that nth Triangle number
int getNFromTriangle(unsigned long x) {
	return getNFromPolygon(3, x);
}

// return the value of n for that nth Pentagon number
int getNFromPentagon(unsigned long x) {
	return getNFromPolygon(5, x);
}

// return the value of n for that nth Hexagon number
int getNFromHexagon(unsigned long x) {
	return getNFromPolygon(6, x);
}

// verify polygon number
bool isPolygon(int s, unsigned long x) {
	int n = getNFromPolygon(s, x);
	return getPolygon(s, n) == x;
}

// verify triangle number
bool isTriangle(unsigned long x) {
	return isPolygon(3, x);
}

// verify pentagon number
bool isPentagon(unsigned long x) {
	return isPolygon(5, x);
}

// verify hexagon number
bool isHexagon(unsigned long x) {
	return isPolygon(6, x);
}

// check the next Ta=Pb=Hc number
unsigned long findNext() {
	bool found = false;
	int nextHex = HEX;

	while (!found) {
		found = isPentagon(getHexagon(nextHex));
		++nextHex;
	}

	return getHexagon(nextHex-1);

}



// test
void test() {
	unsigned long x = 40755;

	cout << isHexagon(x) << endl;
	cout << "Expect: 1" << endl;
	cout << isPentagon(x) << endl;
	cout << "Expect: 1" << endl;
	cout << isTriangle(x) << endl;
	cout << "Expect: 1" << endl;

	int n = 285;
	cout << getTriangle(n) << endl;
	cout << "Expect: 40755" << endl;
	
	n = 165;
	cout << getPentagon(n) << endl;
	cout << "Expect: 40755" << endl;

	n = 143;
	cout << getHexagon(n) << endl;
	cout << "Expect: 40755" << endl;
	
	x = 40754;
	cout << isHexagon(x) << endl;
	cout << "Expect: 0" << endl;
	cout << isPentagon(x) << endl;
	cout << "Expect: 0" << endl;
	cout << isTriangle(x) << endl;
	cout << "Expect: 0" << endl;

	x = 40756;
	cout << isHexagon(x) << endl;
	cout << "Expect: 0" << endl;
	cout << isPentagon(x) << endl;
	cout << "Expect: 0" << endl;
	cout << isTriangle(x) << endl;
	cout << "Expect: 0" << endl;

	x = 45;
	cout << isHexagon(x) << endl;
	cout << "Expect: 1" << endl;
	cout << isPentagon(x) << endl;
	cout << "Expect: 0" << endl;
	cout << isTriangle(x) << endl;
	cout << "Expect: 1" << endl;

	
	
}



// main program
int main () 
{
	//test();
	unsigned long result = findNext();
	
	cout << "The result = " << result << endl;

	return 0;
}

