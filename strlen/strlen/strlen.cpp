// strlen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int stringlen(char *str);


int main()
{
	// This implements the strlen function
	string s;
	cout << "Enter a string" << endl;

	//cin >> s;

	getline(cin, s);

	cout << "Size of the string is  " << stringlen((char *)s.c_str()) << endl;

	cout << endl;

	system("pause");
    return 0;
}

int stringlen(char *str)
{
	char *p = str;
	int x = 0;

	while (*p != '\0')
	{
		x++;
		p++;
	}
	return x;
}
