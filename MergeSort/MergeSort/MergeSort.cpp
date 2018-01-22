// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const static int MAX_ARRAY = 20;

class Merge
{
private:
	int data[MAX_ARRAY];
	int helper[MAX_ARRAY];
	/*int left;
	int right;
	int mid;*/
public:
	Merge();
	void mergeSort(int left, int right);
	void mergeArray(int left, int mid, int right);
	void copyArray(int data[]);
	void PrintArray(void);
};

void Merge::copyArray(int input[])
{
	for (int i = 0; i < MAX_ARRAY; i++)
	{
		data[i] = input[i];
	}
}

void Merge::PrintArray(void)
{
	cout << "Sorted array is " << endl;
	for (int i = 0; i < MAX_ARRAY; i++)
	{
		cout << " " << data[i];
	}
	cout << endl;
}
Merge::Merge()
{
	// Copy from input data array to internal data
	/*left = right = mid = 0;*/
	for (int i = 0; i < MAX_ARRAY; i++)
	{
		data[i] = 0;
		helper[i] = 0;
	}

}
void Merge::mergeArray( int left,int mid,int right )
{
	// Copy both halves into helper array
	for (int i = left; i <= right; i++)
	{
		helper[i] = data[i];
	}
	// Copy smaller elements back into original array
	int helperLeft = left;
	int helperRight = mid + 1;
	int current = left;

	// Copy smaller elements back
	// Iterate through helper array compare Right and Left halves
	// copying back smaller elements from two halve into original array
	while (helperLeft <= mid && helperRight <= right)
	{
		if (helper[helperLeft] <= helper[helperRight])
		{
			data[current] = helper[helperLeft];
			helperLeft++;
		}
		else
		{
			data[current] = helper[helperRight];
			helperRight++;
		}
		current++;
	}

	// Copy remaining elements over
	int remain = mid - helperLeft;
	for (int i = 0; i <= remain; i++)
	{
		data[current + 1] = helper[helperLeft + 1];
	}

}

void Merge::mergeSort(int left, int right)
{
	if (left < right)
	{

		// Done sorting

	// Sort the left and right halves
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		mergeArray(left, mid, right);
	}

}

int main()
{
	Merge merge;  // Instantiate Merge class
	int data[MAX_ARRAY] = { 10,3,25,9,19,30,8,12,28,15,32,1,14,29,44,37,11,17,25,33 };

	merge.copyArray(data);
	merge.mergeSort(0, MAX_ARRAY-1);
	merge.PrintArray();


	system("pause");
    return 0;
}

