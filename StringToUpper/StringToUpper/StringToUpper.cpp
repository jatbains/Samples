// StringToUpper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void ConverToUpper(char *str);
void ConverToLower(char *str);
string ConvertToUpper(string s);
string ConvertToLower(string s);

int main()
{
	char input[] = { 'H','e','l','l','o',' ','W','o','r','l','d','\0' };
	string greet = "Its my life";
	string *out = nullptr;
	ConverToUpper(input);

	cout << input << endl;

	ConverToLower(input);

	cout << input << endl;

	cout << ConvertToUpper(greet) << endl;

	cout << ConvertToLower(greet) << endl;

	system("pause");
    return 0;
}

string ConvertToUpper(string s)
{
	string *out = new string(s.length(),' ');
	string::iterator it;
	string::iterator jt;
	
	for (it = s.begin(),jt=out->begin(); it != s.end(); it++,jt++)
	{
		if (*it >= 'a' && *it <= 'z')
		{
			*it -= 32;

		}
		*jt = *it;
	}
	return *out;
}

string ConvertToLower(string s)
{
	string *out = new string(s.length(),' ');
	string::iterator it;
	string::iterator jt;

	for (it = s.begin(), jt = out->begin(); it != s.end(); it++, jt++)
	{
		if (*it >= 'A' && *it <= 'Z')
		{
			*it += 32;
		}
		*jt = *it;
	}
	return *out;
}

void ConverToLower(char *str)
{
	char *p = str;
	while (*p != '\0')
	{
		if (*p >= 'A' && *p <= 'Z')
		{
			*p += 32;
		}
		p++;
	}

}

void ConverToUpper(char *str)
{
	char *p = str;

	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
		{
			*p -= 32;
		}
		p++;
	}
	
}