// fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int fib(int num);

int main()
{
	int num = 0;
	cout << "Enter a number" << endl;
	cin >> num;

	cout << "Print out numbers upto num" << endl;
	for (int i = 0; i <= num; i++) 
	{
		cout << "Fib number is " << fib(i) << endl;
	}
	getchar();
	getchar();
    return 0;
}

int fib(int num)
{
	if (num <=1)
	{
		return num;
	}
	else
	{
	return (fib(num - 1) + fib(num - 2));
	}
}

