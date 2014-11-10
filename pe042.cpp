#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

// global constant
const int MAX = 2000;
const int NUM = 40;
const string FILENAME = "pe042.txt";
const char DELIMITER = ',';

// global variable
string nameList[MAX];
int triangle[NUM];
int size;

// read file
int readFile() {
	int isValid = 1;
	int position = 0;
	string line;
	ifstream myfile (FILENAME);

	// read file
	if (myfile.is_open())	{
		while (getline(myfile,line))	{		
   		// read line
			stringstream linestream(line);
			string data;

			while(getline(linestream, data, DELIMITER)) {	 
				nameList[position] = data.substr(1, data.length()-2);
				++position;
			}
		} // end while
		size = position;
		myfile.close();
	} else {
		cout << "File Read Error" << endl;
		isValid = 0;
	}
	
	return isValid;
}


// print name list
void printList() {
	for (int i = 0; i < size; ++i) {
		cout << nameList[i] << endl;
	}
}

// calculate triangle number
void calculateTriangle() {
	for (int i = 0; i < NUM; ++i) {
		triangle[i] = i*(i+1) / 2;
	}
}

// print triangle number list
void printTriangle() {
	for (int i = 0; i < NUM; ++i) {
		cout << triangle[i] << endl;
	}
}

// get the word score
int score(string word) {
	int total = 0;
	int limit = word.length();

	for (int i = 0; i < limit; ++i) {
		total += (word[i] -'A' + 1);
	}
	return total;
}



// count the number of triangle word
int countTriangleWord() {
	int count = 0;
	int j = 0;
	for (int i = 0; i < size; ++i) {
		int value = score(nameList[i]);
		j = 0;
		while (value >= triangle[j]) {
			if (value == triangle[j])
				++ count;
			++j;
		}
	}
	return count;
}


// main program
int main () 
{
	int result = 0;	
	readFile();
//	printList();
	calculateTriangle();
//	printTriangle();

	result = countTriangleWord();
	
	cout << "The result = " << result << endl;

	return 0;
}

