// SubbArraySum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	int val[] = { 1, 2, 3, 7, 5 };
	int size = 5;
	int sum = 12;
	int pos = 0;
	int count = 0;
	int prevcount = 0;
	int prevpos = 0;
	int hash[10] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		hash[val[i]] = 1;
	}
	int off = 0;
	int i = 0;
	while (i !=5 )
	{	
		if ((sum - val[i]) >= 0)
		{
			sum = sum - val[i];
			if (hash[sum] == 1)
			{
				pos = i;
				count++;
				if (count > prevcount)
				{
					prevcount = count;
					prevpos = pos;
				}
			}
		}
		else
		{
			off++;
			i = off;
			pos = off;
			sum = 12;
			count = 0;
			continue;
		}

		i++;
	}
	// start at 0 to count index
	// Start from prepos and decrement to value

	cout << prevpos << " " << prevcount;
	




	system("pause");
    return 0;
}

