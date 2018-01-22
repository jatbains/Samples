// MissingNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int ReturnMissingNum(const char *num);

int main()
{
	const char num[] = { "11122233344455666" };


	cout << ReturnMissingNum(num) << endl << endl;


	system("pause");	
    return 0;
}

int ReturnMissingNum(const char *num)
{
	const char *p = num;
	int hash[10] = { 0 };

	while (*p != '\0')
	{
		hash[*p - '0']++;
		p++;
	}

	// Check the hash table
	for (int i = 0; i < 10; i++)
	{
		if (hash[i] == 2)
			return i;
	}

}

