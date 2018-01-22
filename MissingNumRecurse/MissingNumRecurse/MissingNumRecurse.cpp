// MissingNumRecurse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int RecurseFindNum(int data[], int lpos, int rpos);

int main()
{
	int data[] = { 0,1,2,3,4,5,7,8,9,10 };
	// Find missing integer
	int size = sizeof(data) / sizeof(data[0]);
	//The property of the missing integer is a[i+1]-a[i] != i+1-i != 1

	// Recursively divide into sub arrays and look for that property

	cout << "The missing Integer is " << RecurseFindNum(data, 0, size-1) << endl;


	system("pause");
    return 0;
}

int RecurseFindNum(int data[],int start,int end)
{
	if (end < start)
		return -1; // not found means Ok
	else {
		int mid = (start + end) /2;

		if (mid - start == 1 && data[mid] - data[start] > 1)
			return data[mid] - 1;
		if (end - mid == 1 && data[end] - data[mid] > 1)
			return data[mid] + 1;

		if (data[mid] - data[start] != mid - start) {
			return RecurseFindNum(data,start, mid);
		}
		else if (data[end] - data[mid] != end - mid) {
			return RecurseFindNum(data,mid, end);
		}

	}

}
