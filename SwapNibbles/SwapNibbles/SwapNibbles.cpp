// SwapNibbles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int SwapNibbles(int num);

int main()
{
	int num = 0;
	int mask = 0xFFFF;
	int temp;
	int num2 = num;
	cout << "Enter a number " << endl;
	cin >> num;
	num2 = num;
	char *x = (char *)&num2;
	// Get lower nibbles
	temp = num & mask;    // mask off top two bytes
	num >>= 16;       
	num = num | (temp << 16);

	cout << num << endl;

	cout << endl;

	cout << (((num2 & 0X0F) << 4) | ((num2 & 0xF0) >> 4)) << endl;


	for (int i = 1; i <= 4; i++)
	{

		*x = (((*x & 0x0F) << 4) | ((*x &  0xF0) >> 4));
		x++; // move to next byte

	}

	cout << num2 << endl;

	//cout << SwapNibbles(num2);

	cout << endl;

	system("pause");
    return 0;
}

int SwapNibbles(int num)
{ 
	int lmask = 0x0F;  // 4 bits
	int hmask = 0xF0;  // Upper 4 bits
	int loc = num;
	char *x = (char *)&loc;
	// Swapping nibbles is 4 bits of each byte

	for (int i = 1; i <= 4; i++)
	{

		*x = (((*x & lmask ) << 4) | ((*x &  hmask) >> 4));
		x++; // move to next byte

	}

	cout << num << endl;
	return num;

}
