#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

typedef int dtype;

using namespace std;

const dtype LIMIT = 1000000;
const dtype SQRTLIMIT = (dtype) sqrt(LIMIT) + 1;
const dtype MAX = LIMIT / 2 + 1;

bool prime[LIMIT];


void initialize() {
	for (dtype i = 0; i < LIMIT; ++i) {
		prime[i] = true;
	}
	prime[0] = false;
	prime[1] = false;

	for (dtype i = 4; i < LIMIT; i+=2)
		prime[i] = false;

}


void primeSieve() {
	for (dtype i = 3; i < SQRTLIMIT; i+=2) {
		if (prime[i]) {
			for (dtype j = (i+i); j < LIMIT; j+=i)
				prime[j] = false;
		}
	}
}


bool isPrime(dtype number) {
	return prime[number];
}


void printPrime() {
	cout << 2 << endl;
	for (dtype i = 3; i < LIMIT; i+=2) {
		if (prime[i])
			cout << i << endl;
	}
}

dtype nextPrimeAbove(dtype number) {
	if (number == 2)
		return 3;

	dtype value = number + 2;
	while (!isPrime(value))
		value += 2;
	return value;
}

dtype nextPrimeBelow(dtype number) {
	if (number == 3)
		return 2;

	dtype value = number - 2;
	while (!isPrime(value))
		value -= 2;
	return value;
}


dtype sumPrime (dtype start, dtype end) {
	dtype sum = 0;

	for (dtype i = start; i <= end; i=nextPrimeAbove(i)) {
		sum += i;
	}

	return sum;
}


dtype findConsecutive() {
	dtype start = 2;
	dtype end = start;
	dtype i = nextPrimeAbove(start);
	dtype sum = start;
	int count = 1;
	int maxCount = count;
	dtype maxStart = start;
	dtype maxEnd = end;
	dtype maxSum = sum;

	while (start < MAX) {
		sum += i;
		end = i;
		++count;
//cout << "3: maxCount:" << maxCount << ":maxStart:" << maxStart << ":maxEnd:" << maxEnd << endl;
//cout << "1: i:" << i << ":sum:" << sum << ":start:" << start << ":end:" << end << ":count:" << count << endl;	

		if (sum < LIMIT) { 
			if (isPrime(sum) && maxCount < count) {
				maxCount = count;
				maxStart = start;
				maxEnd = end;
				maxSum = sum;
			}
			i = nextPrimeAbove(i);
		} else {
			start = nextPrimeAbove(start);
			end = start;
			sum = start;
			i = nextPrimeAbove(start);
			count = 1;
		}
	}
	
	return sumPrime(maxStart, maxEnd);
}




void test() {
	dtype i = findConsecutive();
	

}	


int main () 
{
	dtype result = 0;

	initialize();
	primeSieve();
	//printPrime();

	//test();

	result = findConsecutive();
	cout << "The result is: "  << result << endl;


	return 0;
}

