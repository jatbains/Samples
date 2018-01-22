// Permutations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;


int main()
{
	string s1;
	string s2;
	bool hash[256] = { false };
	char *c;
	cout << "This program determines if one string is a permutation of another " << endl;
	cout << "Enter the first string " << endl;
	getline(cin, s1);
	cout << "Enter the second string " << endl;
	getline(cin, s2);
	// For permutations both must be same length
	c = (char *)s1.c_str();

	if (s1.length() != s2.length())
		cout << "Not a permutation" << endl;

	// Check both strings
	// Populate with string s1 first
	for (int i = 0; i < s1.length(); i++)
	{
		hash[*c] = true;
		c++;
	}
	// Next Check s2
	c = (char *)s2.c_str();
	for (int i = 0; i < s2.length(); i++)
	{
		if (!hash[*c])
			cout << "Not a permutation " << endl;
		c++;
	}


	getchar();
    return 0;
}

