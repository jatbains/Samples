// VariableArguments.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdarg.h>

using namespace std;
int Variable(int argc, ...);

int main()
{
	cout << "Passing Variable arguments to function" << endl;

	cout << "Max is " << Variable(5, 20, 5, 7, 21, 16) << endl;



	system("pause");
    return 0;
}


int Variable(int argc, ...)
{
	// Passing variable arguments
	int a=0, max= 0;

	va_list ap;
	//char *list;

	va_start(ap, argc);

	max = va_arg(ap, int);
	
	cout << max << endl;

	for (int i = 2; i <= argc; i++)
	{
		a = va_arg(ap, int);
	
		if (a > max)
			max = a;
		cout << a << endl;
	}

	va_end(ap);
	return max;
}