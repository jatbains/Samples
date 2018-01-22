// SubSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;





int main()
{
	int data[] = { 1,2,4,10,11,7,12,6,7,16,18,19 };
	// Create a hash table
	int hash[20] = { 0 };
	int li = 0, hi = 0;

	int lnum = 0, hnum = 0;
	hi = sizeof(data) / sizeof(data[0]);
	// Populate the hash table

	for (int i = 0; i < hi; i++)
	{
		if (data[i])
		{
			hash[data[i]] = 1;
		}
	}
	// We know the integers present
	// Find the lowest number and highest number
	while (li <= hi-1)
	{
		if (data[li] > data[li+1])
		{
			// found the lowest 
			if (lnum<data[li]) {
				lnum = data[li];
			}
		}
		if (data[hi - 1] > data[hi])
		{
			if (hnum>data[hi]) {
				hnum = data[hi];
			}
		}
		li++;
		hi--;
	}
	// Find the first occurence in the array
	for (int i = 0; i < 20; i++)
	{
		if (hash[i] == 1)
		{
			if (hash[i] == lnum)
				li = i;
			if (hash[i] == hnum)
				hi = i;
		}

	}

	cout << "The two indices are " << li << "  " << hi << endl;


	system("pause");
    return 0;
}

