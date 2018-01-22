// IsomorphicStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
const static int MAX_CHAR = 256;

bool AreStringsMorphic(string s1, string s2);

int main()
{
	string s1 = "aab";
	string s2 = "xxy";

	cout << "Are the isomorphic: " << (AreStringsMorphic(s1, s2) ? "Yes" : "False") << endl;

	cout << "aab xyz are isomorphic: " << (AreStringsMorphic("abc", "xxy") ? "Yes" : "False") << endl;

	cout << endl;

	system("pause");
    return 0;
}
// Algorithm first check length must be same
// Go through each string and create a hash table for 
// each and see if anything has occurred previously

bool AreStringsMorphic(string s1, string s2)
{
	int map[MAX_CHAR] = { -1 };
	memset(map, -1, sizeof(map));
	bool marked[MAX_CHAR] = { false };
	if (s1.length() != s2.length())
		return false;

	for (int i = 0; i != s1.length(); i++)
	{
		// Need to see if this was not seen before in map
		if (map[s1[i]] == -1)
		{
			// Check if current character is s2 was seen for a previous mapping of s1
			if (marked[s2[i]] == true)
				return false;
			// If not previously marked for s2
			marked[s2[i]] = true;
			// store the mapping
			map[s1[i]] = s2[i];
		}
		else if (map[s1[i]]!=s2[i])   // The previous mapping did not match
		{
			return false;
		}


	}
	return true;

}