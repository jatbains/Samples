// Atoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int atoi(char *s);

int main()
{
	char *num = "20";


	cout << "Number is " << atoi(num) << endl;

	system("pause");
    return 0;
}

int atoi(char *s)
{
	char *c = s;
	int power = 1;
	int sum = 0;

	while (*c != '\0')
	{
		sum = sum*power + (*c - '0');
		power *= 10;
		c++;
	}
	
	return sum;
}