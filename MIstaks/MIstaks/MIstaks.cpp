// MIstaks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int i; // Can't use unsigned int

	for (i = 100; i >= 0; i--)
	//for (i = 0; i <=100;i++)
		printf("%d\n", i);

	system("pause");
    return 0;
}

