// FlooredSqrt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int WhileRoot(int n);
int SquareRoot(int n, int x);

int main()
{
	int num = 54;

	cout << WhileRoot(num) << endl;

	cout << SquareRoot(54, 1) << endl;

	system("pause");
    return 0;
}

int WhileRoot(int n)
{
	int x = 1;
	while ((n /(x*x) >= 1))
	{
		x++;
	}
	return --x;
}

int SquareRoot(int n,int x)
{
	if (n /(x*x) <=0 )  // Base case  
		return --x;

	return SquareRoot(n, x + 1);

}