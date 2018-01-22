// SwapOddEvenBits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int num = 0, numEven = 0, numOdd = 0;
	int even = 0xAAAAAAAA;
	int odd = 0x55555555;

	cout << "Enter a number whose bits are to be sawpped " << endl;

	cin >> num;

	// Get Even and Odd bits
	numEven = num & even;
	numOdd = num &odd;
	numEven >>= 1;
	numOdd <<= 1;

	num = numEven | numOdd;

	cout << "Shifted number is " << num << endl;

	system("pause");
    return 0;
}

