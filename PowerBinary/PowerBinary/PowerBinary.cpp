// PowerBinary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

double Power(double a, int b);

int main()
{
	double a = 15.5;
	int b = 4;

	cout << "The power is " << Power(a, b) << endl;



	system("pause");
    return 0;
}

double Power(double a, int b)
{
	// Base cases
	if (b == 0)
		return 1;
	if (b == 1)
		return a;

	if (b % 2 == 0)
		return Power(a, b / 2)*Power(a, b / 2);
	else
		return a*Power(a, b / 2)*Power(a, b / 2);


}