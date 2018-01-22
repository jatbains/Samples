// StudentLockers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

//  This program will calculate how many lockers are open after n students toggle the lockers
void lockers(int n);
void recurlock(bool loc[], int n, int i);

int main()
{
	int num = 100;   // Assume 100 students and lockers 


	lockers(num);

	system("pause");
    return 0;
}

void recurlock(bool loc[],int n,int i)
{
	if (i == n)   // base case
		return;

	for (int j = 0; j <= n; j++)
	{
		if (j*i <= n) 
		{
			loc[j*i] = !loc[j*i];
		}
	}
	// Recur until done
 	recurlock(loc, n,++i);	
}

void lockers(int n)
{
	bool *lockers = new bool[n];  // Initially all are closed
	lockers[n] = { 0 };     // solve it recursively  1 ,  2 4 6,   3 6 9  4 8 12
	int count = 0;
	recurlock(lockers, n,1);

	for (int k = 0; k <= 100; k++)
	{
		if (lockers[k])
			count++;
		cout << lockers[k] << endl;

	}
	cout << endl << "Lockers open " << count << endl;
}