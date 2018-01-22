// Bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	int i = 0,total=0;
	int mask = 1;
	int count = 0;

	printf("Enter a number\n");
	scanf_s("%d", &count);

	total = count & (count - 1);
	printf("Total is %d\n", total);

	total = 0;

	for (i = 0; i < 32; i++)
	{
		if (count & mask)
		{
			total++;
		}
		count = count >> 1;

	}

	printf("Number of bits is %d \n", total);

	getchar();
	getchar();
    return 0;
}

