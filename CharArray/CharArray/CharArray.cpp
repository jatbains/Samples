// CharArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char *p = (char *)malloc(100);

	char *s = new char[100];


	// Access an index
	for (int i = 0; i < 100; i++)
	{
		p[i] = rand() % 255;
		s[i] = i % 255;
	}

	for (int i = 0; i < 1000; i++)
	{
		cout << "p : " << p[i] << "  ";
		cout << "s : " << s[i] << "  ";
	}


	cout << endl;
	system("pause");
    return 0;
}

