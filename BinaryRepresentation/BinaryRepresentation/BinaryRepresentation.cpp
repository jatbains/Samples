// BinaryRepresentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;



int main()
{
	int num = 0;
	unsigned int mask = 0x80000000;
	cout << " Enter a number " << endl;
	cin >> num;

	while (mask)
	{
		if (num&mask)
		{
			cout << "1";
		}
		else
		{
			cout << "0";
		}

		mask >>= 1;
	}
	cout << endl;

	system("pause");
    return 0;
}

