#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global constant
const int REGULAR[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int LEAP[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// create date type
typedef struct {
	int year;
	int month;
	int day;
	int dayoftheWeek;	// 1 = Monday
} Date;

// global variable
Date seedDate;

// initialize a seed date
void initialize() {
	seedDate.year = 1900;
	seedDate.month = 1;
	seedDate.day = 1;
	seedDate.dayoftheWeek = 1;
}


// calculate the number of days in a range of year
int calculateDay(int startYear, int endYear) {
	int totalDay = 0;
	int count = 0;
	int dayoftheWeek = ( seedDate.dayoftheWeek + 365 ) % 7 ;

//	if (dayoftheWeek == 0)
//		++count;

	for (int year = startYear; year <= endYear; ++year) {
		for (int month = 1; month <= 12; ++month) {
			if (dayoftheWeek == 0)
				++count;

			if (((year % 400) == 0) || ((year % 4) != 0))
				totalDay = REGULAR[month];
			else
				totalDay = LEAP[month];

			dayoftheWeek = (totalDay + dayoftheWeek) % 7;	
			totalDay = 0;
		}
	}

	//if (dayoftheWeek == 0)
	//	--count;

	return count;
	
}


// main program
int main () 
{
	int result = 0;

	initialize();

	result = calculateDay(1901, 2000);

	cout << "Result = " << result << endl;	

	return 0;
}

