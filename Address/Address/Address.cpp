// Address.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ostream>
#include <iostream>

using namespace std;

typedef struct MyStruct
{
	int age;
	char name[20];
}MyStruct;

int main()
{
	cout << "Welcome ";
	// find sizeof data structure 
	MyStruct *ptr = NULL;
	ptr++;
	cout << "Sizeof structure is " << ptr << endl;

	getchar();
    return 0;
}

