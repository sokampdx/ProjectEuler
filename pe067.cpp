#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

// global constant
const int SIZE = 100;
const string FILENAME = "pe067.txt";


// global variable
unsigned int result[SIZE][SIZE];
unsigned int source[SIZE][SIZE];

// initialize array
void initializeArray(unsigned int array[][SIZE], int size) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			array[i][j] = 0;
}

// read file
int readFile() {
	int isValid = 1;
	int row;
	int current;
	string line;
	ifstream myfile (FILENAME);

	// read file
	if (myfile.is_open())
	{
        row = 0;
		while (getline(myfile,line))	
		{
            // read line
            cout << line << endl;

            for (int i = 0; i <= row; ++i)
            {
                current = i * 3;
				source[row][i] = (line[current] - '0') * 10 + (line[current+1] - '0');
            }
            row +=1;

		} // end while

		myfile.close();
	} else {
		cout << "File Read Error" << endl;
		isValid = 0;
	}
	
	return isValid;
}

// print array
void printArray(unsigned int array[][SIZE], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j <= i; ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

// recursive sum
unsigned int sum(unsigned int array[][SIZE], int row, int col, int size) {
	if (result[row][col] > 0)
		return result[row][col];
	if (row == (size - 1))
		return result[row][col] = array[row][col];
	return result[row][col] = array[row][col] + max(sum(array, row+1, col, size), sum(array, row+1, col+1, size));
		
}

// find Max Sum
unsigned int findMaxSum(unsigned int array[][SIZE], int size) {

	return sum(array, 0, 0, size);
}

// main program
int main () 
{

	unsigned int sum = 0;

	readFile();
	printArray(source, SIZE);
	initializeArray(result, SIZE);	
//	printArray(result, SIZE);

	sum = findMaxSum(source, SIZE);
	
	cout << "The result = " << sum << endl;

	return 0;
}

