// SparseSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	char *list[]={"at","","","","","ball","","","","car","","","dad","",""};
	bool map[26];
	char a[] = "ball";
	int position;
	int index = 0;
	int count = 0;
	int size = sizeof(list) / sizeof(list[0]);
	// Go through the list and look for characters
	char *p = list[0];   // pointer to first string

	for (int i = 0; i < 26; i++)
	{
		index = a[i] - 'a';
		map[index] = true;
	}
	// Now check each string

	for (int i=0; i < size; i++)
	{
		if (*list[i])
		{
			index = *list[i] - 'a';
			if (map[index] == true)
			{
				position = i;
			}
			
		}
	}


	cout << "The string is in position " << position << endl;

	system("pause");

    return 0;
}

