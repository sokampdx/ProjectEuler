// mathutil.h -- my math utility class

#ifndef MATHUTIL_H_
#define MATHUTIL_H_

template <class T>
class MathUtil {
public:
	MathUtil();
	
	// factor formula
	T gcd(T a, T b);

	// summation formula
	T sumP0(T start, T end);
	T sumP1(T start, T end);
	T sumP2(T start, T end);
}; 


template <class T>
MathUtil<T>::MathUtil() {}

template <class T>
T MathUtil<T>::gcd(T a, T b) {
	if (a == 1)
		return 1;
	if (b == 1)
		return 1;
	
	T temp;
	temp = a % b;
	if (temp == 0)
		return b;

	return gcd(b, temp);
};

template <class T>
T MathUtil<T>::sumP0(T start, T end) {
	return end + 1 - start;
}

template <class T>
T MathUtil<T>::sumP1(T start, T end) {
	return (end + 1 - start) * (end + start) / 2;
}

template <class T>
T MathUtil<T>::sumP2(T start, T end) {
	if (start > 0) {
		return sumP2(0, end) - sumP2(0, start-1);
	} else {
		return end * (end + 1) * (2 * end + 1) / 6;
	}
}

	


#endif
