// isPallindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;


int main()
{
	string input;
	int charMap[26];
	int size = 0;
	int val = 0;
	char *p;
	bool isOddChar = false;
	bool isPallindrome = true;
	cout << "Enter a string " << endl;
	getline(cin, input);
	size = input.length();
	// Go through the string and put character frequency into hash
	p = (char *)input.c_str();

	while (*p != '\0')
	{
		if (*p = ' ')
			p++;
		// treat capital and lower case the same
		// Check for capital
		if (*p <= 'Z"')
		{
			val = *p - 'A';

		}
		if (*p >= 'a')
		{
			val = *p - 'a';
		}
		// Increment in table
		charMap[val]++;

	}
	// Once populated next go through map
	for (int i = 0; i < 26; i++)
	{
		if (charMap[i] != 2)
		{
			if (size % 2)
			{
				isOddChar = true;
			}
			if ((size % 2) && isOddChar)
			{
				// More than one odd characters found
				isPallindrome = false;
			}

		}

	}

	cout << (isPallindrome ? "This is a pallindrome" : "This is not a pallindrome") << endl;

	getchar();
    return 0;
}

