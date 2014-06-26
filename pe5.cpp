#include <iostream>
#include <cmath>

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b)
{
	
	cout << "a & b = " << a << " " << b << endl;
	if (a == 1)
		return 1;
	if (b == 1)
		return 1;

	unsigned int temp;
	temp = a % b;
	if (temp == 0)
		return b;
	
	return gcd(b, temp);	
}


int main()
{
	unsigned int i;
	unsigned int gcdval;
	unsigned int result = 20;

	for (i = 19; i > 1; --i)
	{
		gcdval = gcd(result, i);
		cout << "gcd for " << result << " & " << i << "=" << gcdval << endl;
		result *= i;
		if (gcdval !=  1)
			result = (unsigned int) (result / gcdval);
		cout << result << endl;
	}

	cout << result << endl;

	return 0;
}
