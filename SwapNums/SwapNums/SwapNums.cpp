// SwapNums.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	int x = 20;
	int y = 30;

	x = x + y;
	y = x - y;     // y is 20
	x = x - y;     // x is 20

	cout << " X is " << x << endl;
	cout << " Y is " << y << endl;

	cout << endl;
	// Convert back;
	x = x ^ y;
	y = x ^ y;  
	x = x ^ y;

	cout << " X is " << x << endl;
	cout << " Y is " << y << endl;

	cout << endl;

	system("pause");
    return 0;
}

