// Population.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void LifeSpan(int bd[], int dd[], int ls[]);
void TimeSpan(int bd[], int dd[], int *max, int *least);

int main()
{
	int bd[10] = { 1969,1973,1954,1978,1982,1977,1988,1975,1978,1980 };
	int dd[10] = { 1999,2001,1995,2003,2010,1999,2008,2000,1997,2007 };
	int ls[10] = { 0 };
	int maxPop = 0;
	int intPop = 0;
	int maxYears = 0;
	int lowest, maximum;

	cout << "This Program finds when the maximum population existed" << endl;
	// How to solve this hash table or searching
	// Calculate Life span of each person
	LifeSpan(bd, dd, ls);
	TimeSpan(bd, dd, &maximum, &lowest);
	// Create a new Array with mamimum and mimimum values
	// Then Populate that new array with deltas 
	// Finally count the deltas to see when the value is the greatest
	// Determine when there is overlap between people
	// Overlap occurs when the bd and ls of a person is inbetween that of another
	// When we have maximum overlap that is maximum population
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i != j) 
			{
				if (bd[j] <= (bd[i] + ls[i]) <= dd[j])
				{
					intPop++;
				}
			}

		}
		if (intPop > maxPop)
		{
			maxPop = intPop;
		}
	}
	cout << "The Maximum Population is " << maxPop << endl;

	getchar();
	
    return 0;
}

void LifeSpan(int bd[], int dd[], int ls[])
{
	for (int i = 0; i < 10; i++)
	{
		ls[i] = dd[i] - bd[i];
		cout << "The lifespans are " << ls[i] << endl;
	}
}
void TimeSpan(int bd[], int dd[], int *max,int *least)
{
	

	for (int i = 0; i < 10; i++)
	{
		if (*least < bd[i])
			*least = bd[i];
		if (dd[i] > *max)
			*max = dd[i];
	}
}
