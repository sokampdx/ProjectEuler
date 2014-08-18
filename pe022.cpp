#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

// global constant
const int MAX = 6000;
const string FILENAME = "pe022.txt";


// global variable
string nameList[MAX];
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
			cout << line << endl;
			stringstream linestream(line);
			string data;

			getline(linestream, data, ","); 
			nameList[position] = data.substr(1, (unsigned) strlen(data)-2);
			++position;

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


// main program
int main () 
{
	unsigned long long result = 0;	

	readFile();
	printList();	
	cout << "The result = " << result << endl;

	return 0;
}

