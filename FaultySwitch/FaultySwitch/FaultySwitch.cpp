// FaultySwitch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;


int main()
{
	bool swit[] = { false,true,false,true };
	int size = sizeof(swit) / sizeof(swit[0]);
	bool bulbsOn = false;
	// Need to turn on all bulbs
	int count = 0;

		for (int i = 0; i < size; i++)
		{
			// set a switch
			if (swit[i] == false)
			{
				swit[i] = true;
				// flip remaining switches
				for (int k = i+1; k < size; k++)
				{
					swit[k] ? swit[k] = false : swit[k] = true;
				}
			}
			count++;
		}

		// Check



	cout << "The number of presses is " << count << endl;

	system("pause");
    return 0;
}

