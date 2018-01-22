// LongestPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// To caluculate the longest Palindrome we repeatedly subdivide the array and
// check for characters that are the same and the ones inbetween form a palindrome
int LongestPalindrome(string s, int o, int l);

int main()
{
	string s1 = "GEEKSFORGEEKS";
	int max = 0;
	int temp;

	

	cout << "Longest Palindrome is " << LongestPalindrome(s1,0,s1.length()-1) << endl;

	system("pause");
    return 0;
}

int LongestPalindrome(string s, int o, int l)
{
	// Base case when the total string is present 
	// Need to run two loops and increment the substring
	if (o == l)
		return 1;         // None found

	// Onll two characters
	if (s[o] == s[l] && o + 1 == l)
		return 2;

	// if first and last match
	if (s[o] == s[l])
	{
		return LongestPalindrome(s, o + 1, l - 1) + 2;
	}

	// If characters do not match
	return max(LongestPalindrome(s, o, l - 1), LongestPalindrome(s, o + 1, l));

}