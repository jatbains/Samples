// BitDifferences.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	int num1 = 0, num2 = 0;
	int xor = 0, count = 0;
	// Find the bit difference between two numbers
	// Bit difference will be the bit wise XOR summed up

	cout << "Enter two numbers " << endl;
	cin >> num1;
	cin >> num2;

	xor = num1 ^ num2;

	// Count Number of bits in xor
	while (xor)
	{
		if (xor &1)
		{
			count++;
		}
		xor >>= 1;
	}


	cout << "The number of bits difference is " << count << endl;

	system("pause");
    return 0;
}

