// SwapNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

int main()
{
	int x = 12;
	int y = 34;
	int z = 0;

	x ^= y;    // XOR of x and y  Turn on bits not same
	y ^= x;    // XOR of y and x
	x ^= y;

	cout << "X ix " << x << endl;
	cout << "Y is " << y << endl;

	system("pause");
    return 0;
}

