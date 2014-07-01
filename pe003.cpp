// project euler problem 3
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <cmath>

using namespace std;


unsigned long long VALUE = 600851475143;
// unsigned long long VALUE = 486847;


int testMul(unsigned long long val)
{
	unsigned long long limit;
	unsigned long long list[10];
	int num = 0;

	limit = (unsigned long long) sqrt( (double) val);	
	
	for (unsigned long long counter = 3; counter < limit; counter += 2)
	{
		if ((val % counter) == 0)
		{
			list[num] = counter;
			cout << counter << endl;
			cout << " ";
			testMul(counter);
			cout << endl;
			++num;
		}
	}
	
	return list[num];
}


int main()
{
	unsigned long long val = VALUE;
	int numList = 1;
	
	testMul(val);

	return 0;	
}

