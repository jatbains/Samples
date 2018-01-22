// Anagrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void StringCompare(char *s1, char *s2);

int main()
{
	char *list[] = { "ball","apple","bake","cat","bat","tab","rake","tip","pit" };
	bool map[26] = { false };
	char *p = NULL;
	// Go through the list until you find strings with same characters

	// Process first list and then compare against the rest
	// If a match is found move pointers for the array

	// Repeat for all of the strings in the array.
	int size = sizeof(list) / sizeof(list[0]);

	for (int i = 0; i < size; i++)
	{
		// process the lists string by string
		//p = list[i];
		// Compare all strings with each other
		for (int j = i+1; j < size; j++)
		{
			StringCompare(list[i], list[j]);
		}
		
	}


	system("pause");
    return 0;
}
void StringCompare(char *s1, char *s2)
{
	char *t1 = s1, *t2 = s2;
	int count1[26] = { 0 }, count2[26] = { 0 };
	// Got thorugh each string and add counts of letters
	while (*s1 != '\0')
	{
		count1[*s1 - 'a'] ++;
		s1++;
	}
	while (*s2 != '\0')
	{
		count2[*s2 - 'a']++;
		s2++;
	}
	// Compare the char counts of each
	for (int i = 0; i < 26; i++)
	{
		if (count1[i] != count2[i])
		{
			// no match
			return;
		}
	}
	// Match found print them
	cout << t1 << " " << t2 << endl;


}
