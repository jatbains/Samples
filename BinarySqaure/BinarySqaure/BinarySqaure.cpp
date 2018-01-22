// BinarySqaure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int BinarySquare(int x);

int main()
{
	cout << BinarySquare(90) << endl;

	system("pause");
    return 0;
}

int BinarySquare(int x)
{
	if (x == 0 || x == 1)
		return 1;

	// Gues a number and see if it is more or less than value
	// start with x/2
	int start = 1;
	int end = x;
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (mid*mid == x)
			return mid;

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
