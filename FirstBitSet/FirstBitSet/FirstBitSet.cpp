// FirstBitSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;



int main()
{
	int num = 0;
	cout << "Enter a number " << endl;
	cin >> num;

	unsigned int mask = 1 << 31;
	int pos = 32;
	while (!(num & mask))
	{
		mask >>= 1;
		pos--;
	}
	cout << "Position is " << pos << endl;

	system("pause");
    return 0;
}

