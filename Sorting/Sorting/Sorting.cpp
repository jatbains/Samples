// Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;



void QuickRecur(int *data, int low, int high);
void swap(int data[], int low, int high);
void PrintArray(int data[], int size);
int Partition(int *data, int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
	int data[] = { 20,2,13,7,11,19,15,5,9,23,18 };  // Sort this array with two methods
	int size = sizeof(data) / sizeof(data[0]);

	PrintArray(data, size);
	// Call QuickSort
	//QuickRecur(data, 0, size);
	quickSort(data, 0, size-1);
	cout << endl;
	PrintArray(data, size);

	system("pause");
    return 0;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low  --> Starting index,
high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);
		//int pi = Partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void PrintArray(int data[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;
	}
}

void swap(int data[], int low, int high)
{
	int temp = data[low];
	data[low] = data[high];
	data[low] = temp;
	return;
}

int Partition(int *data, int low, int high)
{
	int pivot = data[(low+high)/2];   //  Find pivot
	// Move pointers toward each other

	while (low <= high)
	{
		while (data[low] < pivot)
		{
			low++;                    // Move pointers toward each other
		}
		while (data[high] > pivot)
		{
			high--;
		}
		if (low <= high)
		{
			swap(data, low, high);
			low++;
			high--;
		}
	}
	return low;
}

void QuickRecur(int *data, int low, int high)
{
	if (low >= high)    // Base case foen sorting
		return;

	int index = Partition(data, low, high);
	if (low < index - 1) 
	{                           // Sort left half
		QuickRecur(data, low, index - 1);
	}
	if (index < high)
	{
		QuickRecur(data, index, high);
	}
}


