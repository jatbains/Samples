// PowerExponent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	int pow = 0;
	int accumulator = 1;

	cout << "Enter a Number" << endl;
	cin >> num;
	cout << "Enter a Power" << endl;
	cin >> pow;


	while (pow > 0)
	{
		accumulator = accumulator*num;
		pow--;
	}
	cout << "Number is " << accumulator << endl;

	system("pause");
	return 0;
}
