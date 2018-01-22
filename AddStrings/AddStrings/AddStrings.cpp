// AddStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// This function takes two strings and adds them and then converts 
// back into a string

string ReverseString(string s);
int AddStrings(string s, string t);

int main()
{
	string s1 = "3465";
	string s2 = "234";


	// Add the two strings
	cout << s1 << endl;
	s1 = ReverseString(s1);

	cout << s2 << endl;


	s2 = ReverseString(s2);

	cout << endl;
	cout << AddStrings(s1, s2) << endl;
	


	system("pause");
    return 0;
}

int AddStrings(string s, string t)
{
	char *c = (char *)s.c_str();
	char *d = (char *)t.c_str();
	int digit = 0;
	int power = 1;
	int result=0;
	
	int carry = 0;
	// Add the Values
	while (*c != '\0' && *d != '\0')
	{
		digit = (*c - '0' + *d - '0');
		if (digit > 10)
		{
			digit %= 10;
			carry = 1;
		}
		result += (digit + carry)*power;
		power *= 10;
		carry = 0;
		c++;
		d++;
	}
	while (*c != '\0')
	{
		result  += ((*c - '0')+carry)*power;
		power *= 10;
		carry = 0;
		c++;
	}

	while (*d != '\0')
	{
		result += ((*d = '0')+carry)*power;
		power *= 10;
		carry = 0;
		d++;

	}


	return result;
}

string ReverseString(string s)
{
	char *p = (char *)s.c_str();
	char *t = p;
	char c;

	while (*t != '\0')
	{
		t++;
	}
	t--;

	while (p < t)
	{
		c = *p;
		*p = *t;
		*t = c;
		p++;
		t--;

	}
	return s;
}
