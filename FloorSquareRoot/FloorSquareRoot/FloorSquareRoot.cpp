// FloorSquareRoot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int FloorSqRoot(int x);

int main()
{
	int x = 145;

	cout << FloorSqRoot(x) << endl;


	system("pause");
    return 0;
}

int FloorSqRoot(int x)
{
	// Base cases
	if (x == 0 || x == 1)  
		return x;

	// Check by finding the mid point
	int mid = 0;
	int start = 1;
	int end = x;
	int ans = 0;
	while (start <= end)
	{
		mid = (start + end) / 2;

		if (mid*mid == x)
			return mid;

		// Need to adjust mid
		if (mid*mid < x)
		{
			start = mid + 1;
			ans = mid;
		}
		if (mid*mid > x)
		{
			end = mid - 1;
		}

	}
	return ans;

}