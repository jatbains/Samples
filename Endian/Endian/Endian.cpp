// Endian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;




int main()
{
	int num = 1;  // Bit i in LSB is on
	char *c = NULL;   // 1 Byte in first bit of byte

	// Test 
	c =(char *) &num;  // c points to lowest byte of int

	if (*c & 1)
	{
		cout << "Little Endian" << endl;
		
	}
	else
	{
		cout << "Big Endian" << endl;
	}

	// Print out address of c
	for (int i = 1; i <= 4; i++)
	{
		printf("Address is %x\n", c);
		c++;
	}


	system("pause");
    return 0;
}

