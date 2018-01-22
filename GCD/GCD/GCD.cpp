// GCD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int x = 0, y = 0;
	int g = 0, d = 0;
	cout << "Input two numbers " << endl;
	cin >> x;
	cin >> y;

	while ((x % 2 == 0) && (y % 2 == 0))
	{
		x = x / 2;
		y = y / 2;
		d++;
	}
	
	while (x != y)
	{
		if (x % 2 == 0)
			x = x / 2;
		else if (y % 2 == 0)
			y = y / 2;
		else if (x > y)
			x = (x - y) / 2;
		else
			y = (y - x) / 2;

	}

	g = x * pow(2,d);

	cout << "GCD is " << g << endl;

	system("pause");
    return 0;
}

