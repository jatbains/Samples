// FindAnagrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;
void FindAllAnagrams(string arr[], int size);
bool StringsAnangrams(string s1, string s2);

const static int MAX_NUM_CHARS = 256;

int main()
{
	string arr[] = { "geeksquiz", "geeksforgeeks", "abcd",
		             "forgeeksgeeks", "zuiqkeegs" };
	int size = sizeof(arr) / sizeof(arr[0]);



	FindAllAnagrams(arr, size);

	system("pause");
    return 0;
}

bool StringsAnangrams(string s1, string s2)
{
	int count1[MAX_NUM_CHARS] = { 0 };
	int count2[MAX_NUM_CHARS] = { 0 };
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		count1[s1[i]]++;
		count2[s2[i]]++;
	}

	for (i = 0; i < MAX_NUM_CHARS; i++)
	{
		if (count1[i] != count2[i])
			return false;
	}

	return true;
}

void FindAllAnagrams(string arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (StringsAnangrams(arr[i], arr[j]))
			{
				cout << arr[i] << " " << arr[j] << "      Anangrams " << endl;
			}
		}
	}


}