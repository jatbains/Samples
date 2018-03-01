// AnagramSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool AreAnagramsSort(char *s1, char *s2);
int compare(const void * a, const void * b);

int main()
{
	char str1[] = { 't','o','o','l','\0' };
	char str2[] = { 'l','o','o','t','\0' };

	cout << endl;
	cout << (AreAnagramsSort(str1, str2) ? "The strings are Anagrams":"The strings are not Anagrams") << endl;

	cout << endl;
	system("pause");
    return 0;
}

int compare(const void * a, const void * b)
{
	return (*(char*)a - *(char*)b);
}


bool AreAnagramsSort(char *s1, char *s2)  // Immutable?
{
	// Sort the two strings and compare the dstribution   
	// Sort the frist string
	char *p = s1;
	char *q = s2;
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	if (len1 != len2)
		return false;

	
	qsort(s1, len1,sizeof(char),compare);    // Literal sort  O(nlogn)  Average case
	qsort(s2, len2,sizeof(char),compare);


	// Compare the characters
	while (*p != '\0' && *q != '\0')    // O(n)  ,  
	{
		if (*p != *q)
			return false;
		p++;
		q++;
	}

	return true;

}