// Pairwise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;



int main()
{
	int num = 0;
	int even = 0xAAAAAAAA;
	int odd = 0x55555555;
	

	// We get the even bits and odd bits do a shift and or them together
	cout << "Enter a number " << endl;
	cin >> num;

	num = ((num&even) >> 1) | ((num &odd) << 1);

	cout << "Number is " << num << endl;


	system("pause");
    return 0;
}

