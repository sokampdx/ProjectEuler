#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i;
	int j;
	int value, test;
	int a, b, c, d, e, f;
	int answer = 0;

	i = 999;
	while (i > 100)
	{
		j = 999;
		test = i * 999;
		while (j > 100 && test > answer)
		{
			value = i * j;
			a = value / 100000;
			b = value / 10000 - a * 10;
			c = value / 1000 - a * 100 - b * 10;
			d = value / 100 - a * 1000 - b * 100 - c * 10;
			e = value / 10 - a * 10000 - b * 1000 - c * 100 - d * 10;
			f = value  - a * 100000 - b * 10000 - c * 1000 - d * 100 - e * 10;

			if (value > answer)
			{
				if (((a > 0) &&  (a == f) && (b == e) && (c == d)) ||
   				  ((a == 0) && (b == f) && (c == e)))
				{						
					answer = value;
					cout << i << "x" << j << "=" << value << endl;
				}
			}
			--j;
		}
		--i;
	}
	return 0;
}
