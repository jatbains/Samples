// MultipleofNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

int static const MAX_STRING = 20;

int main()
{
	
	char *val = "11001011010";
	char *c = NULL;
	int power = 1;
	int num = 0;
	
	unsigned int x = 5;
	c = val;
	
	cout << "Enter a number to check for divisibility" << endl;
	cin >> x;


	while (*c != '\0')
	{
		c++;
	}
	c--;
	// Start processing in reverse
	 
	while (c >= val)
	{
		num += (*c-'0')*power;
		power *= 2;
		c--;
	}

	cout << "Number is " << num << endl;

	cout << ((num%x) == 0 ? "Divisible by " : "Not divisible by ") << x << endl;

	system("pause");
    return 0;
}

