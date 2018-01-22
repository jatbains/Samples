// SparseNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h" 
#include <iostream>

using namespace std;


int main()
{
	int num = 0;  // Sparse number has no two 1s together
	int even = 0xAAAAAAAA;
	int odd = 0x55555555;   // if the number XOR with either gives all zeros the sparse
	bool hash[32] = { 0 };
	cout << "Enter a number " << endl;
	cin >> num;

	
	for (int i = 0; i < 32; i++)
	{
		if (num & 1 << i)
		{
			hash[i] = true;
		}
	}

	for (int i = 0; i < 31; i++)
	{
		if (hash[i] & hash[i + 1])
		{
			cout << "Not a Sparse Number " << endl;
		}
	}

	system("pause");
    return 0;
}

