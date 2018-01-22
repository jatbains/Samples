// PalindromeCombinations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;
bool CheckPalindrome(string s);

int main()
{
	list<string> palins = { {"cat"},{"rat"},{"mat"},{"tab"},{"bat"},{"car"},{"race"} };
	string tPalin;
	list<string>::iterator it;
	list<string>::iterator jt;
	// Combine the strings to find palindromes
	// The combinatons can be multiple ways. 
	// The algorithm would involve going through the list multiple times and creating a temporary
	// concatenated string and then test the string for a palindrome
	for (it = palins.begin(); it != palins.end(); it++)
	{
		for (jt = palins.begin(); jt != palins.end(); jt++)
		{
			if (strcmp((const char *)it->c_str(), (const char *)jt->c_str()))	
			{
				tPalin = *it + *jt;

				// Check this string
				if (CheckPalindrome(tPalin))
				{
					cout << *it << " " << *jt << " Are Palindromes" << endl;
				}
			}
		}
	}
	

	system("pause");
    return 0;
}

bool CheckPalindrome(string s)
{
	int len = s.length();
	int i = 0;
	int j = len-1;
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}