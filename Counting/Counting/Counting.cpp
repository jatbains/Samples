// Counting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class SR 
{
private:
	int value;
	int &copy;
public:
	SR(int &x)
	:value(x),copy(x)
	{}
	~SR()
	{
		copy = value;
	}


};

int main()
{
	int x = 0;
	int sum = 0;

	{
		SR mySR(x);

		for (int i = 0; i < 100; i++)
		{
			x += i;
			cout << x << endl;
		}

	}

	cout << x << endl;
	

	for (int i = 0; i <= 100; i++)
	{
		{
			SR my(i);
			while (i--)
			{
				sum += i;

			}
		}

	}

	cout << sum << endl;


	system("pause");
    return 0;
}

