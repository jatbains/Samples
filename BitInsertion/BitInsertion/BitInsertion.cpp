// BitInsertion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int Num1 = 1024;
	int Num2 = 19;
	int result = 0;
	int mask = 1;
	int i = 2;
	int j = 6;

	cout << "This will merge two numbers " << endl;

	// Left shift Num2 i bits
	Num2 <<= i;
	// Or the two numbers
	// Create space in Num1
	for (int k = 0; k < j; k++)
	{
		mask |= (1 << k);
	}
	// Use this mask

	result = Num1 | Num2;

	cout << "The result is " << result << endl;


	system("pause");
    return 0;
}

