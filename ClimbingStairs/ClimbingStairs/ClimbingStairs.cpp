// ClimbingStairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int NumberofWays(int n);
int TotalWays(int n);

int main()
{
	int N = 0;
	cout << "Enter the total stairs" << endl;
	cin >> N;

	cout << NumberofWays(N) <<  " Ways" << endl;

	system("pause");
    return 0;
}

int NumberofWays(int n)
{
	return TotalWays(n+1);
}

int TotalWays(int n)
{
	if (n <= 1)
		return n;

	return (TotalWays(n - 1) + TotalWays(n - 2));

}