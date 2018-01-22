// WordFreq.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	// A book is unordered text 
	// The only search that can be employed is linear
	// If doing it multiple times sorting the book into a
	// BST would make sense.
	// Mechanism employed is define a int array with each entry a frequency 
	// of the characters in the word.  Next go through the book character by character
	// comparing with this array.

	char word[] = "Population";
	char *c = NULL;
	int num = 0;
	int val = 0;
	int map[26] = { 0 };

	c = word;
	// Go through the word
	while (*c != '\0')
	{
		//cout << " c is " << endl
		val = *c;
		
		if (val >= 'a' && val <= 'z') {
			num = (val - 'a');
		}
			
		if (val >='A' && val <= 'Z') {
			num = (val - 'A');
		}		
	
		map[num]++;
		c++;

	}

	for (int i = 0; i < 26; i++)
	{
		cout << " " << map[i] << " " << endl;
	}

	system("pause");
    return 0;
}

