// FindSumNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// Find two numbers in Array that sum to N

int main()
{
	int data[] = { 2,5,7,8,10,15,21,22 };
	int hash[25] = { 0 };
	int N = 0,y=0;
	int size = sizeof(data) / sizeof(data[0]);
	// We know that the sum of two is N
	// Therefore data[i]-N will also be in array;
	// Create hash table of values and set to true when we see 
	// that number 
	cout << "Enter a sum to find " << endl;
	cin >> N;


	for (int i = 0; i < size-1; i++)
	{
		// Check the difference if in table
		if (hash[data[i]] == 1)
		{
			y = data[i];
			break;
		}
		hash[N - data[i]] = 1;
	}

	cout << "Value found is " << y << endl;


	system("pause");
    return 0;
}

