// BitReversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ostream>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int val;
	int i = 1;
	int reverse = 0;
	std::cout << "Enter Value "  << endl;
	std::cin >> val;

	std::cout << "Value is " << val << endl;


	for (int j = 0; j < 32; j++)
	{
		reverse <<= 1;
		reverse |= val & 1;
		val >>= 1;		
	}

	std::cout << "Flipped val is " << reverse << endl;

	getchar();
	getchar();
    return 0;
}

