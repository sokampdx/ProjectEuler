#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global const
const int MAX = 100;
const int LEN = 50;
const int FINAL = 10; 

// global array
string number[MAX];
string subTotal[LEN];

// readfile into global number array
void readfile (string filename) {
	ifstream myfile(filename);
	string line;
	int i = 0;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			if (i < MAX) {
				number[i++] = line;
			}
		}
	}
}

// print number array
void printNumber () {
	for (int i = 0; i < MAX; ++i) {
		cout << number[i] << endl;
	}
}

// print subtotal array
void printSubTotal() {
	for (int i = (LEN - 1); i >= 0; --i) {
		cout << subTotal[i] << endl;
	}
}

// calculate fix string sum
string  addColumn(int index) {
	int value = 0;

	for (int i = 0; i < MAX; ++i) {
		value += stoi(number[i].substr(index, 1));
	}

	cout << value << endl;
	return to_string(value);
}

// modify the sub total array
void  modifySubTotal() {
	for (int i = (LEN - 1); i > 0; --i) {
		subTotal[i-1] = to_string(stoi(subTotal[i-1]) + (stoi(subTotal[i]) / 10));
	}
}

// get sub Total of each column 
void getSubTotal() {

	string result="0";

	for (int i = (LEN - 1); i >= 0; --i) {
		subTotal[i] = addColumn(i);
	}
}

// create result string
string getResult() {
    string result;
	int pos = subTotal[0].size();
    int limit = FINAL - pos;

	result.append(subTotal[0]);
	
	for (int i = 1; i <= limit; ++i) {
		pos = subTotal[i].size();
		result.append(subTotal[i].substr(pos-1,1));
	}

	return result;
}


// Main program
int main () 
{
	readfile("pe013.txt");
	printNumber();
	getSubTotal();
	printSubTotal();
	modifySubTotal();
	printSubTotal();

	cout << "The result is: " << getResult() << endl;

	return 0;
}

