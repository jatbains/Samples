// FacFib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int Fib(int n);
int Fact(int n);

int main()
{
	int num = 0;
	cout << "Enter a number " << endl;
	cin >> num;

	cout << "Factorial is " << Fact(num) << endl;

	cout << "Fibbonaci Num is " << Fib(num) << endl;


	cout << endl;

	system("pause");
    return 0;
}

int Fact(int n)
{
	if (n == 0)
		return 1;

	return (n*Fact(n - 1));
}

int Fib(int n)
{
	if (n <= 1)
		return n;

	return (Fib(n - 1) + Fib(n - 2));
}
