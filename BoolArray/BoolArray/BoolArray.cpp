// BoolArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

static const int MAX_SIZE = 10000;

static char gID[MAX_SIZE];


int main()
{
	int val = 1779;
	char *byte = gID;        // first byte
	int index = val / 8;     // Char value where bit is
	int bit = val % 8;       // Bit to be modified
	int setVal = 1;

	unsigned char mask = 0;
	mask = ~mask;              // 1s
	// clear and set the bit 
	mask &= 0 << bit;          // turn of that bit
	
	// existing value will be
	byte = byte + index;

	// Clear the bit
	*byte &= mask;     // cleared

	*byte |= setVal << bit;   // Set this bit


	cout << "The Byte is " << (int) *byte << endl;

	system("pause");
    return 0;
}

