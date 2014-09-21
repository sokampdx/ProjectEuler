/* Note for pe033

for the canceling to work, one of the digit
on num must match den. since non trivial.
No number with 0 will work.

also notice the following relationship
cx/yc = x/y or xc / cy = x/y
y*cx = yc*x or xc*y = x*cy
cx < yc, x < y, xc < cy

by creating 3 loop of x, y, c where
x from 1 to 9
y from x+1 to 9 (y>x because x/y > 1)
and then loop c from 1 to 9
and check the two conditions of equality
above, we can quickly find the four solution

the final answer is y / gcd(x,y)
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

using namespace std;

int gcd(int m, int n) {
	if (n == 0)
		return m;
	return gcd(n, m%n);
}


// choose fraction
int cancelingFraction() { 
	int den = 1;
	int num = 1;

	for (int x = 1; x <= 9; ++x) {
 		for (int y = x+1; y <= 9; ++y) {
			for (int c = 1; c <= 9; ++c) {
				int y_cx = y*(c*10+x);
				int yc_x = (y*10+c)*x;
				int xc_y = (x*10+c)*y;
				int x_cy = x*(c*10+y);
				if (y_cx == yc_x || xc_y == x_cy) {
					num *= x;
					den *= y;
//					cout << x << ":" << y << ":";
//					cout << y_cx << ":" << yc_x << ":";
//					cout << x_cy << ":" << xc_y << endl;
//					cout << x << ":" << y << endl;
				}
			}
		}
	}
	return den/ gcd(num, den);
}


// Main program
int main () 
{
	int result = 0;

	result = cancelingFraction();
	cout << "The result is: " << result << endl;

	return 0;
}

