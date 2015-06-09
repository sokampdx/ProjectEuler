// mathutil.h -- my math utility class

#ifndef MATHUTIL_H_
#define MATHUTIL_H_

template <class T>
class MathUtil {
public:
	MathUtil();
	
	T gcd(T a, T b);
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


#endif
