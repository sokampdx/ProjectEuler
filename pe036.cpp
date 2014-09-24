/* pe36

pick 3 number i, j, k where
1 <= i <= 9
0 <= j,k <= 9

and check the decimal number in these form only
i
ii
iji
ijji
ijkji
ijkkji
*/




#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const unsigned long MAX = 1000000;

bool palindrome[MAX];

void initialize() {
	for (unsigned long i = 0; i < MAX; ++i) {
		palindrome[i] = false;
	}
}


unsigned long decimalToBinary(unsigned long decimal) {
	if (decimal == 0)
		return 0;
	return decimal%2 + 10*decimalToBinary(decimal/2);
} 


int digitLen(unsigned long number) {
	unsigned long current = number;
	int count = 0;
	
	while (current > 0) {
		++count;
		current /= 10;

	}
	return count;
}



bool isPalindrome(unsigned long number) {
	int length = digitLen(number);
	int limit = (length + 1) / 2;
	bool isSame = true;

	for (int i = 1; i <= limit; ++i) {
		unsigned long end = (number / ((unsigned long) pow(10, i-1)))  % 10;
		unsigned long front = (number / ((unsigned long) pow(10, length - i))) % 10;
		isSame = isSame && (front == end);
//		cout << front << ":" << end << endl;
	}
	return isSame;
}


void checkDoublePalindrome() {
	unsigned long Digit[7];
	Digit[0] = 0;

	for (unsigned long i = 1; i <= 9; ++i) {
		for (unsigned long j = 0; j <=9; ++j) {
			for (unsigned long k = 0; k <= 9; ++k) {
				unsigned long ji = j * 10 + i;
				unsigned long kji = k * 100 + ji;
			
				Digit[1] = i;
				Digit[2] = i*10+i;
				Digit[3] = i*100+ji;
				Digit[4] = i*1000+j*100+ji;
				Digit[5] = i*10000+j*1000+kji;
				Digit[6] = i*100000+j*10000+k*1000+kji;

				for (int m = 1; m <=6; ++m) {
					unsigned long current = Digit[m];
					palindrome[current]=isPalindrome(decimalToBinary(current));
				}
			}	
		}
	}
}



unsigned long sumPalindrome() {
	unsigned long result = 0;
	for (unsigned long i = 1; i< MAX; ++i) {
		if (palindrome[i]) {
//			cout << i << ":" << decimalToBinary(i) << endl;
			result += i;
		}
	}

	return result;
}

void printPalindrome() {
	for (unsigned long i = 1; i < MAX; ++i) {
		if (palindrome[i]) {	
			cout << i << ":" << decimalToBinary(i) << endl;
		}
	}
}


int main() {
	unsigned long result = 0;
	initialize();

//	cout << isPalindrome(1001000111000) << endl;


	checkDoublePalindrome();
//	printPalindrome();
	result = sumPalindrome();
	cout << "The result = " << result << endl;

	return 0;
}

