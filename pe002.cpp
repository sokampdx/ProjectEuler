#include <iostream> 
 
using namespace std; 
 
const unsigned int MAX = 4000000; 
 
int main() 
{ 
    unsigned int sum;                        // curmutive sum 
    unsigned int current, previous, next;    // Fibonacci number 
     
    // initialize 
    previous = next = sum = 0; 
    current = 1; 
 
    while (next < MAX) 
    { 
        // add even-term to sum 
        if (!(next % 2)) 
            sum += next; 
         
        // increment fibonacci numbers 
        next = current + previous; 
        previous = current; 
        current = next; 
    } 
     
    // print result 
    cout << sum << endl; 
    
    return 0; 
} 
 
 
