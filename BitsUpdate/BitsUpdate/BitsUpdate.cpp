// BitsUpdate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int num = 0;
	int bit = 0;
	bool IsOn = false;
	int val = 0;
	cout << " Enter number, bit and true or false" << endl;
	cin >> num;
	cin >> bit;
	cin >> IsOn;

	val = IsOn ? 1 : 0;
	int mask = ~(1 << bit);

	num = (num & mask) | (val << bit);

	cout << " Modified number is " << num << endl;

	system("pause");
    return 0;
}

