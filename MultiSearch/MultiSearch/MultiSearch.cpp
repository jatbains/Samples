// MultiSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;
bool FindString(char *str, char *pat);
bool FindMatch(char *str, char *pat);

int main()
{
	const char str[] = "ThisIsAVeryLongString";
	const char *pat[] = { "Very","Long","Boy","sIs" };
	int size = sizeof(pat) / sizeof(pat[0]);
	

	for (int i = 0; i < size; i++)
	{ 
		// Call function
		cout << (FindString((char *)str, (char *)pat[i]) ? "Match Found" : "No Match") << endl;
		
	}
	cout << endl;

	system("pause");
    return 0;
}

bool FindString(char *str, char *pat)
{
	// Go through the string and look for a match
	if (*str == '\0')
		return false;     // No match

	// Chek for a match
	if (*pat == *str)
	{
		// Call fundtion to match them
		return FindMatch(str, pat);
	}

	// If no match move forward and try again
	return FindString(str + 1, pat);
}

bool FindMatch(char *str, char *pat)
{
	// Base case when we reach end
	if (*str == '\0' && *pat != '\0')
		return false;    // No match

	if (*pat == '\0')
		return true;   // Match found

	// Check the next character for a match
	return FindMatch(str + 1, pat + 1);
}