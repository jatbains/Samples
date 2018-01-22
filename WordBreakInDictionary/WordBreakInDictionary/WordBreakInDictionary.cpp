// WordBreakInDictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


bool CheckDictionary(string word);
bool wordBreak(string word);

int main()
{
	wordBreak("ilikesamsung") ? cout << "Yes" << endl : cout << "No" << endl;
	wordBreak("iiiiiiii") ? cout << "Yes" << endl: cout << "No" << endl;
	wordBreak("") ? cout << "Yes" << endl: cout << "No" << endl;
	wordBreak("ilikelikeimangoiii") ? cout << "Yes" << endl: cout << "No" << endl;
	wordBreak("samsungandmango") ? cout << "Yes" << endl: cout << "No" << endl;
	wordBreak("samsungandmangok") ? cout << "Yes" << endl : cout << "No" << endl;
	



	system("pause");
    return 0;
}

bool wordBreak(string str)
{
	// Recursively break this string and compare with the dictionary
	int size = str.size();   // End of the string
	
	if (size == 0)   // Base case
		return true;

	// Look for words
	// Move in the string and look for words
	for (int i = 1; i <= size; i++)
	{
		// Generate substring and check for them in the dictionary recursively until
		// we complete a pass We pass in a string starting at length i into function
		if (CheckDictionary(str.substr(0, i)) && wordBreak(str.substr(i,size-1)))
		{
			//cout << str << endl;
			return true;
		}
	}
	
	return false;
}

bool CheckDictionary(string word)
{
	string dictionary[] = { "mobile","samsung","sam","sung",
		"man","mango","icecream","and",
		"go","i","like","ice","cream" };

	int size = sizeof(dictionary) / sizeof(dictionary[0]);
	// We need to compare the word with this dictionary
	for (int i = 0; i < size; i++) 
	{
		if (dictionary[i].compare(word) == 0)
		{
			return true;
		}
	}
	return false;
}