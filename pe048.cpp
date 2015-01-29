#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>

typedef unsigned long long ULL;

using namespace std;

// global constant
const ULL TENDIGIT = 10000000000LL;
const ULL MAX = 1000LL;

ULL power(ULL x, ULL p) {
	if (p == 1LL)
		return x;
	
	ULL result = power(x, p/2) % TENDIGIT;
	// still overflow for unsigned long long
	result = (result * result) % TENDIGIT;
	//cout << p << ":" << p/2 << ":" << p%2 << ":" << result << endl;
	
	if (p % 2LL == 0LL) {
		return result;
	}

	return (result * x) % TENDIGIT;
}


ULL power2(ULL x, ULL p) {
	ULL result = x;
	for (ULL i = 0; i < p-1; ++i) {
		result = (result * x) % TENDIGIT;
	}

	return result;
}


ULL selfPower(ULL x) {
	return power2(x, x) % TENDIGIT;
}



ULL lastTenDigit() {
	ULL result = 0;
	for (ULL i = 1; i <= MAX; ++i) {
		result = (result + selfPower(i)) % TENDIGIT;
	}

	return result;
}

void test() {
	ULL x = 3;
	cout << power(x, x) << endl;
	cout << selfPower(x) << endl;
	x = 999;
	cout << power(x, x) << endl;
	cout << selfPower(x) << endl;
	
	ULL y = 9999999999 * 9999999999;
	cout << y << endl;
	cout << power(y, 2) << endl;
	cout << power2(y, 2) << endl;

	cout << LLONG_MAX << endl;
	cout << LONG_MAX << endl;

	cout << 999/2 << endl;
}




// main program
int main () 
{
	//test();
	ULL result = lastTenDigit();
	cout << "The result = " << result << endl;

	return 0;
}

