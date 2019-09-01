// LongestNonRepeatingString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

bool CheckRepeatingChars(char *s);
int LookForLongestString(char *s);

int main()
{
    std::cout << "Please enter a string\n";
	string longString;
	getline(cin, longString);
	int length = 0, tempLen = 0;
	char *s = &longString[0];
	char *tStr = NULL, *lStr = NULL;
	char *tp = NULL;

	// Go through the string and look for longest non-repeating string
	while (*s != '\0')
	{
		tempLen = LookForLongestString(s);
		if (tempLen > length)
		{
			length = tempLen;
			lStr = s;
		}
		s++;
	}

	cout << "Longest string is \n";
	for (int i = 0; i < length; i++)
	{
		cout << *lStr;
		lStr++;
	}

	cout << "\n";

	if (CheckRepeatingChars(&longString[0]))
	{
		cout << "No repeating chars \n";
	}
	else
	{
		cout << "Repeating chars \n";
	}
	cout << "String is " << longString << "\n";
	getchar();
	return 0;
}

int  LookForLongestString(char *s)
{
	char *t = NULL;
	int length = 0;

	int charFreq[52] = { 0 };

	while (*s != '\0')
	{
		// No non alpha chars
		if (*s < 'Z') {
			charFreq[*s - 'A']++;
			length++;
			if (charFreq[*s - 'A'] > 1)
			{
				break;
			}
		}
		else {
			charFreq[(*s - 'a') * 2]++;
			length++;
			if (charFreq[(*s - 'a') * 2] > 1)
			{
				break;
			}
		}
		s++;
	}

	return length;;

}

bool CheckRepeatingChars(char *s)
{
	int charFreq[52] = { 0 };

	while (*s != '\0')
	{
		// No non alpha chars
		if (*s < 'Z') {
			charFreq[*s - 'A']++;
			if (charFreq[*s - 'A'] > 1)
			{
				return true;
			}
		}
		else {
			charFreq[(*s - 'a')*2]++;
			if (charFreq[(*s - 'a') * 2] > 1)
			{
				return true;
			}
		}

		s++;
	}

	return false;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
