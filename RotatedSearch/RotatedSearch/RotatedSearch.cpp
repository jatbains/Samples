// RotatedSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int BinarySearch(int arr[], int left, int right, int target);

int main()
{
	int data[] = { 15,16,19,20,25,1,3,4,5,7,10,14 };
	int size = sizeof(data) / sizeof(data[0]);
	cout << "Find element 5 " << endl;

	cout << "The index of the number is " << BinarySearch(data, 0, size - 1, 5) << endl;;

	system("pause");
    return 0;
}


int BinarySearch(int arr[],int left,int right, int target)
{
	
	// Base case 
	if (left > right)
		return -1;  // Not found

	// Find the mid point
	int mid =  (right+left) / 2;
	
	// Check value
	if (target == arr[mid])
		return mid;

	// Recurse down
	if (arr[left] < arr[mid])
	{
		// Go left
		if (arr[left] <= target && target < arr[mid])
		{
			return BinarySearch(arr, left, mid-1, target);
		}
		else
		{
			return BinarySearch(arr, mid+1, right, target);
		}

	}
	else
	{
		if (arr[mid] < target && target <= arr[right])
		{
			return BinarySearch(arr, mid+1, right, target);
		}
		else
		{
			return BinarySearch(arr, left, mid - 1, target);
		}

	}


}
