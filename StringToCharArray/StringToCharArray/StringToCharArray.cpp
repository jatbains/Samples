// StringToCharArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
char * StringToChar(string input);

int main()
{
	string greet = "Welcome to Windows";
	char *cGreet = nullptr;
	int len = greet.length();

	cGreet = StringToChar(greet);

	for (int i = 0; i < len; i++)
	{
		cout << cGreet[i];
	}
	cout << endl;

	system("pause");
    return 0;
}

char * StringToChar(string input)
{
	int len = input.length();
	char *arr = (char *)malloc(len * sizeof(char));
	// Copy elements over
	for (int i = 0; i < len; i++)
	{
		arr[i] = input[i];
	}
	return arr;
}