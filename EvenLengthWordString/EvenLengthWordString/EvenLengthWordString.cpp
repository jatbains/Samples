// EvenLengthWordString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	char s[] = "Welcome to the Jungle";
	char *p = s;
	int count = 0;
	char *start = s;

	while (*p != '\0')
	{
		if (*p == ' ')
		{
			
			if (count % 2 == 0)
			{
				// Found word
				*p = '\0';
				cout << start << endl;
				break;
			}
			else
			{
				count = 0;
				start = p;
				p++;
				continue;
			}
				
		}
		count++;
		p++;

	}
	





	system("pause");
    return 0;
}

