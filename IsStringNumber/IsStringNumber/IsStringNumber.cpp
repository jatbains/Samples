// IsStringNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
bool CheckIfNumber(char *st);

int main()
{
	char *str = "45&*999#chj2";
	char *num = "29574";

	cout << (CheckIfNumber(num) ? " A Number " : " Not a number ") << endl;



	system("pause");
    return 0;
}

bool CheckIfNumber(char *st)
{
	char *c = st;
	// Go through string and check for non integer characters
	while (*c != '\0')
	{
		if (!(*c >= '0' && *c <= '9'))
		{
			return false;
		}
		c++;
	}
	return true;
}