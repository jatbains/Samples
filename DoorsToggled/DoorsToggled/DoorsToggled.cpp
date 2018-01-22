// DoorsToggled.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

void DoorsOpen(int num, int pass,bool *doors);

int main()
{
	int num = 0;
	cout << "Enter the number of doors" << endl;
	cin >> num;
	bool *doors = new bool[num];

	for (int i = 0; i < num; i++)
	{
		doors[i] = false;
	}

	DoorsOpen(num, 1, doors);

	for (int i = 0; i <= num; i++)
	{
		if (doors[i])
		{
			cout << "Door is Open " << i << endl;
		}
		
	}

	system("pause");
    return 0;
}

void DoorsOpen(int num,int pass,bool *doors)
{
	if (pass == num)
	{
		// We are done 
		return;
	}
	// toggle the doors
	for (int i = pass; i <= num; i += pass)
	{
		doors[i] = !doors[i];
	}

	return (DoorsOpen(num , (pass + 1),doors));
}