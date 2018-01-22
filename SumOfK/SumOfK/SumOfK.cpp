// SumOfK.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int data[] = { 3,24,5,33,17,21,57,43,12 };
	// Find two numbers so sum is a multiple of k ie.  n*k
	// Or this means sum%n == 0
	int hash[100] = { 0 };
	int size = sizeof(data) / sizeof(data[0]);
	int sum = 0;
	int n = 0;
	int y = 0;
	cout << "Enter the sum " << endl;
	cin >> sum;
	cout << "Enter multiplier " << endl;
	cin >> n;

	for (int i = 0; i < size; i++)
	{
		if (hash[data[i]] == 1)
		{
			y = data[i];
			break;
		}
		
		hash[n*sum-data[i]] = 1;
	}

	cout << "Y is " << y << endl;

	system("pause");
    return 0;
}

