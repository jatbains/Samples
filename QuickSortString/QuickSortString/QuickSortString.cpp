// QuickSortString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;
void QuickRecur(char s[], int l, int r);
int PartitionString(char s[], int l, int r);

int main()
{
	char s1[] = {'b','i','r','t','h','d','a','y'};
	int size = sizeof(s1) / sizeof(s1[0]);

	QuickRecur(s1, 0, size-1);

	for (int i = 0; i < size; i++)
		cout << " " << s1[i] << " ";

	cout << endl << endl;

	system("pause");
    return 0;
}

int PartitionString(char s[], int l,int r)
{
	// Sort aroung the pivot
	int mid = l + (r - l) / 2;     // This is the pivot character
	char c = s[mid];

	while (l <= r)
	{
		while (s[l] < c)
		{
			l++;
		}
		while (s[r] > c)
		{
			r--;
		}
		
		// Swap the characters
		if (l <= r)
		{
			char t = s[l];
			s[l] = s[r];
			s[r] = t;
			l++;
			r--;
		}

	}
	return l;
}

void QuickRecur(char s[], int l, int r)
{
	// Base case will be reached when l==r
	if (l == r)
		return;
	
	// Partition the string and recursively sort the string

	// Partition the string
	int index = PartitionString(s, l, r);
	if (l < index - 1)
		QuickRecur(s, l, index - 1);
	if (index < r)
		QuickRecur(s, index, r);

}