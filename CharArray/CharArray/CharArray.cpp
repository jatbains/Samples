// CharArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char *p = (char *)malloc(sizeof(char)*100);
	char *s = new char[100];


	// Access an index
	for (int i = 0; i < 100; i++)
	{
		p[i] = rand() % 100;
		s[i] = p[i];
	}

	for (int i = 0; i < 100; i++)
	{
		if (p[i] != s[i])
			cout << "Not the same" << endl;
		else
		{
			printf("p: %d s: %d\n", p[i], s[i]);
		}

	}


	cout << endl;
	system("pause");
    return 0;
}

