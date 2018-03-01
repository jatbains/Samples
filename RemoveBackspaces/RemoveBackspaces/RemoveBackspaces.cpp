// RemoveBackspaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void RemoveBackSpaces(char *str);

int main()
{
	char name[] = { 'M','y',' ','N','e','\b','a','c','c','\b','\b','m','e','\0' };

	RemoveBackSpaces(name);

	cout << name << endl;

	system("pause");
    return 0;
}

void RemoveBackSpaces(char *str)
{
	char *p = str;
	char *t = nullptr;
	char *b = nullptr;

	while (*p != '\0')
	{

		if (*p == '\b')    // p-- b points to \b 
		{	
			b = p;
			while (*b == '\b')
			{
				b++;
				p--;
			}

			t = p;
			while (*b != '\0')    // Copy all over
			{
				*p = *b;
				p++;
				b++;
			}
			*p = '\0';
			p = t;    // Move p to next chracter backtrack
		}

		p++;
	}
	*p = '\0';


}