// OneAway.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// This method will compare two strings and determine if they are one away
// from each other by doing one change.

int CompareStrings(char *s1, char *s2);

int main()
{
	int diff = 0;
	char str1[] = "bales";
	char str2[] = "pales";  // One edit away


	diff = CompareStrings(str1, str2);

	cout << " The string are " << (diff > 1 ? " Not one away " : " One away") << endl;

	system("pause");
    return 0;
}

int CompareStrings(char *s1, char *s2)
{
	char *p1 = s1;
	char *p2 = s2;
	char *c1 = NULL;
	char *c2 = NULL;
	int diff = 0;
	// Go through both strings and compare them
	while (*p1 != '\0' && *p2 != '\0')
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		if (*p1 != *p2)
		{
			if (*p1 == '\0' || *p2 == '\0')
				break;
			diff++;
			c1 = p1;
			c1++;
			c2 = p2;
			c2++;
			if (*c1 == *c2)
			{
				p1++;
				p2++;
			}
			else
			{
				diff++;
			}
			c1 = p1;
			c1++;
			c2 = p2;
			c2++;
			if (*c1 == *c2)
			{
				p1++;
				p2++;
			}
			else
			{
				diff++;
			}
			if (diff > 1)
				break;
		}

	}
	// We ended and one of the strings may be shorter than the other
	if (*p1 != '\0')
	{
		diff++;
	}
	if (*p2 != '\0')
	{
		diff++;
	}

	return diff;
}