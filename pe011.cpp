#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const int LEN = 4; 
const int SIZE = 20;
const int MAX = 256;
const int LIMIT = SIZE - LEN + 1;

// Main program
int main () 
{
	// initialization
    long int result = 1;  
    long int vsum[SIZE];
    long int hsum[SIZE];
    long int fsum[SIZE];
    long int bsum[SIZE];  
    long int test = 1;
    int value[SIZE][SIZE];

    int current = 0;
    int row = 0;
    int col = 0;


    string line;
	ifstream myfile ("pe011.txt");    //input file name

    // init sum
    for (int i = 0; i < SIZE; ++i)
    {
        vsum[i] = 1;
        hsum[i] = 1;
        fsum[i] = 1;
        bsum[i] = 1;
    }



	// read file
	if (myfile.is_open())
	{
        row = 0;
		while (getline(myfile,line))	
		{
            // read line
            cout << line << endl;

            for (int i = 0; i < SIZE; ++i)
            {
                current = i * 3;
                value[row][i] = (line[current] - '0') * 10 + (line[current+1] - '0');
            }
            row +=1;

		} // end while

		myfile.close();

	} // end if
	else
		cout << "file error" << endl;
		

    // loop
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < LIMIT; ++j)
        {
            for (int k = 0; k < LEN; ++k)
                test *= value[i][j+k];
            if (result < test)
                result = test;
            test = 1;
        }
    }

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < LIMIT; ++j)
        {
            for (int k = 0; k < LEN; ++k)
                test *= value[j+k][i];
            if (result < test)
                result = test;
            test = 1;
        }
    }

    for (int i = 0; i < LIMIT; ++i)
    {
        for (int j = 0; j < LIMIT; ++j)
        {
            for (int k = 0; k < LEN; ++k)
                test *= value[i+k][j+k];
            if (result < test)
                result = test;
            test = 1;
        }
    }

    for (int i = LEN; i < SIZE; ++i)
    {
        for (int j = 0; j < LIMIT; ++j)
        {
            for (int k = 0; k < LEN; ++k)
                test *= value[i-k][j+k];
            if (result < test)
                result = test;
            test = 1;
        }
    }



/*

    for (int k = 0; k < SIZE; ++k)
    {
        if (result < max(hsum[k], vsum[k], fsum[k], bsum[k]))
            result = max(hsum[k], vsum[k], fsum[k], bsum[k]);
    }
*/
    




	// product of the adjacent digit

    cout << "The final result = " << result << endl;


	return 0;
}

