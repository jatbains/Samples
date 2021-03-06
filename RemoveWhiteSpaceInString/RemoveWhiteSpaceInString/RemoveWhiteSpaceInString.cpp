// RemoveWhiteSpaceInString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>


using namespace std;

string RemoveWhiteSpaces(string s1);
string CopyString(string s1);

static const int MAX_SIZE = 40;

int main()
{
	string s1 = "    Welcome   To The    Jungle   ";
	string s2 = "";

	s2 = RemoveWhiteSpaces(s1);
	
	cout << s2 << endl;

	system("pause");
    return 0;
}

string CopyString(string s1)
{
	string s2;
	s2.resize(MAX_SIZE);
	int l = 0;
	for (int l = 0; l != s1.length(); l++)
	{
		s2[l] = s1[l];
	}
	return s2;
}

string RemoveWhiteSpaces(string s1)
{
	string s2 = "";
	s2.resize(MAX_SIZE);
	bool isCharSeen = false;
	bool isWordSeen = false;

	int index1 = 0;
	int index2 = 0;

	// Process the string removing whitespaces preceeding in the
	// middle and following
	// Process until the end of the original string

	while (index1 != s1.length())
	{
		if (s1[index1] == ' ')
		{
			// Skip over if previous was not a char
			if (!isCharSeen)  // Previous was not a character
			{
				index1++;     // skip over whitspace
			}
			isCharSeen = false;
			continue;
		}
		else
		{	
			// Need to insert whitespace
			if (!isCharSeen && isWordSeen)
			{
				index2++;
			}

			s2[index2] = s1[index1];
			index1++;
			index2++;

			isCharSeen = true;
			isWordSeen = true;
		}

	}
	return s2;
}