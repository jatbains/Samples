// NumberKTimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;



int main()
{
	int data[] = { 1, 7, 4, 3 ,4 ,8, 7 };
	int k = 2;
	int hash[20] = { 0 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		hash[data[i]]++;
	}
	// Just check the hash table
	for (int i = 0; i < 20; i++)
	{
		if (hash[i] == k) 
		{
			cout << "Value " << i << " Repeated " << k << " times " << endl;
		}
	}




	system("pause");
    return 0;
}

