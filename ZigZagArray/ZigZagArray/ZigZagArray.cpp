// ZigZagArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// Zig Zag fashion for array means a<b>c<d>e
void ZigZagArray(int val[], int size);

int main()
{
	int data[] = { 4, 3, 7, 8, 6, 2, 1 };
	int size = sizeof(data) / sizeof(data[0]);

	// Modified Bubble Sort skip over elements don't need to swap
	// Call Zig Zag method
	for (int i = 0; i < size - 1; i++)
	{
		cout << " " << data[i] << endl;
	}

	system("pause");
    return 0;
}

void ZigZagArray(int val[], int size)
{
	bool swap = false;
	int temp = 0;
	// Do modified bubble sort
	for (int i = 0; i < size - 2; i++) {
		if (swap)
		{
			// swap elements
			if (val[i] < val[i + 1])
			{
				temp = val[i];
				val[i] = val[i + 1];
				val[i + 1] = temp;
			}
			else
			{
				if (val[i] > val[i + 1])
				{
					temp = val[i];
					val[i] = val[i + 1];
					val[i + 1] = temp;
				}
			}
		}
		swap != swap;
	}

}