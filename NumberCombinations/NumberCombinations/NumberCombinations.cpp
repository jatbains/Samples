// NumberCombinations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void printCombination(char s[], int i, char o[], int l);

int main()
{
	char input[] = "1214";
	int size = sizeof(input) / sizeof(input[0]);

	char *output = new char[100];

	// initialize output with empty string
	output[0] = '\0';

	printCombination(input, 0, output, 0);


	system("pause");
    return 0;
}

void printCombination(char s[], int i,char o[], int l)
{
	// we need to go through the main string and modify the index
	// generate strings with space appended
	// Print these out
	if (s[i] == '\0')   // NULL termination
	{
		o[l] = '\0';
		cout << o << endl;   // Base case
		return;
	}

	o[l] = s[i];
	o[l + 1] = ' ';

		// Repeate
	printCombination(s, i + 1,  o,l + 2);

	if (i + 1 != '\0')
		printCombination(s, i + 1, o, l + 1);

}

