// ReverseStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
void reverse(char *str);

int main()
{
	//char string[] = { 'H','E','L','L','O','\0' };
	char string[] = "Welcome";

	reverse(string);

	cout << string << endl;

	system("pause");
    return 0;
}
void reverse(char *str) {
	char *p = NULL, *q = NULL;
	p = q = str;
	char c;
	while (*q != '\0')
	{
		q++;
	}
	q--;

	while (p < q)
	{
		c = *p;
		*p = *q;
		*q = c;
		p++;
		q--;
	}
}
