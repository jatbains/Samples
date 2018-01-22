// Coins.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


// Quarters, Dimes, Nickels and Cents
// If you have N cents to give back  you would start with quarters
// 25x + 10y + 5z +w = N  , where x,y,z, w are numbers of coins resp.
void Calculate(int N);

int main()
{
	int change = 0;
	cout << "Enter the change desired " << endl;
	cin >> change;   



	Calculate(change);



	system("pause");
    return 0;
}

void Calculate(int N)
{
	int w = 0, x = 0, y = 0, z = 0;

	// Quarters

	while (N - (25 * w) >= 25)
	{
		w++;  // Number of Quarters
	}
	N = N - 25 * w;
	// Calculate dimes
	while ((N - (10 * x)) >= 10)
	{
		x++;
	}
	N = N - 10 * x;
	// Calculate nickels
	while ((N - (5 * y)) >= 5)
	{
		y++;
	}
	N = N - 5 * y;
	
	// Pennies is z
	z = N;
	cout << "Change is " << w << " Quarters " << x << " Dimes " << y << " Nickels " << z << " Pennies " << endl;
}