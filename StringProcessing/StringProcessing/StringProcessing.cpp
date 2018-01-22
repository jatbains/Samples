// StringProcessing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void MixStrings(string s1, string s2);
void PrintAnagrams(string s1, string s2);

const static int MAX_CHAR = 256;

int main()
{
	string arr[]= { "geeksquiz", "geeksforgeeks", "abcd",
		            "forgeeksgeeks", "zuiqkeegs" };
	string s1 = "Hello";
	string s2 = "lloeH";

	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			PrintAnagrams(arr[i], arr[j]);
		}
	}
	cout << endl;
	PrintAnagrams(s1, s2);


	MixStrings(s1, s2);

	cout << endl;


	system("pause");
    return 0;
}

void PrintAnagrams(string s1, string s2)
{
	string::iterator t1;
	string::iterator t2;

	// Create two hash arrays
	int hashA[MAX_CHAR] = { 0 };
	int hashB[MAX_CHAR] = { 0 };

	for (t1 = s1.begin(); t1 != s1.end(); t1++)
	{
		hashA[*t1]++;
	}
	for (t2 = s2.begin(); t2 != s2.end(); t2++)
	{
		hashB[*t2]++;
	}
	// Compare the hash functions
	for (int i = 0; i < MAX_CHAR; i++)
	{
		if (hashA[i] != hashB[i])
		{
			return;  // No match
		}
	}
	// Match found
	cout << s1 << " " << s2 << endl;
}

void MixStrings(string s1, string s2)
{
	string::iterator i1 = s1.begin();
	string::iterator i2 = s2.begin();
	

	while (i1!=s1.end()	  && i2 !=s2.end())
	{
		// Mix the characters
		cout << *i1 << *i2;
		i1++;
		i2++;
	}
	// Remaining chars
	while (i1 != s1.end())
	{
		cout << *i1;
		i1++;
	}
	while (i2 != s2.end())
	{
		cout << *i2;
		i2++;
	}
}

