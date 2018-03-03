// VariableArgs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdarg.h>
#include <iostream>

using namespace std;
int Multiply(int x, ...);
void test1();
void test2(void);

int main()
{
	cout << Multiply(2, 10, 15) << endl;
	cout << Multiply(3, 4, 5, 6) << endl;

	cout << Multiply(4, 7, 7, 9, 9) << endl;

	cout << endl;
	test1();
	test2();

	system("pause");
    return 0;
}

void test1()
{
	cout << "Hello" << endl;
}

void test2(void)
{
	cout << "Bye" << endl;
}
int Multiply(int x, ...)
{
	va_list list;     // list of args  pointer to array

	int result = 1;

	// initialize the list 
	va_start(list, x);

	for (int i = 0; i < x; i++)
	{
		result *= va_arg(list, int);
	}

	va_end(list);

	return result;
}
