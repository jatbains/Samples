// ExclusiveOr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num;
	cout << "Enter a number" << endl;
	cin >> num;

	cout << "XOR is " << (num^num) << endl;


	system("pause");
    return 0;
}

