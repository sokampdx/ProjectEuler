// prime.h -- a prime template

#ifndef PRIME_H_
#define PRIME_H_

template <class T>
class Prime {
public:
	Prime (T maximum);
	T getLargestFactor(T number)

private:
	T findLimit(T number);
	void init();
	void sieve();
	bool isDivisor(divideBy, divideFrom);

	T max;
	bool * prime;	
};

template <class T>
Prime<T>::Prime(T maximum) {
	max = maximum;
	prime = new bool [maximum];
	init();
	sieve();
}

template <class T>
T get LargestFactor(T number) {
	T result = 0;
	T current = findLimit(number);
	T end = 3;
	bool isFound = false;

	if (current % 2 == 0) {
		++current;
	}

	while ((current >= end) && (!isFound)) {
		if (isDivisor(current, number)) {
			isFound = true;
			result = current;
		}
		current -= 2;
	}

	return 	result;
}

template <class T>
bool isDivisor(T divideBy, T divideFrom) {
	return divideFrom % divideBy == 0;
}

template <class T>
void init() {
	for (T i = 0; i < max; ++i) {
		prime[i] = false;
	}
}

template <class T>
void sieve() {
	T limit = findLimit(max);

	for (T i = 3; i < limit; i+=2) {
		if (isPrime(i)) {
			setNonPrimeForMulOf(i);
		}
	}
}


template <class T>
T findLimit(T number) {
	return (T) sqrt ((double) number);
}

#endif
