// IsNumberAnExponent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int num = 0, exp = 0;
	cout << "Enter a number " << endl;
	cin >> num;
	cout << "Enter the base " << endl;
	cin >> exp;
	// A number is a an exponent of 5 if num%5 == 0

	cout << "Number is a " << (num % exp == 0 ? "power" : "not a power") << endl;

	system("pause");
    return 0;
}

