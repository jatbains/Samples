// 2DAlloc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void * TwoDAlloc(int i, int j);

int main()
{

	void *p = TwoDAlloc(5, 5);
	int count = 0;
	cout << "Address of p is " << p << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			*((int*)p + i*5 + j) = count++;
		}
	}


	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << ((int*)p + i * 5 + j) << "  " <<  *((int*)p + i * 5 + j) << endl;
		}
	}

	system("pause");
    return 0;
}

void * TwoDAlloc(int i, int j)
{
	// Allocate enough memory for a i x j integer 2d array
	int size = sizeof(int);  // Bytes for integer 
	int vsize = sizeof(void *);
	// Size of memory for two D array will be  
	void *p = (void *)malloc(i*j*size);

	return p;
}