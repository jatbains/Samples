// RotateBits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define INT_BITS 32

int LeftRotateBits(int num, int d);
int RightRotateBits(int num, int d);

int main()
{ 
	int num = 0;  // Input a number an rotate the bits of the number
	int d = 0;
	cout << "Please enter a number " << endl;
	cin >> num;
	cout << "Please enter how many spaces to shift " << endl;
	cin >> d;

	cout << "The left rotated number is " << LeftRotateBits(num,d) << endl;
	cout << "The right rotated number is " << RightRotateBits(num, d) << endl;

	system("pause");
    return 0;
}

int LeftRotateBits(int num, int d)
{
	// Rotate the bits  d posiions left and OR with 32-d shifts to right
	return (num << d) | (num >> INT_BITS - d);
	
}
int RightRotateBits(int num, int d)
{
	// Rotate the bits  d posiions left and OR with 32-d shifts to right
	return (num >> d) | (num << INT_BITS - d);

}