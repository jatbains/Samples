// Passwords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

void passwords(char st[], int len);
void generate(char s[], int i, string p, int len);

int main()
{
	char str[] = { 'a','b','c' };
	int len = sizeof(str) / sizeof(str[0]);
	char pass[2] = { 0 };
	// Recursively generate all the passwords

	passwords(str, len);

	system("pause");
    return 0;
}

void generate(char s[], int i, string p, int len)
{
	if (i == 0)  // Done
	{
		cout << p << endl;
		return;
	}

	for (int j = 0; j < len; j++)
	{
		string appended = p + s[j];
		generate(s, i - 1, appended, len);

	}
	return;
}

void passwords(char st[], int len)
{
	for (int i = 2; i <= len; i++) 
	{
		generate(st, i, "", len);
	}

}
