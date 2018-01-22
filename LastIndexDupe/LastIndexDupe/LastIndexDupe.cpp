// LastIndexDupe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int BinarySearch(int data[], int size);
void RecurBinarySearch(int data[], int lval, int rVal, int *last);

int main()
{
	int data[] = { 1,3,6,6,8,9,12,12,15,19 };
	int size = sizeof(data) / sizeof(data[0]);
	int lastindex = 0;
	int lastnum = 0;
	int mid = 0;

	lastnum = data[0];

	// Linear Search O(n)

	for (int i = 1; i < size; i++)
	{
		if (lastnum == data[i])
		{
			lastindex = i;
		}
		lastnum = data[i];
	}

	cout << "Last Index is " << lastindex << endl;

	// Binary search
	cout << "Last Index is " << BinarySearch(data, size) << endl;

	system("pause");
    return 0;
}

int BinarySearch(int data[], int size)
{
	int lastIndex = 0;
	int tIndex = 0;
	

	// Do a binary search on the array
	 RecurBinarySearch(data, 0, size, &lastIndex);
	 return lastIndex;
}

void RecurBinarySearch(int data[], int lval, int rVal, int *lastIndex)
{
	if (lval != rVal)
	{
		if (data[lval] - data[rVal] == 0)
		{
			// found the index
			*lastIndex = rVal;
		}
		// Search the array
		int mid = (lval + rVal) / 2;
		// Search left side and then right
		RecurBinarySearch(data, lval, mid, lastIndex);
		RecurBinarySearch(data, mid+1, rVal, lastIndex);
	}
}