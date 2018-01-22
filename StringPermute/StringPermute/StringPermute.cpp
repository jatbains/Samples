// StringPermute.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// Recursively call routine to find all permutations
void swap(char *x, char *y);
void permute(char *s, int l, int r);

int main()
{
	char str[] = "ABCD";
	char *p = str;
	int n = strlen(str);

	permute(str, 0, n );



	system("pause");
    return 0;
}


void swap(char *x, char *y)
{
	char temp;
	temp = *y;
	*y = *x;
	*x = temp;

}

void permute(char *s, int l, int r)
{
	int i = 0;
	// Base case
	if (l == r )  // At las character
	{
		cout << s << endl;
		return;
	}

	for (i = l; i < r; i++) 
	{
		swap(s + l, s + i);
		permute(s, l + 1, r);
		swap(s + l, s + i);      // backtrack
	}

}