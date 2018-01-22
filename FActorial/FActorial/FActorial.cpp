// FActorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int Fact(int n);

int main()
{
	int num = 0;
	cout << "Enter a number" << endl;
	cin >> num;

	cout << "Factorial is " << Fact(num) << endl;

	getchar();
	getchar();
    return 0;
}

int Fact(int n)
{
	if (n == 0)
		return 1;
	return (n*Fact(n - 1));
}
