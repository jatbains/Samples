// LongestSubstring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void LongestSubstring(string s1);

int main()
{
	string s = "abcabcbb";

	LongestSubstring(s);
	cout << endl;

	system("pause");
    return 0;
}

void LongestSubstring(string s1)
{
	int size = s1.length();
	int maxLen = 0;
	int currLen = 0; 
	int index = 0;
	bool map[256] = { false };

	for (int i=0; i < size; i++)
	{
		if (map[s1[i]])  // reset everything
		{
			if (currLen >= maxLen)
			{
				maxLen = currLen;
				currLen = 0;
				index = i-maxLen;
				memset(map, 0, 256);   // Reset boolean array
			}

		}

		map[s1[i]] = true;
		currLen++;
	}
	cout << "The max size is " << maxLen << " Substring is " << s1.substr(index, maxLen) << endl;
}