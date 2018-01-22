// SubStringInString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool CompareStr(char *s1, char *su);
bool FindString(char *s1, char *su);

int main()
{
	char s1[] = "HelloToTheWorld";
	char su[] = "llo";

	// We Will run through two methods akin to two
	// loops with the first looking for first matching
	// character
	// The second method will then compare the sub withing string


	cout << (FindString(s1, su) ? "Match Found" : "No Match") << endl;

	system("pause");
    return 0;
}

bool CompareStr(char *text, char *pat)
{
	if (*text == '\0' && *pat != '\0')
		return false;

	if (*pat == '\0')
		return true;     // Matched reached end

	// If char match increase and recur
	if (*text == *pat)
		return CompareStr(text + 1, pat + 1);
	
	return false;
}

bool FindString(char *text, char *pat)
{
	// Base case
	if (*text == '\0')
		return false;


	if (*text == *pat)
		return CompareStr(text, pat);
	

	return FindString(text + 1, pat);
}

