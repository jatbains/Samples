// MagicIndex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int MagicNumber(int magic[], int start, int end);

int main()
{
	int magic[] = {-40,-20,-1,1,2,3,5,7,9,12,13 };
	int size = 0;
	cout << "Find the magic index in an array " << endl;
	
	size = sizeof(magic) / sizeof(magic[0]);
	cout << "Magic number found " << MagicNumber(magic, 0,size) << endl;


	system("pause");
    return 0;
}

int MagicNumber(int magic[], int start, int end)
{
	if (end < start)
		return -1;
	// Sorted Array  Property of sorted array

	// If magic[index] < index values are increasing else the other way
	int mid = (start + end) / 2;
	if (magic[mid] == mid)
	{
		return mid;
	}
	else if (magic[mid] > mid)
	{ // search left 
		
		return MagicNumber(magic,start,mid-1);
	}
	else
	{ // search right
		
		return MagicNumber(magic,mid+1,end);
	}
	return 0;
}