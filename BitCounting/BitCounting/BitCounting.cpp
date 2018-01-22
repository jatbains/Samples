// BitCounting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int LookupCount(int num);

int main()
{
	int num = 0;
	int copy = 0;
	int count = 0;
	cout << "Enter a number " << endl;
	cin >> num;
	copy = num;
	// count the number of bits
	while (num)
	{
		if (num & 1)
			count++;
		num >>= 1;
	}
	cout << "The number of bits on is " << count << endl;

	cout << "Using the lookup method  " << LookupCount(copy) << endl;
	system("pause");
    return 0;
}

int LookupCount(int num)
{
	int map[] = { 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4 };
	int count = 0;
	int mask = 0xF;

	while (num)
	{
		if (num & mask)
			count += map[num & mask];
		num >>= 4;
	}

	return count;
}

