// Memoization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int Fib(int num);
int FibMemo(int num, int memo[]);

int main()
{
	int num = 0;
	int memo[20] = { 0 };
	cout << "Enter a number " << endl;
	cin >> num;

	cout << "The fibonacci number is " << Fib(num) << endl;

	// Calculate with memoization
	cout << endl;

	cout << "The fibonacci number with memoization " << FibMemo(num, memo) << endl;

	system("pause");
    return 0;
}

int FibMemo(int num, int memo[])
{
	// Base case
	if (num <= 1)
		return num;

	// Cache the results caching the ith number and once we get it we return it

	if (memo[num] == 0) 
	{
		memo[num] = FibMemo(num - 1, memo) + FibMemo(num - 2, memo);
	}
	return memo[num];
}
int Fib(int num)
{ 
	if (num <= 1)
		return num;


	// else we recurse and add up numbers
	return (Fib(num - 1) + Fib(num - 2));
}

