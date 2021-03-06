// StringToInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int parseInt(string s1);

int main()
{
	string num1 = "2250";
	string num2 = "354";

	int val1 =0, val2 = 0;
	val1 = parseInt(num1);
	val2 = parseInt(num2);

	cout << "Sum is " << val1 + val2 << endl;

	system("pause");
    return 0;
}

int parseInt(string s1)
{
	int power = 1;
	const char *p = NULL;
	int sum = 0;

	p = s1.c_str();

	while (*p != '\0')
		p++;

	p--;    // last digit in number

	while (p != s1.c_str())
	{
		sum += (*p-'0') * power;
		power *= 10;
		p--;
	}
	// Get the last digit
	sum += (*p-'0') *power;

	return sum;

}