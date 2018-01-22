// MergeSortString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void mergeRecur(char s[], int l, int r);
void mergeArrays(char s[], int l, int m, int r);


int main()
{
	char s[] = { 'b','i','r','t','h','d','a','y' };
	int size = sizeof(s) / sizeof(s[0]);
	mergeRecur(s, 0, size - 1);

	for (int i = 0; i < size; i++) {
		cout << " " << s[i] << " ";
	}

	cout << endl << endl;

	system("pause");
    return 0;
}

void mergeArrays(char s[], int l, int m, int r)
{
	// create sub arrays of smaller sizes
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	char *L = new char[n1];
	char *R = new char[n2];

	// Copy data into temp arrays   from the subset of values
	for (int i = 0; i < n1; i++)
	{
		L[i] = s[l+i];     
	}
	for (int j = 0; j < r; j++)
	{
		R[j] = s[m + j + 1];
	}

	// Next we merge the smaller values back into main array
	i = 0;    // Index of 1st subarray
	j = 0;    // Index of second subarray
	k = l;    // Initial index of merged array

	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])     // L is smaller
		{
			s[k] = L[i];
			i++;
		}
		else
		{
			s[k] = R[j];
			j++;
		}
		k++;

	}

	// Copy remaining elements if any
	while (i < n1)
	{
		s[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		s[k] = R[j];
		j++;
		k++;
	}

}

void mergeRecur(char s[], int l, int r)
{
	if (l == r)     // Base case
		return;
	// Get midpoint then partition the array 
	// Merge the subarrays back into main
	int mid = (l + r) / 2;

	mergeRecur(s, l, mid);
	mergeRecur(s, mid + 1, r);

	mergeArrays(s, l, mid, r);

}
