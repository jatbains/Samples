// Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int Num[20] = { 3,5,8,5,10,21,14,20,18,13,9,19,25,23,7,30,17 };
	int *p = Num;
	int val = 0;

	cout << "Enter num to find " << endl;
	cin >> val;

	for (int i = 0; i <20;i++)
	{
		if (*p == val)
			cout << "Value was found" << endl;
		p++;
	}


	getchar();
    return 0;
}

