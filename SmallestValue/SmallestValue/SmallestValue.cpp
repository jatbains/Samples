// SmallestValue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int a[] = { 1,3,15,11,2 };
	int b[] = { 23,127,235,19,8 };
	int diff = 0;
	int num1 = 0, num2 = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (abs(b[j] - a[i] < diff))
			{
				diff = abs(b[j] - a[i]);
				num1 = a[i];
				num2 = b[j];
			}

		}
	}

	cout << "The minimum difference is " << diff << endl;
	cout << "Numbers are " << num1 << "  " << num2 << endl;

	system("pause");
    return 0;
}

