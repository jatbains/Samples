// SumSubArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
// Sorted Array Find indexes which add up to a sum

int SubArraySum(int data[], int size, int sum);

int main()
{
	int data[] = { 1 ,2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sum = 0;
	cout << "Enter sum to find " << endl;
	cin >> sum;
	int size = sizeof(data) / sizeof(data[0]);


	SubArraySum(data, size, sum);




	system("pause");
    return 0;
}

int SubArraySum(int data[], int size, int sum)
{
	int currentSum = 0, start = 0, i = 0;
	// Go through the array and look for sum
	currentSum = data[0];

	for (i = 1; i <= size; i++)
	{

		// Check to see if current sum exceeds sum
		while ((currentSum > sum) && (start < i - 1))
		{
			// Remove elements from the sum
			currentSum = currentSum - data[start];
			start++;  // Move start forward

		}
		// Check to see if we have found the sum
		if (currentSum == sum)  // Found the indices
		{
			cout << "The indices are " << start << " and " << i -1 << endl;
			return 1;

		}
		// Else we add elements to the current sum
		if (i < size)
			currentSum = currentSum + data[i];


	}

}

