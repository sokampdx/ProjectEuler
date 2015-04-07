
template <class T>

Summation<T>::Summation(T n) {
	this.result = (n * (n + 1)) / 2;
}

T Summation<T>::getResult() const {
	return this.result;
}

