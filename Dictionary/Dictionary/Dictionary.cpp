// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>


using namespace std;


int main()
{
	std::map<int, string> LookupTable;
	LookupTable[0] = "Rhea Bains";
	LookupTable[1] = "Jimmy Bains";
	LookupTable[2] = "Charles Barkley";
	LookupTable[3] = "Rani Bains";
	string hello = "Hello World";

	cout << hello << endl << endl;

	// Loop through all the values and print them out 
	for (map<int, string>::value_type &x : LookupTable)
	{
		cout << x.first << "," << x.second << endl;
	}


	system("pause");
    return 0;
}

