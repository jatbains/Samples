// RemoveWhiteSpace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	char sen[] = "I   live   on     earth";
	char *c = NULL,*p=NULL;

	c = p = sen;
	//p++;
	//c++;
	// Go through the string and remover whitspaces

	while (*c != '\0')
	{
		*p = *c;
		if (*c == ' ')
		{
			while (*c == ' ')
			{
				c++;
			}
		c--;
		}
		p++;
		c++;
	}
	// Terminate string at new end
	*p = '\0';

	cout << sen << endl;


	system("pause");
    return 0;
}

