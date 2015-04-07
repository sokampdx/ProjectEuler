// summation.h -- a summation template

#ifndef SUMMATION_H_
#define SUMMATION_H_

template <class T>
class Summation {
public:
	Summation (T n);
	T getResult();

private:
	T result;
};


template <class T>
Summation<T>::Summation(T n) {
	result = (n * (n + 1)) / 2;
}

template <class T>
T Summation<T>::getResult() {
	return result;
}

#endif

	
