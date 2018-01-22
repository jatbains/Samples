// LongestPalindromeSequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
// Longest palindrome  
//  Go through the string and find the same character and
//  then go through the substring and lookf for a palindrome
int LongestSubPalindrome(const char *s);

int main()
{
	const char *s1 =  "abcbbabbcabcbaac" ;

	cout << "Max Palindrome is " << LongestSubPalindrome(s1) << endl;
	cout << endl;
	system("pause");
    return 0;
}

int LongestSubPalindrome(const char *s1)
{
	const char *p = s1;
	const char *q = s1;
	const char *s =NULL , *t = NULL;
	int max = 0;
	int count = 0;
	q++;
	while (*p != '\0')
	{
		while (*q != '\0')
		{
			if (*p == *q)
			{
				s = p;
				t = q;
				count = 0;
				while (s < t)
				{
					if (*s != *t)
					{
						break;
					}
					count++;
					s++;
					t--;
				}
				if (count > max)
				{
					max = count;
				}

			}
			q++;
		}

		p++;   // Backtracking
		q = p;
		q++;
	}

	return max;

}
