#include <iostream> 
 
using namespace std; 
 
int main() 
{ 
   int N = 1000; 
   int i, j, k; 
   int sum = 0; 
    
   // Use summation from 1 to N 
   // O(1) 
   i = ((N - 1) / 3); 
   j = ((N - 1) / 5); 
   k = ((N - 1) / 15); 
    
   sum = sum + (3 * ((i + 1) * i / 2)); 
   sum = sum + (5 * ((j + 1) * j / 2)); 
   sum = sum - (15 * ((k + 1) * k / 2)); 
    
   cout << endl << "The result = " << sum << endl; 
 
 
   //brute force algorithm 
   //O(n) 
   sum = 0;      
   for (i = 1; i < N; i++) 
     if (!(i % 3) || !(i % 5)) 
       sum = sum + i; 
 
   cout << endl << "The result = " << sum << endl; 
    
   return 0; 
} 
 
 
