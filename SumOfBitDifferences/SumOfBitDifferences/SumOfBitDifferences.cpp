// SumOfBitDifferences.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int sumBitDifferences(int arr[], int n)
{
	int ans = 0;  // Initialize result

				  // traverse over all bits
	for (int i = 0; i < 32; i++)
	{
		// count number of elements with i'th bit set
		int count = 0;
		for (int j = 0; j < n; j++)
			if ((arr[j] & (1 << i)))
				count++;

		// Add "count * (n - count) * 2" to the answer
		ans += (count * (n - count) * 2);
	}

	return ans;
}

using namespace std;

int main()
{
	int data[] = { 1,3,5 };
	int ans = 0;
	int n = sizeof(data) / sizeof(data[0]);

	ans = sumBitDifferences(data, n);

	cout << "The bits diffrence is " << ans << endl;

	system("pause");
    return 0;
}

