// Pallindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	int size;
	char *s = NULL, *t = NULL;
	bool isPalindrome = true;
	cout << "Enter a string to be analyzed " << endl;
	getline(cin, word);

	// Analyze this string  ignore whitespace characters
	size = word.length();
	s = t = (char *)word.c_str();
	while (*t != '\0')
	{
		t++;
	}
	t--;  // last chracter

	while (s < t)
	{
		if (*s == ' ')
			s++;
		if (*t == ' ')
			t--;
		if (*s != *t)
			isPalindrome = false;

		s++;
		t--;

	}

	cout << ((isPalindrome) ? "This is a palindrome" : "This is not a palindrome" )<< endl;

	getchar();
    return 0;
}

