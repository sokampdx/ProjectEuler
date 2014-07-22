#include <iostream>
#include <cmath>

using namespace std;

const unsigned long long MAX = 2000000;


int main()
{
	unsigned long long sum = 2;
	unsigned long long i, j;
 	bool prime[MAX];

	// initialize array
	for (i = 0; i < MAX; ++i)
		prime[i] = true;

	// initialize even number not prime (except 2)
	for (i = 4; i < MAX; i+=2)
		prime[i] = false;

	// eliminate non prime
	for (i = 3; i < MAX; i+=2)
	{
		if (prime[i]) {
			for (j = 2i; j < MAX; j+=i)
				prime[j] = false;
			sum += i;
		}
	}
	cout << "The sum = " << sum << endl;
}
		
