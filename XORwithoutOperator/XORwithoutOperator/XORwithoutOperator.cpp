// XORwithoutOperator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// Wish to determmine the XOR od two numbers without operator
//  XOR will be the | of two numbers & with the ! of the & operation

int main()
{
	int num1 = 0;
	int num2 = 0;
	int out = 0;
	

	cout << "Enter a number " << endl;
	cin >> num1;
	cout << "Enter a number" << endl;
	cin >> num2;


	
	out = (num1 | num2) & (~(num1 & num2));
	                                       // Inverse of the intersection


	cout << "XOR is " << out << endl;



	system("pause");
    return 0;
}

