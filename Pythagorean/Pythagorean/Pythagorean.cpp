// Pythagorean.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// Given an array we want to find if elements form a pythagorean triplet

int main()
{
	int data[] = {1,3,7,9,4,12,5 };  // Here we have 5,4,3 
	int hash[20] = { 0 };
	int x = 0, y = 0, z = 0;
	bool xf = false, yf = false, zf = false;
	int size = sizeof(data) / sizeof(data[0]);
	int hashSize = sizeof(hash) / sizeof(hash[0]);
	// One way would be to sort it first  and then go through the list
	// Put elements into hash

	for (int i = 0; i < size; i++)
	{
		hash[data[i]] = 1;  // Unique elements
	}
	// Go through hash we know that it will be in increasing order
	for (int i = 0; i < hashSize - 2; i++)
	{
		if (hash[i] == 1)
		{
			cout << i << endl;
			if (!xf)
			{
				x = i;
				xf = true;
			}

			else if (!yf)
			{
				y = i;
				yf = true;
			}
				
			else if (!zf)
			{
				z = i;
				zf = true;
			}
			
			if (xf&&yf&&zf)
			{
				if (x*x + y*y == z*z)
				{
					x = 0;
					y = x;
					z = y;
					xf = false;
					yf = false;
					zf = false;
					cout << "Pythagorean Triplet" << endl;
				}
				else
				{
					x = y;
					y = z;
					z = 0;
					xf = true;
					yf = false;
					zf = false;
				}
			}

		}

	}



	system("pause");
    return 0;
}

