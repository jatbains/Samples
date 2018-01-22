// TriplStep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int countways(int n);

int main()
{
	int stairs = 0;
	cout << "Possible ways child can go up staircase " << endl;
	stairs = 10;

	cout << "Possible ways " << countways(stairs) << endl;

	system("pause");
    return 0;
}
int countways(int n)
{
	// Base case
	if (n < 0)
	{
		return 0;
	}
	else if (n == 0)
	{
		return 1;
	}
	else
	{
		return (countways(n - 1) + countways(n - 2) + countways(n - 3));
	}
}