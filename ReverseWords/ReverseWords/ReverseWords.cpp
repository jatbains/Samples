// ReverseWords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
void ReverseWord(char *p);

int main()
{
	string mySentence;
	cout << "Enter a sentence" << "\n";
	
	getline(cin, mySentence);
	
	char *s = &mySentence[0];
	char *p = NULL;
	while (*s != '\0')
	{
		if (p == NULL)
		{
			ReverseWord(s);
		}
		if (p != NULL && *p == ' ')
		{
			// Reverse word
			ReverseWord(s);

		}

		p = s;
		s++;
	}


	cout << "Reversed is " << "\n" << mySentence << "\n";

	getchar();
	return 0;
}

void ReverseWord(char *p)
{
	char *t = p;
	char temp;
	while (*t != ' ' && *t != '\0')
	{
		t++;
	}
	// backup one
	t--;
	// Swap chars
	while (p < t)
	{
		temp = *p;
		*p = *t;
		*t = temp;
		p++;
		t--;
	}

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
