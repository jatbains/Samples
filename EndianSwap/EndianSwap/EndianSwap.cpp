// EndianSwap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

unsigned int EndianSwap(unsigned int num);

int main()
{
	unsigned int num = 0xAABBCCDD;

	cout << endl;
	cout << hex << EndianSwap(num) << endl;
	cout << endl;

	system("pause");
    return 0;
}

unsigned int EndianSwap(unsigned int num)
{
	int swap = 0;
	unsigned char mask = 0;
	unsigned int umask = 0;

	mask = ~mask;      // All 1s
	umask |= mask;

	swap = num << 24 | num >> 24 | (num >> 8) & (umask << 8) | (num << 8) & (umask  << 16);
	
	return swap;
}