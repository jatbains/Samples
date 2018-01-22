// DuplicateNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int data[] = { 1,2,3,2,1,4 };
	int N = 2;
	int hash[20] = { 0 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		hash[data[i]]++;    // Populate the hash table
	}

	// Know that N items are duplicated  go through the hash and look 
	// for duplicates
	for (int i = 0; i < 20; i++)
	{
		if (hash[i] > 1)
		{
			cout << "Duplicates are " << i << " ";
		}
	}
	cout << endl;


	system("pause");
    return 0;
}

