// WaysClimbing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

int WaysClimbing(int n);

int main()
{
	int num = 0;
	cout << "Enter the number of total steps" << endl;
	cin >> num;

	cout << "Total ways is " << WaysClimbing(num) << endl;

	system("pause");
    return 0;
}

int WaysClimbing(int n)
{
	// The number of ways of climbing will be 
	// Ways(n-1) + Ways(n-2) + Ways(n-3)
	//  n is the total number of steps
	if (n <= 2)
		return n;   // No more steps left to climb

	return (WaysClimbing(n - 1) + WaysClimbing(n - 2) + WaysClimbing(n - 3));

}

