// StringRotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	char *s1 = "waterbottle";
	char *s2 = "erbottlewat";
	char *c1 = s1;
	char *c2 = s2;
	int count = 0;
	bool rot = false;
	// How to determine is one is a rotation of another
	// Move bothe pointers until the values are the same then wrap aroound 
	// the one you had to increment

	while (*c1 != '\0' && *c2 != '\0')
	{
		if (*c1 != *c2)
		{
			c1++;
			count++;
		}
		else {
			c1++;
			c2++;

		}

	}
	// Reached here count will give how much s1 was moved forward 
	// and how much s2 is left to move
	c1 = s1;  // Start at beginning again
	while (*c2 != '\0' && count>0)
	{
		if (*c1 != *c2)
		{
			// Not equal
			cout << "Not a Rotation " << endl;
			break;
		}
		else
		{
			c1++;
			c2++;
			count--;

		}
			
	}
	// Here if count is zero and c2 is \o the rotate
	if (count == 0 && *c2 == '\0')
	{
		cout << "It is a Rotation " << endl;
	}
	else
	{
		cout << "Not a rotation" << endl;
	}

	system("pause");
    return 0;
}

