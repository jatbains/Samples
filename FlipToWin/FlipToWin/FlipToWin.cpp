// FlipToWin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	int Num = 1775;
	int mask = 1;
	int preLen = 0, curLen = 0;
	int maxLen = 1;
	
	// Find the longest number of bits first

	// Trivial case
	if (~Num == 0)
	{
		cout << " All 1s " << endl;
		return 0;
	}


	while(Num !=0)
	{
		// Find max numbers of 1s in a row separated by 0
		if ((Num & 1) == 1)
		{
			curLen++;
		}
		else if ((Num & 1) == 0)
		{
			preLen = ((Num & 2) == 0) ? 0 : curLen;
			curLen = 0;
		}
		maxLen = max((preLen + curLen + 1), maxLen);
		Num >>= 1;

	}

	cout << "The number of bits is " << maxLen << endl;

	system("pause");
    return 0;
}

