#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1000;

int main()
{
	int a, b, c;
	int result, temp, test;
	
	for (a = 1; a < MAX; ++a)
	{
		for (b = a; b < MAX; ++b) 
		{
			
			temp = (a*a) + (b*b);
			test = (int) sqrt(temp);
			
//			cout << temp << ":" << test << endl;			

			result = test * test;

			if (result == temp)
			{
				result = test + a + b - MAX;
//				cout << result << endl;
			}


			if (result == 0)
			{
				c = test;
				result = a * b * c;
				cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
				cout << result << endl;
			}

//			cout << "---------------" << endl;
		}
	}

	return 0;
}
