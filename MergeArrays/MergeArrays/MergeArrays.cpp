// MergeArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;


int main()
{
	int a1[20] = { 3,5,8,11,13,18,23 };
	int b1[] = {1, 4, 9, 15, 17};
	bool hash[100] = { 0 };
	int asize = sizeof(a1) / sizeof(a1[0]);
	int bsize = sizeof(b1) / sizeof(b1[0]);
	// Merge b1 into a1

	// Use a hash table
	// Go through a1 and b1 and turn on bool in hash table
	for (int i = 0; i < asize; i++)
	{
		hash[a1[i]] = true;
	}
	// Same for or b1
	for (int i = 0; i < bsize; i++) {
		hash[b1[i]] = true;
	}
	// Go through has table and set values in a1
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (hash[i] == true)
		{
			a1[count] = i;
			count++;
		}
	}

	// Print out a1 now
	for (int i = 0; i < asize; i++)
	{
		cout << a1[i] << endl;
	}

	system("pause");
    return 0;
}

