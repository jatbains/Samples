// ReverseString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ostream>
#include <string>

using namespace std;


int main()
{
	string name;
	char *p1 = NULL, *p2 = NULL;
	char c;
	int size = 0;
	char me[] = "Jatinder";

	cout << "Enter a string" << endl;

	cin >> name;
	p1 = p2 = (char *)name.c_str();
	//p1 = p2 = me;

	size = name.length();

	cout << "Length of string is " << size << endl;

	//p2 = p2 + size -1;

	while (*p2 != NULL)
	{
		p2++;
	}
	p2--;

	while (p1 < p2)
	{
		c = *p1;
		*p1 = *p2;
		*p2 = c;
		p1++;
		p2--;

	}

	cout << "Reversed string is " << name << endl;

	getchar();
	getchar();

    return 0;
}

