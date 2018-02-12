// MedianOfArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int ReturnMedian(int *arr1, int *arr2, int n);

int main()
{
	int ar1[] = { 1, 12, 15, 26, 38 };
	int ar2[] = { 2, 13, 17, 30, 45 };

	int n1 = sizeof(ar1) / sizeof(ar1[0]);
	int n2 = sizeof(ar2) / sizeof(ar2[0]);

	cout << "Median is " << ReturnMedian(ar1, ar2, n1) << endl;

	cout << endl;
	system("pause");
    return 0;
}

int ReturnMedian(int *arr1, int *arr2, int n)
{
	int m1 = 0, m2 = 0;
	int i = 0, j = 0;
	int count = 0;

	// Go through the arrays and get median
	for (count = 0; count < n; count++)
	{
		if (i == n)   // All elements of arr1 less that arr2
		{
			m1 = m2;  // save previous  
			m2 = arr2[0];
		}
		if (j == n)
		{
			m1 = m2;
			m2 = arr1[0];
		}

		if (arr1[i] < arr2[j])
		{
			m1 = m2;
			m2 = arr1[i];
			i++;
		}
		if (arr1[i] > arr2[j])
		{
			m1 = m2;
			m2 = arr2[j];
			j++;
		}
	}

	return (m1 + m2) / 2;




}
