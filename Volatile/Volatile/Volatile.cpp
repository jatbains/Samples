// Volatile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

int main()
{
	volatile int x = 1;
	// We can use this in a loop it can be modified outside program

	while (x)
	{
		cout << "Hello ";
	}


    return 0;
}

