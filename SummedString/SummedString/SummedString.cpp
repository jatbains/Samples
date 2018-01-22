// SummedString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;



int main()
{
	string input = "AC2BEW3";
	char *c = NULL;
	bool hash[26] = { 0 };
	int sum = 0;

	// Process the String first
	c = (char *)input.c_str();
	while (*c != '\0')
	{
		if (*c >= 'A')
		{                            // chracter
			hash[*c - 'A'] = 1;
		}
		else   
		{                            // integer
			sum += *c - '0';
		}

		c++;
	}
	// Print out the values
	for (int i = 0; i < 26; i++)
	{
		if (hash[i] == 1)
		{
			char a = i + 'A';
			cout << a;
		}
	}
	// Print out number
	cout << sum << endl;



	system("pause");
    return 0;
}

