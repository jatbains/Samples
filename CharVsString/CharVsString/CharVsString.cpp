// CharVsString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;


int main()
{
	const char *literal = "Engineering";  // Const string literal can't be modified
	char myString[] = "Engineering";        // Array of characters

	//literal[3] = '\0';    // Can't be modified

	myString[8] = '\0';

	cout << myString << endl;

	system("pause");
    return 0;
}

