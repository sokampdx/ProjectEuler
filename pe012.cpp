#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100000;
const int LIMIT = 500;


// check perfect square
int perfect_root(int value)
{
    if (value <= 0)
        return 0;
    if (value == 1)
        return 1;

    int check = (int)(sqrt(value));
    if (check * check == value)
        return check;

    return 0;
}




// Count divisor
int count_div(int value)
{
    int root = (int)(sqrt(value));
    int divisor = 2;

    if (value == 0)
        return 0;
    if (value == 1)
        return 1;
    if (value == 2)
        return 2;

    for (int i = 2; i <= root; ++i)
    {
        if ((value % i) == 0)
            divisor += 2;
    }

    if ((root * root) == value)
        divisor -= 1;
    
    return divisor;
}




// triangle divisor program
int triangle_divisor()
{

    int divisor = 0;
    int triangle = 0;
    int count = 0;


    while (divisor <= LIMIT)
    {
        count += 1;
        triangle += count;
        divisor = count_div(triangle);
        cout << count << " : " << triangle << " : " << divisor << endl;

    } // end while


    return divisor;
}


// main program
int main()
{
    triangle_divisor();



/*
    int test = 4;
   
    cout << "Test perfect_root function" << endl; 
    test = 4;
    cout << test << " : " << perfect_root(test) << endl;
    cout << test << " : " << count_div(test) << endl;
    test = 1;
    cout << test << " : " << perfect_root(test) << endl;
    cout << test << " : " << count_div(test) << endl;
    test = 0;
    cout << test << " : " << perfect_root(test) << endl;
    cout << test << " : " << count_div(test) << endl;
    test = 25;
    cout << test << " : " << perfect_root(test) << endl;
    cout << test << " : " << count_div(test) << endl;
    test = 1000;
    cout << test << " : " << perfect_root(test) << endl;
    cout << test << " : " << count_div(test) << endl;
    test = 121;
    cout << test << " : " << perfect_root(test) << endl;
    cout << test << " : " << count_div(test) << endl;
*/

    return 0;
}


