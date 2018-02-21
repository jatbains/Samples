// MinimumWindow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void MinimumString(string input, string pattern);

int main()
{
	string input = "ADOBECODEBANC";
	string pattern = "ABC";

	MinimumString(input, pattern);

	system("pause");
    return 0;
}

void MinimumString(string input, string pattern)
{
	bool map[256] = { false };
	bool tempMap[256] = { false };
	int trueCount = 0;
	int maxLen = 0;
	int maxCurr = 0;
	int prevLen = 0;
	int len = 0;
	int pat = 0;
	int curlen = 0;
	int index = 0;
	// Populate the map for all char in pattern
	for (int i = 0; i < pattern.length(); i++)
	{
		map[pattern[i]] = true;
		trueCount++;
	}
	// map has pattern
	while (len != input.length())
	{
		if (map[input[len]] == true)  // Found one entry
		{
			curlen = len;
			// Loop to see if all are found

			while (input[curlen] != input[input.length()])
			{
				if (map[input[curlen]] == true)
				{
					pat++;					
				}
				
				curlen++;
				if (pat == trueCount)
					break;
			}

			if (pat == trueCount)
			{
				index = len;
				maxCurr = curlen - index;
				
				if (maxCurr < prevLen)
				{
					prevLen = maxCurr;
				}
				prevLen = maxCurr;
			}
			pat = 0;
		}
		// Not found restart
		len++;
	}

	cout << "Length is " << prevLen << " Index is " << index << endl;
	cout << endl;
	cout << input.substr(index, prevLen);
	cout << endl;
}

bool CheckMap(bool *map)
{
	return true;
}