// FirstRepeatedChar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

const static int MAX_CHAR = 26;
char FirstRepeatingChar(const char *s);

int main()
{
	const char *str = "geeksforgeeks";

	cout << "First Repeating char " << FirstRepeatingChar(str) << endl;

	system("pause");
    return 0;
}

char FirstRepeatingChar(const char *s)
{
	int table[MAX_CHAR] = { 0 };
	const char *c = s;

	while (*c != '\0')
	{
		table[*c - 'a']++;
		c++;
	}
	// Go through the table now
	for (int i = 0; i < MAX_CHAR; i++)
	{
		if (table[i] > 1)
		{
			return (i + 'a');
		}
	}
}
