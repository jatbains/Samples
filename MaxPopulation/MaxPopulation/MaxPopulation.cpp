// MaxPopulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int birth[] = {1900,1910,1955,1943,1979,1989,1969,1977};
	int death[] = {1980,1959,1999,2000,2010,2017,2009,2010};
	int born[120] = { 0 };
	int died[120] = { 0 };
	int people = 0;
	int max = 0;
	int size = sizeof(birth) / sizeof(birth[0]);
	// Populate the birth and death's into the hash table
	for (int i = 0; i < size; i++)
	{
		born[birth[i]-1900]++;
		died[death[i]-1900]++;
	}

	// Go through the table and find max population
	for (int i = 0; i < 120; i++)
	{
		if (born[i] > 0) {
			people += born[i];
		}
		if (died[i] > 0)
		{
			people -= died[i];
		}
		if (max < people)
		{
			max = people;
		}
			
	}
	cout << "The maimum population is " << max << endl;

	system("pause");
    return 0;
}


