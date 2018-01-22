// CountSetBits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int CountBits(int n);


int main()
{
	cout << CountBits(5) << endl;


	system("pause");
    return 0;
}

int CountBits(int n)
{
	// In all numbers from 0 to n bits will be flipped
	// at powers of 2
	int i = 0;

	int ans = 0;

	while ((1 << i) <= n)      // Upto the number n we flips bits
	{

		// This is flipped after 2^i iterations
		bool k = 0;

		int change = 1 << i;   // change iterator

		for (int i = 0; i <= n; i++)
		{

			ans += k;
			if (change == 1)
			{
				k = !k;   // flip the bit when change
				change = 1 << i;
			}
			else
			{
				change--;
			}

		}

		i++;
	}
	return ans;
}
