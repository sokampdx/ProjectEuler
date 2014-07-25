#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// global constant
const int DAYINYEAR = 365;
const int LEAPYEAR = 366;

// create date type
typedef struct {
	int year;
	int month;
	int day;
	int dayoftheWeek;	// 0 = Sunday
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

	for (int i = startYear; i <= endYear; ++i) {
		if (((i % 400) == 0) || ((i % 4) != 0))
			totalDay += DAYINYEAR;
		else
			totalDay += LEAPYEAR;
	}
	return totalDay;
	
}

// find 1/1/year day of the week using seed
int findDayoftheWeek(int year) {
	int numDay = 0;
	int result = 0;

	numDay = calculateDay(seedDate.year, year);


// main program
int main () 
{
	int result = 0;
	int startDayoftheWeek = 0;
	int numDay = 0;

	initialize();

	numDay = calculateDay(1901, 2000);
	startDayoftheWeek = findDayoftheWeek(1901);
	
	cout << "Number of days = " << numDay << endl;
	cout << "Result = " << result << endl;	

	return 0;
}

