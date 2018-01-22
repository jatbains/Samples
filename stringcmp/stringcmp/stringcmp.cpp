// stringcmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool stringcmp(char *s1, char *s2);


int main()
{
	string s1;
	string s2;

	cout << "Enter first string " << endl;
	getline(cin, s1);

	cout << "Enter second string " << endl;
	getline(cin, s2);



	cout << "String are " << (stringcmp((char *)s1.c_str(), (char *)s2.c_str()) ? "Equal" : "Not Equal") << endl;

	cout << endl;

	system("pause");
    return 0;
}

bool stringcmp(char *s1, char *s2)
{
	char *s = s1;
	char *t = s2;

	while ((*s != '\0') && (*t != '\0'))
	{
		if (*s != *t)
			return false;
		s++;
		t++;

	}

	if ((*s != '\0') || (*t != '\0'))
		return false;

	return true;

}
