// CircularSeating.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int data[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int count = 0;
	int index = 0;
	int loop = 0;
	int skip = 3;
	int size = sizeof(data) / sizeof(data[0]);
	// Print out the elements ever third and wrap around
	while (count != size)
	{
		if (data[index] != -1)
			cout << data[(index)] << endl;
		data[index] = -1;
		count++;
		index +=skip;
		if (index >= size)
		{
			loop++;
			index = loop;
		}
	}

	system("pause");
    return 0;
}

