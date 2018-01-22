// Knapsack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>		

using namespace std;

// This solves the knapsack problem by recursion

int MaxValue(int x, int y);

int KnapSack(int W, int wt[], int val[], int n);

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int  W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	

	cout << "Maximum value is " << KnapSack(W, wt, val, n) << endl;



	system("pause");
    return 0;
}

int KnapSack(int W,int wt[], int val[],int n)
{
	if (W == 0 || n == 0)  // Base case
		return 0;

	// We can't add the nth element weight is too much
	if (wt[n - 1] > W)
		return KnapSack(W, wt, val, n - 1);

	else
		return (MaxValue(val[n - 1] + KnapSack(W-wt[n-1], wt, val, n - 1), KnapSack(W , wt, val, n - 1)));


}

int MaxValue(int x, int y)
{
	return (x > y ? x : y);
}