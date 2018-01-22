// NumbersOppositeSign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;


// Bits have opposite signs if uppermost bit is set
bool SignNumbers(int x, int y);

int main()
{
	int mask = 0x80000000;
	int num1 = -5;
	int num2 = -10;


	cout << (SignNumbers(num1, num2) ? "Opposite Nos" : "Negative Nos") << endl;

	system("pause");
    return 0;
}
bool SignNumbers(int x, int y)
{
	return ((x^y) < 0);
}

