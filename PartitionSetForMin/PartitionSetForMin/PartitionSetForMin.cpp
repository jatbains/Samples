// PartitionSetForMin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int FindMinResult(int arr[], int i, int sumCal, int sumTotal);
int FindMinDiff(int arr[], int n);

int main()
{
	int arr[] = { 1, 6, 11, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	// Partition and find minimal difference
    // Sum of n - (size -n)  minimal
	// diff abs(s1-s2)  


	cout << "min diff is " << FindMinDiff(arr, size) << endl;


	system("pause");
    return 0;
}

int FindMinResult(int arr[], int i, int sumCal, int sumTotal)
{
	// Base case we are decreasing the number of elements in the 
	// total to find the sum
	// Last element reached

	if (i==0)
		return abs((sumTotal - sumCal) - sumCal);

	cout << "SumCal is " << sumCal << endl;
	// Find the minimum difference in the set
	// We either include the ith element or we do not

	return min(FindMinResult(arr, i - 1, sumCal + arr[i - 1], sumTotal), FindMinResult(arr, i - 1, sumCal, sumTotal));
}

int FindMinDiff(int arr[],int n)
{
	// Base case 

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	return FindMinResult(arr, n, 0, sum);
}
