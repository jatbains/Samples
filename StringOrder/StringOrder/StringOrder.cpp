// StringOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;




int main()
{
	char *str = "abcNjhgAhGjhfhAljhRkhgRbhjbevfhO";
	char pattern[]= { "NAGARRO" };
	bool isMatched = true;
	// Go through the main string and search for the patter
	// What we know pattern is upper case embedded in string
	// Go through main string looking for upper case and compare with a pointer in patter
	char *s = str;
	char *p = pattern;

	while (*s != '\0' && *p != '\0')
	{
		if (*s >= 'A' && *s <= 'Z')
		{
			if (*s == *p)
			{
				// pattern match increment to next place
				s++;
				p++;
			}
			else
			{
				// no match 
				isMatched = false;	
			}
		}
		s++;
	}

	cout << (isMatched ? "Match Found" : "Match Not Found") << endl;

	system("pause");
    return 0;
}

