#include <iostream>
#include <sstream>

using namespace std;

template <class T>
T findMin(T number) {
	T min = 1;
	for (T k = 1; k < number; ++k) {
		min *= 10;
	}
	return min;
}


template <class T>
T findLengthOf(T number) {
	T counter = 0;
	T current = number;

	while (current > 0) {
		current /= 10;
		++counter;
	}
		
	return counter;
}

template <class T>
bool isPalindrome(T number) {
	T count = findLengthOf(number);
	T limit = count / 2;
	bool isValid = true;
	T digit[limit];
	T current = number;
	
	for (T i = 0; i < limit; ++i) {
		digit[i] = current % 10;
		current /= 10;
	}

	if (count % 2 == 1) {
		current /= 10;
	}

	for (T i = (limit-1); i >= 0; --i) {
		isValid &= (digit[i] == (current % 10));
		current /= 10;
	}

	return isValid;
}


template <class T>
T findLargestPalindrome(T number) {
	T min = findMin(number);
	T max = min * 10 - 1;
	T i, j;
	T value, test;

	int largest = 0;

	i = max;
	while (i > min)	{
		j = max;
		test = i * max;
		while (j > min && test > largest) {
			value = i * j;

			if ((value > largest) && isPalindrome(value)) {
				largest = value;
			}
			--j;
		}
		--i;
	}

	return largest;
}


template <class T>
T findSolution(T number) {
	return findLargestPalindrome(number);
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        istringstream ss(argv[1]);
        long long n;
        if (!(ss >> n)) {
            cerr << "Invalid number" << argv[1] << endl;
        } else {
            cout << "The result is = " << findSolution(n) << endl;
        }   
    } else {
        cout << "usage: " << argv[0] << " <input> " << endl;
    }   

    return 0;
}

