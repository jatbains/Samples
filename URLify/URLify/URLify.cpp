// URLify.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	string input;
	string output;
	int size;
	char *c;
	string p;
	// Shift characters or create a new string
	cout << "Enter a string " << endl;
	getline(cin, input);
	cout << "Enter size of string " << endl;
	cin >> size;
	c = (char *)input.c_str();

	// Loop through string and look for " " 
	for (int i = 1; i <= size; i++)
	{
		if (*c == ' ')
		{
			output.append("%20");
		}
		else
		{
			p = *c;
			output.append(p.c_str());
		}
		c++;
	}


	cout << "Output string is " << output << endl;
	getchar();
	getchar();
    return 0;
}

