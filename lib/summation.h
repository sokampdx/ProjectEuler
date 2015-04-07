// summation.h -- a summation template

#ifndef SUMMATION_H_
#define SUMMATION_H_

template <class T>
class Summation {
public:
	Summation ();
	Summation (T n);
	T getResult();
	void setResult(T n);

private:
	T result;
};


template <class T>
Summation<T>::Summation() {
	result = 0;
}

template <class T>
Summation<T>::Summation(T n) {
	setResult(n);
}

template <class T>
T Summation<T>::getResult() {
	return result;
}

template <class T>
void Summation<T>::setResult(T n) {
	result = (n * (n + 1)) / 2;
}


#endif

	
