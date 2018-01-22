// RecurseBinary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int BSSearch(int data[], int l, int r,int x);


int main()
{
	int data[] = { 5,9,13,17,21,25,29 };
	int x = 15;
	// Find x
	int size = sizeof(data) / sizeof(data[0]);
	// Binary search
	
	
	cout << (BSSearch(data, 0, size - 1, x) ? "Found Number" : "Number not found") << endl;
	
	system("pause");
    return 0;
}
int BSSearch(int data[], int l, int r,int x)
{
	if (l > r)
		return 0;  // Not found
	int mid = l+ (r-l) / 2;
	if (data[mid] == x) {
		return 1;
	}
	// Else recurse
	if (data[mid] > x)
		return BSSearch(data, l, mid - 1, x);
	else
		return BSSearch(data, mid + 1, r, x);

	return -1;
}
