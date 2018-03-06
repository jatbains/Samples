// MultiplyStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// This programs will take two strings of numbers and 
// convert them into integers multiply them and then convert back into a string

int StringToInt(char *s);
char * IntoToString(int x);

const static int MAX_NUM = 20;

int main()
{
	char *n1 = "254";
	char *n2 = "23";
	int num1 = 0;
	int num2 = 0;
	int mul = 0;
	char *mulstr= NULL;

	num1 = StringToInt(n1);
	num2 = StringToInt(n2);

	mul = num1*num2;

	cout << "Number is " << mul << endl;

	mulstr = IntoToString( mul);

	cout << "String is " << mulstr << endl;

	system("pause");
    return 0;
}

int StringToInt(char *s)
{
	char *c = s;
	int num = 0;
	int power = 1;
	while (*c != '\0')
		c++;
	c--;  // one less to end of string  going backwards add into number
	while (c >= s)  // while its address is greater
	{
		num += (*c - '0')*power;
		power *= 10;
		c--;
	}

	return num;  // base 10 integer
}
char * IntoToString(int x)
{
	char *c = (char*)malloc(sizeof(char)*20);
	char *s = c;
	int i = 0;
	// end of the array
	int power = 1;
	int num = x;
	int digit = 0;
	while (x / power > 0)
	{
		x /= power;
		power *= 10;
		i++;
	}
	// Power will be 10 * more than needed


	while (num > 10)
	{
		digit = num / power;
		num = num - digit*power;

		*c = digit + '0';
		power /= 10;
		c++;

	}
	// uppermost digit
	*c = num + '0'; // 1s digit remainder is in num
	c++;
	*c = '\0'; // terminate string

	return s;
}

