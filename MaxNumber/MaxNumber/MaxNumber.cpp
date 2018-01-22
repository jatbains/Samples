// MaxNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int sign(int x);
int flip(int x);

int main()
{
	int x = 0, y = 0;
	cout << "Enter two numbers " << endl;
	cin >> x;
	cin >> y;
	int c = 0;
	int mask = 1 << 32;
	// Determine which is bigger
	c = x - y;  // k will be positive or negative if +ve then x bigger else y bigger
	// Test for positive  else its negative
	int sa = sign(x);
	int sb = sign(y);
	int sc = sign(c);

	int use_sign_of_a = sa ^ sb;

	int use_sign_of_c = flip(sa^sb);

	int k = use_sign_of_a * sa + use_sign_of_c * sc;
	int q = flip(k);

	cout << "The result is " << x*k + y*q << endl;

	system("pause");
    return 0;
}

int flip(int x)
{
	return 1 ^ x;
}
int sign(int x)
{
	return (x >> 31 & 1 );
}
