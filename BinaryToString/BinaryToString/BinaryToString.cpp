// BinaryToString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	double Num = 0.72;
	int temp = 0;
	string number;
	int mask = 1,count = 32;
	cout << "Enter a real number " << endl;
	//cin >> Num;

	for ( int j = 1; j <= 32; j++)
	{
		// shifting the mask and display the number
		mask = 2 * j;
		temp = Num*mask;
		if (temp & mask)
		{
			number += to_string(1);
		}
		else
		{
			number += to_string(0);
		}

	}
	cout << "Number in binary is  " << number << endl;

	system("pause");
    return 0;
}

