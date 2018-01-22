// PermuteString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void Swap(char *s, char *t);
void Permute(char *s, int l, int r);

int main()
{
	char s[] =  "ABCD" ;

	Permute(s, 0, 3);
	cout << endl;
	system("pause");
    return 0;
}

void Permute(char *s, int l, int r)
{
	int i = 0;
	if (l == r) 
	{
		cout << s << endl;    // Base condition
		return;
	}
	// repeat for size of string
	for (int i = l; i <= r; i++) 
	{
		// Swap Permute and swap back
		Swap((s + l), (s + i));
		Permute(s, l + 1, r);
		Swap((s + l), (s + i));    // Backtrack
	}

}

// Permuting a string is finding all of the different options
// and then printing them out.
void Swap(char *s, char *t)
{
	char c = *s;
	*s = *t;
	*t = c;
}
