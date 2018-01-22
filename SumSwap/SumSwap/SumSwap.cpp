// SumSwap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>


using namespace std;

// With two arrays find numbers to swap that give two arrays the same sum
//  Array A  and Array B  sum of A and sum of B  will differ by a delta number
//  this delta will be the difference between the two elements in arrays
//  We find these two that give delta and then swap them


int main()
{
	int A[] = {4,1,2,1,1,2};
	int B[] = {3,6,3,3};
	int sizeA = sizeof(A) / sizeof(A[0]);
	int sizeB = sizeof(B) / sizeof(B[0]);
	int sumA = 0;
	int sumB = 0;
	int diff = 0;
	int hashA[10] = { 0 };
	int hashB[10] = { 0 };
	int numA = 0;
	int numB = 0;
	

	for (int i = 0; i < sizeA; i++)
	{
		sumA += A[i];
		hashA[A[i]]++;
	}

	for (int i = 0; i < sizeB; i++)
	{
		sumB += B[i];
		hashB[B[i]]++;
	}

	diff = abs(sumA - sumB);

	// Check the two hash lists for a difference of diff
	// Also check for a positive value
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (hashA[i]>0 && hashB[j]>0)
			{
				if (abs(i - j) == diff)
				{
					numA = i;
					numB = j;
					break;
				}
			}
		}

	}

	//for (int i = 0; i < 10; i++)   // if diff - i is in hashb then we found it  hashb[diff=i]== true 
	//{
	//	if (hashA[abs(diff - i)] == 0)
	//	{
	//		numA = i;
	//	}

	//	if (hashB[abs(diff - i)] == 0)
	//	{
	//		numB = i;
	//	}
	//}

	cout << "Num A " << numA << " Num B " << numB << endl;


	system("pause");
    return 0;
}

