// FindMinFlip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int findMinFlip(int num);

int main()
{
	int num = 0;
	cout << "Enter a number" << endl;
	cin >> num;

	cout << "Minimum flips are " << findMinFlip(num) << endl;

	system("pause");
    return 0;
}

int findMinFlip(int num)
{
	int flips = 0;
	int ones = 0,zeros=0;
	int oBits = 0, zBits = 0;
	bool bits[32] = { false };

	for (int i = 0; i < 32; i++)
	{
		if (num & 1<<i)
		{
			bits[i] = true;

			ones++;
		}
		
	}

	zeros = 32 - ones;

	// Go through the bits table
	for (int i = 31; i > 31 - ones; i--)
	{
		if (!bits[i])
		{
			oBits++;  // Bits need to be changed to ones
			
		}
	}
	cout << "The one bits to be flipped " << oBits << endl;

	for (int i=0;i<=zeros;i++)
	{
		if (bits[i])
		{
			zBits++;  // bits needed to be change to zeros
		}
	}
	// Bits to flip are
	cout << "The zero bits to be flipped " << zBits << endl;

	flips = oBits + zBits;
	return flips;

}
