// Debugger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

int main()
{
	int Num;
	int result = 0;
	cout << "enter a number " << endl;
	cin >> Num;

	result = Num & (Num - 1);
	
	cout << "The result of Num &(Num-1) is " << (result ? " Not a multiple of 2 " : " Multiple of 2 " )<< endl;
	cout << "The reason is we are shifting bits right and anding the two together" << endl;

	system("pause");
    return 0;
}

