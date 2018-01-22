// NumberAppearingOnce.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

int Linear(int data[], int size);

int main()
{
	int data[] = { 1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65 };
	int size = sizeof(data) / sizeof(data[0]);
	int num = 0;
	
	// Find number appearing once
	// Binary search at base condition difference = 0 except for 1 case

	//num = MissingRecur(data, 0, size - 1);
	num = Linear(data,size);

	cout << "Num is " << num << endl;


	system("pause");
    return 0;
}

int Linear(int data[], int size)
{
	int diff = 0;
	int hash[100] = { 0 };
	for (int i = 0; i < size; i++) 
	{
		hash[data[i]]++;	
	}
	for (int i = 0; i < 100; i++)
	{
		if (hash[i] == 1)
			return i;
	}
}

