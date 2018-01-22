// IPToHex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;




int main()
{
	char *ip = { "192.168.10.21" };
	// Convert to HEX 
	int numA, numB, numC, numD;
	list<int> myList;
	int num = 0;
	char *c = ip;
	char *s = ip;
	int power = 1;
	int ipAddress = 0;

	while (*c != '\0')
	{
		c++;

	}
	c--;  // Start at end 
	while (c != s)
	{

		if (*c >= '0' && *c <= '9')
		{
			num = num + (*c - '0')*power;
			power *= 10;
		}
		if (*c == '.')
		{
			myList.push_front(num);
			power = 1;
			num = 0;
		}
		c--;
	}
	// Get last digit
	//
	if (*c >= '0' && *c <= '9')
	{
		num = num + (*c - '0')*power;
		power *= 10;
		myList.push_front(num);
	}


	// List has elements in right order
	cout << endl;
	cout << hex;
	cout << "  0x";
	cout << (myList.front());
	myList.pop_front();

	cout << (myList.front());
	myList.pop_front();
	cout << (myList.front());
	myList.pop_front();
	cout << (myList.front()) << endl;

	myList.pop_front();
	cout << endl;
	system("pause");
    return 0;
}

