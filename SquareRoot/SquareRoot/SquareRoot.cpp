// SquareRoot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int SquareRoot(int n, int x);

int main()
{
	int num = 0;
	int div = 0;
	cout << "Enter a number" << endl;
	cin >> num;
	
	div = SquareRoot(1, num);

	cout << "Num is " << div << endl;

	system("pause");
    return 0;
}

// Wish to find square root  Efficiently 
// Get a number and square it to see if it equal the number
int SquareRoot(int n, int x)
{
	if (n*n >= x) // Base case
		return n;

	// Recurse
	return SquareRoot(n + 1, x);
}

