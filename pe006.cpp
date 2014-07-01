#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	unsigned int n = 100;
	
	unsigned int result;

	result = (n + 1) * n / 2; 
	result = result - ( (2 * n + 1) / 3) ;
	result = result * ((n + 1) * n / 2 );

	cout << result << endl;
	return 0;
}
