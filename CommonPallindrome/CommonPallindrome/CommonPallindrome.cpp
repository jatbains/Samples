// CommonPallindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int countPS(string str,int len);

int main()
{
	string str = "aaccdd";
	int len = str.length();

	cout << countPS(str, len) << endl;

	system("pause");
    return 0;
}

int countPS(string str,int len)
{
	   // total length of string

	int **CPS = new int*[len+1];
	for (int i = 0; i < len+1; i++)
	{
		CPS[i] = new int[len+1];
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			CPS[i][j] = 0;
		}
	}
	//memset(*CPS, 0, sizeof(len*len));
	for (int i = 0; i < len; i++)
	{
		CPS[i][i] = 1;   // All Palindromes of size 1
		cout << CPS[i][i] << endl;
	}

	
	// All other lenghts
	for (int L = 2; L <= len; L++)
	{
		for (int i = 0; i < len; i++)
		{
			int k = L + i-1;

			if (str[i] == str[k])
			{
				CPS[i][k] = CPS[i][k - 1] + CPS[i + 1][k] +1;
			}

			else
			{
				CPS[i][k] = CPS[i][k - 1] + CPS[i + 1][k] - CPS[i + 1][k - 1];

			}


		}

	}
	return CPS[0][len-1];
}