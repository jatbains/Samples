// BitFlips.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int countOnes(int n);

int main()
{
	int array[] = { 1,0,1,1,0,0,0 };
	int num = 0;
	int size = sizeof(array) / sizeof(array[0]);
	int power = 1;
	int mask = 1 << 3;
	// Get the number
	for (int i = 0; i < size; i++)
	{
		num += array[size - 1 - i] * power;   // Multiple number time power of two
		power *= 2;                           // Becomes the power
		
	}

	cout << "Number is " << num << endl;

	cout << " The number of ones is " << countOnes(num) << endl;

	num = num^mask;

	cout << "Number is " << num << endl;

	system("pause");
    return 0;
}

int countOnes(int n)
{
	int count = 0;
	while (n > 0)
	{
		n = n & (n - 1);
		count++;

	}
	return count;
}

