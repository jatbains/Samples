// StringPermutations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>


using namespace std;
void CharSwap(char *a, char *b);
void Permute(char * a, int l, int r);

int main()
{
	char str[] = "BELT";
	int l = strlen(str);

	Permute(str, 0, l - 1);

	system("pause");
    return 0;
}

// Permutation function
void Permute(char * a, int l, int r)
{
	int i;
	if (l == r)   // Print out string
	{
		cout << a << endl;
	}

	else
	{        // Go through the string swapping a character at a time and call permute
		for (int i = l; i <= r; i++)      // swapping characters at indexes and permute
		{
			CharSwap((a + l), (a + i));    // Swap lower index and i
			Permute(a, l + 1, r);     
			CharSwap((a + l), (a + i));   // Backtracking

		}

	}
}

void CharSwap(char *a, char *b)
{

	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// What is the algorithm?  Get the subsequent char in a loop and call into recursion