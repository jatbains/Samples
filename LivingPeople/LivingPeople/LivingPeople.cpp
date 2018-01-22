// LivingPeople.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;




int main()
{
	int birth[] = { 1978,1969,1974,1980,1984,1977,1975,1989,1980 };
	int death[] = { 2001,2005,2010,1981,1996,1997,2011,2012,1985 };
	int tally[200] = { 0 };
	int current = 0;
	int size = sizeof(birth) / sizeof(birth[0]);
	int max = 0;

	for (int i = 0; i < size; i++)
	{
		tally[birth[i] - 1900]++;
		tally[death[i]+1 - 1900]--;

	}

	// Find the max
	for (int i = 0; i < 200; i++)
	{
		current += tally[i];
		if (current > max)
			max = current;
	}

	cout << "Max Population is " << max << endl;

	system("pause");
    return 0;
}

