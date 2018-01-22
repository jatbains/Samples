// RandNumBits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const static int MAX_BITS = 4;

int RandNum(void);

int main()
{
	
	cout << "Random Number is " << RandNum() << endl;


	system("pause");
    return 0;
}

int RandNum(void)
{
	unsigned int mask = 0xFFFFFFFE;
	int num = 0;

	for (int i = 0; i <= MAX_BITS; i++)
	{
		num |= rand() & ~mask;
		num <<= i;
	}

	return num;
}

