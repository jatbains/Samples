// Duplicates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ostream>
#include <iostream>	

using namespace std;

int main()
{
	int vals[10] = { 1,3,10,6,15,32,8,13,7,15 };
	int num = 0;
	int seen[100] = { 0 };
	bool duplicate = false;

	cout << "Determing if there are duplicates in array" << endl;

	for (int i = 0; i < 10; i++)
	{
		if (seen[vals[i]] == 1)
		{
			duplicate = true;
		}
		seen[vals[i]] = 1;

	}

	cout << "Was there a duplicate " << duplicate << endl;
	getchar();
    return 0;
}

