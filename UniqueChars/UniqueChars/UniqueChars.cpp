// UniqueChars.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

typedef struct CharMap
{
	int alph[26];
}CharMap;

int main()
{
	string input;
	CharMap map;
	int hash[26] = { 0 };
	int index = 0;
	char *p;
	cout << "Enter a string to process " << endl;
	getline(cin,input);

	p = (char *)input.c_str();

	for (int i = 0; i < input.length(); i++)
	{
		 // May Capital or lower case
		if ('A' <= *p <= 'Z')
			index = *p - 'A';
		if ('a' <= *p <= 'z')
			index = *p - 'a';

		hash[index]++;
		if (hash[index] > 1)
		{
			cout << "Duplicate characters " << endl;
			break;
		}
		p++;
	}


	getchar();

    return 0;
}

