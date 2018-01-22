// QuickSortArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


void QuickRecur(int data[], int left, int right);
int Partition(int data[], int left, int right);
void PrintArray(int data[], int size);

int main()
{
	int data[] = { 12,3,17,5,14,4,23,19,15,27,9,1,21};
	int size = sizeof(data) / sizeof(data[0]);


	QuickRecur(data, 0, size - 1);

	PrintArray(data, size);

	cout << endl;

	system("pause");
    return 0;
}

void PrintArray(int data[],int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		cout << " " << data[i] << " ";
	}
}

void Swap(int data[], int x, int y)
{
	int temp = data[x];
	data[x] = data[y];
	data[y] = temp;
}

int Partition(int data[], int left, int right)
{
	// Get the mid point
	int mid = left + (right - left) / 2;

	// Get the Pivot Value

	int pivot = data[mid];

	// While left is less than right move pointers towards each 
	// other
	while (left <= right)
	{
		while (data[left] < pivot)
		{
			left++;
		}
		while (data[right] > pivot)
		{
			right--;
		}

		// swap the two values if left < right
		// Here the values on left of pivot and one on right
		// need to be swapped.
		if (left <= right)
		{
			Swap(data, left, right);
			left++;
			right--;
		}
	}

	return left;
}

void QuickRecur(int data[], int left, int right)
{
	// Base Condition
	if (left >= right)
		return;
	// Partition the array and then quicksort the pratitions
	int index = Partition(data, left, right);

	// Sort Left and Right Partitions
	if (left < index - 1)
	{
		QuickRecur(data, left, index - 1);
	}
	if (index + 1 < right)
	{
		QuickRecur(data, index + 1, right);
	}

}
