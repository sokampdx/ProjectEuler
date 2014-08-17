#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

const int LEN = 13; 

// Main program
int main () 
{
	// initialization
	char current = '0';         //current char
	int value = 0;              //current char value
	int currentn = 0;           //current char counting
	char rolling[LEN+1];          //current sequence of char
	long int rollingsum = 1;    //current sequence product
	char product[LEN+1];          //highest sequence of char
	long int high = 1;               //highest sequence product 
	int size = 0;               //line size
	string line;                //input line

    long int result = 1;             //final result
    int userwait;               //for user input

    // initialize the array to '\0'
	for (int i = 0; i <= LEN; i++)
	{
		rolling[i] = '\0';
		product[i] = '\0';
	}

	ifstream myfile ("pe008.txt");    //input file name

	// read file
	if (myfile.is_open())
	{
		while (getline (myfile,line))	
		{
			size = line.size();

			for (int i = 0; i < size; i++)
			{
				current = line[i];
				cout << current << endl;

				// test for current size
				if (current == '0')
				{
					// reset
					currentn = 0;
					rolling[0] = '\0';
                    rollingsum = 1;
					cout << "zero" << endl;
				}
				else if (current > '0' && current <= '9')
				{

					cout << "non Zero" << endl;
					if (currentn >= LEN)
					{
						// rolling LEN
                        rollingsum *= current - '0';
                        rollingsum /= rolling[0] - '0';
						for (int j = 0; j < LEN-1; j++)
							rolling[j] = rolling[j+1];
						rolling[LEN-1] = current;
						rolling[LEN] = '\0';
					}
					else
					{
						// new start
						rolling[currentn] = current;
                        value = current - '0';
                        rollingsum *= value;
						currentn += 1;
						rolling[currentn] = '\0';
						
					}

                    // record highest sum without the 0's
                    if (high < rollingsum)
                    {
                        strcpy (product, rolling);
                        high = rollingsum;
                    }
				}
				else    // error
                	cout << "input error" << endl;
                
                // test output
//                cout << "current n = " << rolling << "; sum = " << rollingsum << endl;
//                cout << "high = " << product << "; sum = " << high << endl;
			} // end for
            
//            cin >> userwait;

		} // end while

		myfile.close();

	} // end if
	else
		cout << "file error" << endl;
		

	// product of the adjacent digit
    for (int i = 0; i < LEN; i++)
    {
        value = product[i] - '0';
        result *= value;
        cout << i << " -----> " << value << " --- " << result << endl;
    }

    cout << "The final result = " << result << endl;


	return 0;
}

