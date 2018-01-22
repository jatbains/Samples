// Isomorphic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// Isomorphic strings
const static int MAX_CHAR = 256;
bool CheckIsomorph(string s1, string s2);

int main()
{
	string s2 = "ball";
	string s1 = "vice";

	// Check lengths
	if (s1.length() != s2.length())
	{
		cout << "Not isomorphic" << endl;
	}

	cout << (CheckIsomorph(s1, s2) ? "Isomorphic" : "Not Isomorphic") << endl;

	system("pause");
    return 0;
}

bool CheckIsomorph(string s1, string s2)
{
	bool marked[ MAX_CHAR ] = { false };
	int map[MAX_CHAR] = { -1 };
	memset(map, -1, sizeof(map));
	// Create a hash array for each
	// Frequency of the difference must be the same
	for (int i = 0; i < s1.length(); i++)
	{
		// go through the strings and check for first occurrence
		if (map[i] == -1)  // First time seen this character
		{
			// If  seen
			if (marked[s2[i]] == true)
				return false;

			// Mark it as seen
			marked[s2[i]] = true;

			// store mapping
			map[s1[i]] = s2[i];
		}
		else if (map[s1[i]] != s2[i])     // Already seen
		{
			return false;
		}
	}

	// Compare the two
	// If there is overlap and different values not isomorphic
	// If not overlap but values are not the same then not isomorphic

	return true;
}