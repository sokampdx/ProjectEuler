// fibonacci.h -- a fibonacci template

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

template <class T>
class Fibonacci {
public:
	Fibonacci ();
	Fibonacci (T n);
	T getSumOfEvenTerm();

private:
	bool isEven(T n);
	T max;
};

template <class T>
Fibonacci<T>::Fibonacci() {
	max = 0;
}

tempalte <class T>
Fibonacci<T>::Fibonacci(T n) {
	max = n;
}

template <class T>
T Fibonacci<T>::getSumOfEvenTerm() {
	T sum;
	T current, previous, next;

	previous = next = sum = 0;
	current = 1;

	while (next < max) {
		if (isEven(next)) {
			sum += next;
		}

		next = current + previous;
		previous = current;
		current = next;
	}

	return sum;
}

template <class T>
bool Fibonacci<T>::isEven(T n) {
	return !(n % 2);
}
