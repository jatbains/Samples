// Pangram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;



int main()
{
	string sent = "The quick brown fox jumps over the lazy dog";
	int charMap[26] = { 0 };

	// Process the string character by character
	for (int i = 0; i != sent.length(); i++)
	{
		charMap[sent[i] - 'a']++;
	}

	// Process the map
	for (int i = 0; i < 26; i++)
	{
		if (charMap[i] == 0)
		{
			char c = i + 'a';
			cout << "Character  missing is  " << c << endl;
		}
	}

	system("pause");
    return 0;
}

