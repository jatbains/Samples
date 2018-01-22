// Conversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
	int A = 29, B = 44;
	int mask = 1;
	int diff = 0;
	int count = 0;
	// Compare the two and determine how many bits to flip
	diff = A ^ B; // XOR between the two
	// Count the bits up

	for (int i = 1; i <= 32; i++)
	{
		if (diff & mask)
		{
			count++;
		}
		mask <<= 1;
	}


	cout << "The number of bits to flip is " << count << endl;

	system("pause");
    return 0;
}

