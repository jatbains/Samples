// RecureMultiply.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int RecurMul(int x, int y);

int main()
{
	int x = 0, y = 0;
	cout << "Enter 1 number " << endl;
	cin >> x;
	cout << "Enter 2 number " << endl;
	cin >> y;


	cout << "The Product is " << RecurMul(x, y) << endl;

	system("pause");
    return 0;
}

int RecurMul(int x, int y)
{
	// Base case x+x y times
	if (y == 1)
		return x;

	// Recursively add
	return (x + RecurMul(x, y - 1));

}

