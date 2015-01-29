#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>

typedef int dtype;

using namespace std;

const dtype LIMIT = 9867;
const dtype SQRTLIMIT = 100;
const dtype MIN = 1001;
const dtype MAX = 9999;
const int SIZE = 4;
const int PERMSIZE = 24;
const int ANSSIZE = 3;

bool prime[LIMIT];

int constIndex[PERMSIZE][SIZE];
dtype permutate[PERMSIZE];
dtype answer[ANSSIZE];

void initPerm() {
	for (int i = 0; i < PERMSIZE; ++i) {
		permutate[i] = 0;
	}
}

void initAnswer() {
	for (int i = 0; i < ANSSIZE; ++i) 
		answer[i] = 0;
}


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

dtype nextPermutation(dtype number) {
	int perm[SIZE];
	dtype temp = number;


	// if number = 1023456789
	// perm[] = {9,8,7,6,5,4,3,2,0,1}
	for (int k = 0; k < SIZE; ++k) {
		perm[k] = (int) (temp % 10);
		temp /= 10;
	}
//cout << "-1-" << endl;
	// find the largest index i such that ai < ai-1 but ai-1 > ai-2 ... a0
	int i = 1;
	bool isIncreasing = true;
	while (i < SIZE-1 && isIncreasing)  {
		if (perm[i] > perm[i-1]) {
			++i;
		} else {
			isIncreasing = false;
		}
	}
//cout << "-2-" << endl;
	
	// find index j with min aj such that ai < aj and 0 <= j < i
	long nextMin = 10;
	int j;
	for (int k = 0; k < i; ++k) {
		if (perm[k] > perm[i] && perm[k] < nextMin) {
			j = k;
			nextMin = perm[j];
		}
	}
//cout << "-3-" << endl;

	// swap i and j
	int digit = perm[i];
	perm[i] = perm[j];
	perm[j] = digit;	
//cout << "-4-" << endl;

	// reverse ai+1 to an
	int limit = i - 1;
	int max = i /2;
	for (int k = 0; k < max; ++k) {
		digit = perm[k];
		perm[k] = perm[limit - k];
		perm[limit - k] = digit;
	}
//cout << "-5-" << endl;

	temp = 0;
	for (int k = SIZE-1; k >= 0; --k) {
		temp = (temp * 10) + (long) perm[k];
	}

	return temp;
}	

	
void createPerm(dtype number) {
	int digit[SIZE];
	dtype current = number;

	for (int i = 0; i < SIZE; ++i) {
		digit[i] = current % 10;
		current /= 10;
	}

	for (int i = 0; i < PERMSIZE; ++i) {
		if (digit[constIndex[i][0]] && digit[constIndex[i][3]] % 2) {
			permutate[i] = digit[constIndex[i][0]]*1000 + 
							digit[constIndex[i][1]]*100 +
							digit[constIndex[i][2]]*10 +
							digit[constIndex[i][3]]; 
		} else {
			permutate[i] = 0;
		}
	}

}


void printPerm() {
	for (int i = 0; i < PERMSIZE; ++i)
		cout << permutate[i] << endl;
}

void printAnswer() {
	for (int i = 0; i < ANSSIZE; ++i)
		cout << answer[i];
	cout << endl;
}


void initIndex() {
	int number = 123;
	int current = number;	

	for (int i = 0; i < PERMSIZE; ++i) {
		int temp = current;
	//	cout << temp << endl;
		for (int j = 0; j < SIZE; ++j) {
			constIndex[i][j] = temp % 10;
			temp /= 10;
		}
		current = nextPermutation(current);
	}
}


void printIndex() {
	for (int i = 0; i < PERMSIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << constIndex[i][j];
		}
		cout << endl;
	}
}

void checkPermPrime() {
	for (int i = 0; i < PERMSIZE; ++i) {
		if (!isPrime(permutate[i])) {
			permutate[i] = 0;
		}
	}
}



void uniquePerm() {
	for (int i = 0; i < PERMSIZE-1; ++i) {
		dtype current = permutate[i];
		if (current) {
			for (int j = i+1; j < PERMSIZE; ++j) {
				dtype value = permutate[j];
				if (!value || value == current)
					permutate[j] = 0;
			}
		}
	}
}
		

void compactPerm() {
	int index = PERMSIZE-1;
	int i = 0;
	while (i < index) {
		if (!permutate[i]) {
			while (!permutate[index] && i < index)
				--index;
			permutate[i] = permutate[index];
			permutate[index] = 0;
			--index;
		}
		++i;
	}
}

int numCandidate() {
	int count = 0;
	for (int i = 0; i < PERMSIZE; ++i) {
		if (permutate[i])
			++count;
	}

	return count;
}

void sortPerm() {
	int nprime = numCandidate();
	
	for (int i = 0; i < nprime - 1; ++i) {
		for (int j = i+1; j < nprime; ++j) {
			if (permutate[i] > permutate[j]) {
				dtype temp = permutate[i];
				permutate[i] = permutate[j];
				permutate[j] = temp;
			}
		}
	}
}

void markVisited() {
	int nprime = numCandidate();

	for (int i = 0; i < nprime; ++i) {
		prime[permutate[i]] = false;
	}
}

 
bool foundAnswer() {
	bool found = false;
	checkPermPrime();
	uniquePerm();
	compactPerm();
	sortPerm();
	int nprime = numCandidate();

	

	int i, j, k = 0;
	dtype d1, d2 = 0;

	for (i = 0; i < nprime-2; ++i) {
		for (j = i+1; j < nprime-1; ++j) {
			d1 = abs(permutate[i] - permutate[j]);
			for (k = j+1; k < nprime; ++k) {
				d2 = abs(permutate[j] - permutate[k]);
				if (d1 == d2 && d1 && d2)  {
					answer[0] = permutate[i];
					answer[1] = permutate[j];
					answer[2] = permutate[k];
					found = true;
				}
			}
		}
	}

	return found;	
}



void findPrimePerm() {
	initIndex();

	for (dtype i = MIN; i <= MAX; i+=2) {
		if(isPrime(i)) {
			initPerm();
			initAnswer();
			createPerm(i);
			if (foundAnswer()) {
				printAnswer();
			}
			markVisited();
		}
	}		
}


void test() {
	dtype x = 1478;
	initPerm();
	initAnswer();
	initIndex();
	createPerm(x);
	printPerm();
	cout << "--------------------" << endl;
	cout << foundAnswer() << endl;
	cout << "--------------------" << endl;
	printPerm();
	cout << "--------------------" << endl;
	printAnswer();
	
}


int main () 
{
	dtype result = 0;

	initialize();
	primeSieve();
	//printPrime();
	//printIndex();

	//test();

	cout << "The result is: "  << endl;
	findPrimePerm();	

	return 0;
}

