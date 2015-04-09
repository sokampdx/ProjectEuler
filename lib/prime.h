// prime.h -- a prime template

#ifndef PRIME_H_
#define PRIME_H_

template <class T>
class Prime {
public:
	Prime();
	Prime(T maximum);

private:
	T findLimit(T number);
	void setNonPrimeForMultipleOf(T number);
	void init();
	void sieve();

	T max;
	bool * prime;	
};


template <class T>
Prime<T>::Prime() {
	max = 0;
	prime = NULL;
}



template <class T>
Prime<T>::Prime(T maximum) {
	max = maximum;
	prime = new bool [maximum];
	init();
	sieve();
}


template <class T>
Prime<T>::~Prime() {
	if (prime) {
		delete[] prime;
	}
}


template <class T>
void Prime<T>::init() {
	for (T i = 0; i < max; ++i) {
		prime[i] = true;
	}

	prime[0] = prime[1] = false;
}

template <class T>
void Prime<T>::sieve() {
	T limit = findLimit(max);

	for (T i = 3; i < limit; i+=2) {
		if (prime[i]) {
			setNonPrimeForMultipleOf(i);
		}
	}
}

template <class T>
void Prime<T>::setNonPrimeForMultipleOf(T number) {
	for (T i = (number + number); i < max; i += number) {
		prime[i] = false;
	}
}

template <class T>
T Prime<T>::findLimit(T number) {
	return (T) sqrt ((double) number);
}

#endif
