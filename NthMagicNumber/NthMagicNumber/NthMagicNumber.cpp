// NthMagicNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int NthPower(int n);

int main()
{
	int num = 0;
	
	cout << "Enter a number N" << endl;

	cin >> num;


	cout << NthPower(num) << endl;


	system("pause");
    return 0;
}

int NthPower(int n)
{
	int power = 1;
	int sum = 0;

	while (n)
	{
		power *= 5;

		if (n & 1)
		{
			sum += power;
		}
		n >>= 1;

	}
	return sum;
}