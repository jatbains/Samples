// RecurseMultiply.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	cout << "Recursive Multiply" << endl;
	cout << "Enter two numbers" << endl;
	cin >> num1;
	cin >> num2;

	for (int i = 1; i <= num1; i++)
	{
		sum += num2;
	}


	cout << "The sum is " << sum << endl;

	system("pause");
    return 0;
}

