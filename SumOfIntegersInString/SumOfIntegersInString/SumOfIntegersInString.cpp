// SumOfIntegersInString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int FindSum(char *st);

int main()
{
	char str[] = "aa23sdsaadsfsd212sdfsf";

	cout << FindSum(str) << endl;


	system("pause");
    return 0;
}

int FindSum(char *st)
{
	int num1 = 0;
	bool isOne = false;
	int num2 = 0;
	int digit = 0;
	bool isTwo = false;
	char *p = st;
	int power = 1;

	while (*p != '\0')
	{
		p++;
	}
	p--;

	// Go through the string and find numbers
	while (p != st)
	{
		if (*p >= '0' && *p <= '9')
		{
			// Mark begging of first number
			isOne = true;

			if (isOne)
			{
				num1 += (*p - '0')*power;
				power *= 10;
							
			}
			if (!isOne)
			{
				num2 += (*p - '0')*power;
				power *= 10;
					
			}
			p--;
			continue;

		}
		if (isOne)
		{
			power = 1;
			isOne = false;  // Found first
		}

		p--;

	}

	return num1 + num2;


}
