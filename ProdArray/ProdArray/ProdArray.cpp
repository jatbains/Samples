// ProdArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;





int main()
{
	int val[] = { 3,1,4,2 };
	int hash[10] = { 0 };
	int size = sizeof(val) / sizeof(val[0]);
	int *result = new int[size];
	int product = 1;
	// Populate the hash array
	for (int i = 0; i < size; i++)
	{
		if (i != val[i])
		{
			product *= val[i];
			hash[val[i]]++;
		}
	}
	// Hash Array has all values that are not indexes 
	// Run through the hash table and multply to get values for new array
	int left = 0;
	int right = sizeof(hash) / sizeof(hash[0]) - 1;
	int i = 0;
	int j = 0;
	// Divide to get values
	for (int i = 0; i < 10; i++)
	{
		if (hash[i] != 0)
		{
			result[j] = product / i;
			j++;
		}
	}

	
	// result is 
	for (int i = 0; i < size; i++)
	{
		cout << result[i] << endl;
	}

	system("pause");
    return 0;
}

