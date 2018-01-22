// SumOfSquares.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>

using namespace std;
void SumOfSquares(int num);

int main()
{
	int num = 0;
	cout << "Enter a number" << endl;
	cin >> num;

	SumOfSquares(num);



	system("pause");
    return 0;
}

void SumOfSquares(int num)
{
	int diff = 0;
	bool sqTable[100] = { false};  // Upto 10 squared
	// Trial and error and create a hash table  
	// start with a table of squares and then do a lookup for the difference
	//  easier than computing everyting on the fly
	for (int i = 0; i < 10; i++)
	{
		sqTable[i*i] = true;
	}
	// Try decomposing um
	for (int i = 0; i < 10; i++)
	{
		if (sqTable[i])
		{
			diff = num - i;     // Difference
			if (sqTable[diff])  // If this is found then we found the numbers
			{
				cout << "Numbers are " << i << " And " << diff << endl;
				return;
			}
		}
	}
	cout << "Numbers not found" << endl;
}
