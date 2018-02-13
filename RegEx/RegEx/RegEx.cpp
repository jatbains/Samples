// RegEx.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <regex>

using namespace std;

bool isMatch(const char *s, const char *p);
bool regexMatch(const char *s, const char *p);

int main()
{
	cout << isMatch("aa", ".a");
	cout << endl;
	cout << isMatch("aab", ".*b") << endl;

	cout << regexMatch("ab", ".*");

	cout << endl;

	system("pause");
    return 0;
}

bool regexMatch(const char *s, const char *p)
{
	regex test(p);
	
	return regex_match(s, test);

}


bool isMatch(const char *s, const char *p)
{
	const char *t = s;
	const char *q = p;
	char dot = '\0';
	char pre = '\0';
	char met = '\0';

	while (*t != '\0')
	{
		if (*q == '.')
		{
			dot = *t;
			q++;
			t++;
			continue;

		}
		if (*q == *t)
		{
			q++;
			t++;
			continue;
		}
		if (*q == '*')
		{
			// match zero or more preceding chars
			// 
			pre = *(--q);  // preceding char

			if (pre == '.')
			{
				met = *t;
				// Matches
				while (met == *t)
				{
					q++;
					t++;
				}

			}
			else
			{
				while (*q == *t)
				{
					t++;
					q++;
				}
			}

		}

		if (*q == '\0')
		{
			// end of pattern start over
			q = t;
		}
		if (*q != *t)
		{
			return false;
		}

	}
	return true;

}