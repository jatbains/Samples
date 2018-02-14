// NeedleHaystack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
bool IsSubFound(const char *s,const char *t);

int main()
{
	const char *str = "HellowNewYork";
	const char *sub = "New";

	cout << "Substring found " << (IsSubFound(str, sub) ? "Yes" : "No" )<< endl;

	system("pause");
    return 0;
}

bool IsSubFound(const char *s,const char *t)
{
	const char *p = s;
	const char *w = s;
	const char *q = t;
	
	// Iterate through s and look for t in it
	while (*w != '\0')
	{
		p = w;
		if (*q == *p)
		{
			while (*q != '\0')
			{
				if (*q == *p)
				{
					q++;
					p++;

				}
				if (*q != *p)
					break;
			}
			if (*q == '\0')
			{
				return true;
			}
		}
		// Reset p and q and retry
		w++;     ///Reset to next char and move q to next character
		q = t;
	}

	return false;  // Not found
}