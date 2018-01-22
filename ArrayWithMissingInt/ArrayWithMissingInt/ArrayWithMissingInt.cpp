// ArrayWithMissingInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
// Given an array with missing int find missing number

int main()
{
	int val[] = { 1,2,3,4,5,7,8,9 };
	int val2[] = { 11,12,13,14,15,16,18,19,20,21 };
	int mid = 0;
	int lpos = 0, rpos = 0;
	int missing = 0;

	rpos = sizeof(val) / sizeof(val[0]);

	cout << "Use Binary Algorithm to find missing number " << endl;
	mid = (rpos + lpos) / 2;
	// Setup while loop to do a binary search
	while (lpos < rpos)  // When 2 indexes are next to each other
	{		

		if ((val[mid] - val[lpos]) != (mid - lpos))
		{
			// Hole is here

			// In this partition
			if ((mid - lpos) == 1 && (val[mid] - val[lpos] > 1))
			{
				missing = (val[mid] - 1);
				break;
			}
			rpos = mid;

		}
		else  if ( (val[rpos] - val[mid]) != (rpos-mid))
		{   // In this partition
			
			if ((rpos - mid) == 1 && (val[rpos] - val[mid] > 1))
			{
				missing = (val[mid] + 1);
				break;
			}
			lpos = mid;

		}
		else {
			// no hole
			missing = -1;
			break;
		}

		mid = (rpos + lpos) / 2;
	}

	cout << "Missing number is " << missing << endl;


	system("pause");
    return 0;
}

