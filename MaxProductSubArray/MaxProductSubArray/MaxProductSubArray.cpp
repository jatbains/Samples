// MaxProductSubArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Find the Maximum Product of a Sub Array
int MaxProductSub(int data[], int n);

int main()
{
	int data[] = { -2, -3, 0, -2, -40 };
	int size = sizeof(data) / sizeof(data[0]);

	cout << "max Product Sum: " << MaxProductSub(data, size) << endl;

	system("pause");
    return 0;
}

int MaxProductSub(int data[],int n)
{
	int max_so_far = 1;
	int max_end_here = 1;
	int min_end_here = 1;
	// The algorithm is to go through the array and keep track of the max and min so far values
	//  when the max_so_far is greater than max_val we save it in there.

	// The reason for the min_so_far is when we see a negative number we use it to find the next positive number

	/* Traverse through the array. Following values are
	maintained after the i'th iteration:
	max_ending_here is always 1 or some positive product
	ending with arr[i]
	min_ending_here is always 1 or some negative product
	ending with arr[i] */
	for (int i = 0; i < n; i++)
	{
		// check the array
		if (data[i] > 0)
		{
			max_end_here *= data[i];  // Multiply the max
			min_end_here = min(min_end_here*data[i], 1);

		}

		// Special case if data[i] == 0
		if (data[i] == 0)
		{
			// Reset both max and min end here
			max_end_here = 1;
			min_end_here = 1;
		}

		// What about when data[i] is negative
		if (data[i] < 0)
		{
			int temp = max_end_here;
			max_end_here = max(min_end_here*data[i], 1);
			min_end_here = temp*data[i];
		}

		if (max_end_here > max_so_far)
		{
			max_so_far = max_end_here;
		}

	}

	return max_so_far;

}
