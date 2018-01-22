// StringsIntoNum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	char num[] = "1,9,3,5,4,7,2";
	int hash[25] = { 0 };
	int longest = 0;
	int prevlong = 0;
	int prevstart = 0;
	int start = 0;
	bool Isstart = false;
	char c = 0;
	char *s = NULL;
	int size = sizeof(num) / sizeof(num[0]);
	// Parse the array
	// s = strtok(num, ",");

	for (int i = 0; i < size; i++)
	{
		if (num[i] >= '0' && num[i] <= '9')
		{
			hash[num[i] - '0'] = 1;
		}
	}
	// Now just go thorugh the table
	for (int i = 0; i < 25; i++)
	{
		if (hash[i] == 1)
		{
			start = i;
			
			longest++;
			if (!Isstart)
			{
				if (longest > prevlong)
				{
					prevstart = start;
					Isstart = true;
				}
			}
			if (longest > prevlong)
			{
				prevlong = longest;
			}

		}
		else
		{
			// reset 
			longest = 0;
			start = 0;
			Isstart = false;
		}
	}
	// done here

	c = prevstart + '0';
	cout << c << " " << prevlong << endl;


	system("pause");
    return 0;
}

