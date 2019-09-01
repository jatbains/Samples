// PairSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int num[] = { 1,3,5,8,10,12 };  // Sorted in Ascending order
	int sum = 13;
	bool numHash[100] = { 0 };  // Hash table
	int num1 = 0;
	// Find two numbers that sum to 13

	for (int i = 0; i <= 5 ; i++)
	{
		num1 = sum - num[i];
		if (numHash[num1] == true)
		{
			cout << "Numbers are " << num[i] << "  and  " << num1 << endl;
			break;
		}
		// turn on found num
		numHash[num[i]] = true;
	}


	getchar();
	return 0;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
