// PrintKlines.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	// Read in a file
	int i = 0;
	int k = 0;
	char *file[2000];  // Max number os lines in file is 2000
	char *p = NULL;
	// Find total number of lines N  then start printing at N-K
    // Create an array of strings with each string representing a line
	// After file is read in go through the array and print the lines

	p = file[0];

	while (p != NULL)
	{
		i++;
	}
	// Skip over and print last K lines

	while (k <= i)
	{
		cout << file[k];
	}


    return 0;
}

