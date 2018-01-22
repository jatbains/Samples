// KthFrequent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[] = { 1,2,3,2,1,2,2,2,3,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 2;

	int hash[10] = { 0 };

	for (int i = 0; i < size; i++)
	{
		hash[arr[i]]++;
	}

	// Process the table
	for (int i = 0; i < 10; i++)
	{
		if (k == hash[i])
		{
			cout << "Number is " << i << endl;
		}
	}

	system("pause");
    return 0;
}

