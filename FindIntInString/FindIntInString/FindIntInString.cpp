// FindIntInString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
void TestImmutability(string s1, char s2[]);
int FindIntInString(string input);

int main()
{
	string name = "Jim Bains";
	char address[] = " 9770 Rancho Hills ";
	const char *country = "United States";
	string intInString = "927367bsjjbcajbcak";
	int largeNum = 0x7FFFFFFF;
	unsigned int vlarge = 0xFFFFFFFF;

	const char *p = country;
	
	

	TestImmutability(name, address);

	cout << "Number is " << FindIntInString(intInString) << endl;

	cout << "Large Number is " << largeNum << endl;

	largeNum++;

	cout << "Large Number is now " << largeNum << endl;

	cout << "Very large is  " << vlarge << endl;

	vlarge++;

	cout << "Very large is now " << vlarge << endl;

	system("pause");
    return 0;
}
int FindIntInString(string input)
{
	int power = 1;
	int num = 0;
	bool sign = true;
	int digits = 0;
	int prevSum = 0;
	// reverse the string
	reverse(input.begin(), input.end());

	// Process in reverse
	for (int i = 0; i < input.length(); i++)
	{
		if (input[0] == ' - ')
		{
			sign = false;
		}
		if ((input[i] >= '0') && (input[i] <= '9'))
		{
			num += (int)((input[i] - '0') *power); // Digits being accumulated
			power *= 10;                             // Power can 10^10 ?? 

													//  Check for overflow
													//   2147483648 + 1 = 0 
			if (num < prevSum)
			{  // We wrapped around send an error
				return -1;
			}
			prevSum = num;
		}
	}
	// Set the sign if negative
	if (!sign)
	{
		num *= -1;
	}
	return num;

}

void TestImmutability(string s1, char s2[])
{
	s1[3] = 'x';
	s2[0] = '2';

	cout << s1 << " " << s2 << endl;
}