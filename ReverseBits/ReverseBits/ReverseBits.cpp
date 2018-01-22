// ReverseBits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

// Reverse the bits in a number

int main()
{
	int num = 0;
	unsigned int out = 0;
	cout << "Enter a number " << endl;

	cin >> num;

	// shift num to right by one at a time and and with one and 
	// accumulate the result into out which is shifted to left
	for (int i = 0; i < 31; i++)
	{
		out |= (num >> i) & 1;
		out <<= 1;
	}

	cout << "Shifted num is " << out << endl;


	system("pause");
    return 0;
}

