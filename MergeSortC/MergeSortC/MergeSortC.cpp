// MergeSortC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void Merge(int data[], int lp, int rp);
void merge(int data[], int lp, int mid, int rp);
void PrintArray(int data[], int size);

int main()
{
	int data[] = { 23,32,18,7,12,27,37,3,13,29 };
	// Do a merge sort on this
	int size = sizeof(data) / sizeof(data[0]);
	Merge(data, 0, size-1);

	PrintArray(data, size);

	system("pause");
    return 0;
}

void PrintArray(int data[],int size)
{
	cout << "Array is " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " " << data[i]  << "  ";
	}
	cout << endl;
}

void merge(int data[], int lp, int mid, int rp)
{
	int i, j, k;

	int n1 = mid - lp + 1;
	int n2 = rp - mid;
	int L[20], R[20];

	for (i = 0; i < n1; i++)
		L[i] = data[lp + i];
	for (j = 0; j < n2; j++)
		R[j] = data[mid + 1 + j];

	i = 0;
	j = 0;
	k = lp;


	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			data[k] = L[i];
			i++;
		}
		else
		{
			data[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		data[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		data[k] = R[j];
		j++;
		k++;
	}


}

void Merge(int data[], int lp, int rp)
{
	if (lp > rp)
		return;
	// find mid point
	int mid = lp + (rp - lp) / 2;
	// Sort meft then right and merge
	Merge(data, lp, mid - 1);
	Merge(data, mid+1, rp);
	merge(data, lp, mid, rp);

}

