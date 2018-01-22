// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void QuickSort(int data[],int size);
void BSQuick(int data[], int left, int right);
int partition(int data[], int left, int right);
void swap(int data[], int left, int right);
void PrintArray(int data[],int size);



int main()
{
	int data[] = { 22,55,32,12,17,44,37,4,9,28,37,77 };
	int size = sizeof(data) / sizeof(data[0]);
	// Call QuickSort

	QuickSort(data,size);

	PrintArray(data,size);

	system("pause");
    return 0;
}

void PrintArray(int data[],int size)
{
	
	cout << "Array is " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << data[i] << "  ";
	}
	cout << endl;
}

void QuickSort(int data[],int size)
{
	int left = 0;
	int right = size;
	// Call BS Q
	BSQuick(data, left, right-1);
}
void BSQuick(int data[], int left, int right)
{
	int index = partition(data, left, right);
	if (left < index - 1) {
		BSQuick(data, left, index - 1);
	}
	if (index < right) {
		BSQuick(data, index, right);
	}
	// Sort Left around pivot 

}
int partition(int data[], int left, int right)
{
	int pivot = data[(left + right) / 2];

	while (left <= right) {
		// Move pointers
		while (data[left] < pivot)
			left++;
		while (data[right] > pivot)
			right--;
		// Swap elements
		if (left <= right)
		{
			swap(data, left, right);
			left++;
			right--;
		}

	}
	return left;
}

void swap(int data[], int left, int right)
{
	int temp = data[left];
	data[left] = data[right];
	data[right] = temp;
}