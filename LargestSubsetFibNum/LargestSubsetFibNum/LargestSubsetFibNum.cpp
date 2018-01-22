// LargestSubsetFibNum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int FibNum(int n)
{
	if (n <= 1)
		return n;
	return(FibNum(n - 1) + FibNum(n - 2));
}

bool FibSearch(int *fib, int x);
bool FibRecurse(int *fib, int lw, int hi, int val);

int fib[20] = { 0 };

int main()
{
	int num = 0;
	int arr[] = { 1, 4, 3, 9, 10, 13, 7 };
	int hash[20] = { 0 };
	bool isfib = false;
	int size = sizeof(arr) / sizeof(arr[0]);
	// In an array dtermine the numbers which are fibonacci

	for (int i = 0; i < size; i++)
	{
		hash[arr[i]] = 1;  // Turn on bits for array values  sorted in hash O(N)
	}
	// Test each number with routine
	for (int i = 0; i < 20; i++)
	{
		fib[i] = FibNum(i);
	}
	// Check in the table
	for (int i = 0; i < 20; i++)
	{
		if (hash[i] == 1)
		{
			// Check the hash table with binary search
			isfib = FibSearch(fib, i);
			cout << "The number " << i << (isfib ? " Is a Fibonacci num" : " Is not a Fibonacci num") << endl << endl;
		}
	}

	system("pause");
    return 0;
}

bool FibSearch(int *fib, int x)
{
	// Call Recurse
	return FibRecurse(fib, 0, 20 - 1, x);

}
bool FibRecurse(int *fib, int lw, int hi,int val)
{
	if (lw >= hi)
		return false;
	int mid = (lw + hi) / 2;
	// Search left or right
	if (fib[mid] == val)
		return true;
	if (val < fib[mid])
		return FibRecurse(fib, lw, mid-1, val);
	else
		return FibRecurse(fib, mid+1, hi, val);

}
