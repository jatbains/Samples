// BitManipulation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int num = 0;
	int count = 0;
	int mask = 1;
	int copy = 0;
	int reverse = 0;
	cout << "Enter a number " << endl;

	cin >> num;
	copy = num;
	// Count bits
	while (copy)
	{
		if (copy & 1)
			count++;
		copy >>= 1;
	}
	cout << "Bit on are " << count << endl;

	copy = num;
	for (int i = 0; i < 32; i++)
	{
		if (!(copy & 1))
			reverse |= 1;
		reverse <<= 1;
		copy >>= 1;
	}

	cout << "Reverse number is " << reverse << endl;


	getchar();
	getchar();
    return 0;
}

