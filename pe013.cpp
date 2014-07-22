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
 
// global array
string number[MAX];


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

// calculate fix string sum
void stringSum(string& result, int current) {
	int value = 0;

	for (int i = 0; i < MAX; ++i) {
		value += stoi(number[i].substr(current, 1));
	}

	cout << value << endl;
	result = to_string(value);
}

// calculate vary string sum
string string2Sum(string previous, string current) {
	int pSize = previous.size();
	int cSize = current.size();
	int limit = max(pSize - 1, cSize);
	int pValue, cValue, value;
	int carry = 0;
	string result = "0";

	for (int i = 0; i < limit; ++i) {
		if (i < (pSize - 1))
			pValue = stoi(previous.substr(pSize - i - 1, 1));
		else
			pValue = 0;
		if (i < cSize)
			cValue = stoi(current.substr(cSize - i, 1));
		else
			cValue = 0;

		value = pValue + cValue + carry;
		carry = 0;

		if (value > 9) {
			carry = value / 10;
		}			
		result.insert(0, to_string(value % 10));			
	}

	return result;
}


// print result
void printResult () {
	string previous="12340";
	string current="9876";
	string result="0";

/*	
	for (int i = (LEN - 1); i >= (LEN - 1); --i) {
		stringSum(current, LEN-1);
		result = string2Sum(previous, current);
		previous = current;
		current = result;
	}
*/

	result = string2Sum(previous, current);

	cout << "The final result is: " << endl;
	cout << result << endl;
}




// Main program
int main () 
{
	readfile("pe013.txt");
	printNumber();
	printResult();
	return 0;
}

