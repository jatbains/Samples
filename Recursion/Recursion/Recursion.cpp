// Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int Multiply(int x)
{
	if (x == 0)
		return 1;
	else
		return (Multiply(x-1)*Multiply(x - 1));
}

int main()
{
	int x;
	cout << "Enter a number " << endl;
	cin >> x;
	cout << "The multiply number is " << Multiply(x) << endl;


	getchar();
	getchar();
    return 0;
}

