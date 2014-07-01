#include <iostream>
#include <cmath>

using namespace std;




// const unsigned long long MAX = 10000;
const unsigned long long MAX = 10001;

int main ()
{

	unsigned long long count = 1;
	unsigned long long j;
	unsigned long long i = 2;
	unsigned long long list[MAX];	
	bool prime;

	prime = true;

	list[count] = i;
	cout << count << ":" << i << endl;

	for ( i = 3; count < MAX; i = i + 2)
	{
//		cout << i << endl;
		prime = true;

		for ( j = 1; j <= count; ++j)
		{
//			cout << j << endl;
			if (i % list[j] == 0)
				prime = false;
		}
		
		if (prime)
		{
			cout << ++count << ":" << i << endl;
			list[count] = i;
		}
			
		prime = true;
	}
	
	cout << list[MAX] << endl;
	return 0;

	
}
