// Power.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int Power(int x, int y);


int main()
{

	cout << Power(4, 4) << endl;

	system("pause");
    return 0;
}

int Power(int x, int y)
{ 
	int num = 1;
	// Calculate x^y
	for (int i = 1; i <= y; i++)
	{
		num *= x;
	}

	return num;

}