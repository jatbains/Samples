// time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
#include <sys/timeb.h>

using namespace std;


int main()
{
	// Sawp two numbers
	int a = 10;
	int b = 15;

	cout << "a is " << a << "  " << "b is " << b << endl;

	b = a + b; // b is 25
	a = b - a;  // a is 15
	b = b - a;  // b is 10

	cout << "a is " << a << "  " << "b is " << b << endl;

	system("pause");
    return 0;
}

