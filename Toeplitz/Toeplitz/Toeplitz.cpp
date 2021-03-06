// Toeplitz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


const static int N = 5;
const static int M = 4;

//void PrintArray(int top[][M]);
void PrintArray(int top[N][M]);
void PointerPrintArray(int *top);
bool ProveToeplitz(int top[N][M]);
bool CheckDiagonal(int top[N][M], int i, int j);

int main()
{
	int topl[3][3] = { {1,2,3},
					   {4,1,2},
					   {5,4,1} };

	int top2[N][M] = {  { 6, 7, 8, 9 },
						{ 4, 6, 7, 8 },
						{ 1, 4, 6, 7 },
						{ 0, 1, 4, 6 },
						{ 2, 0, 1, 4 } };

	cout << "Print the Matrix " << endl;

	PrintArray(top2);

	cout << endl;

	//PointerPrintArray(&topl[0][0]);

	cout << endl;

	// cout << (ProveToeplitz(topl) ? " Toeplitz matrix 1 " : " Not a toeplitz matrix ") << endl;

	cout << (ProveToeplitz(top2) ? " Toeplitz matrix 2 " : " Not a toeplitz matrix ") << endl;

	cout << endl;
	system("pause");
    return 0;
}

bool CheckDiagonal(int top[N][M],int i, int j)
{
	int val = top[i][j];  // Diagonal value 

	while (++i < N && ++j < M)
	{
		if (top[i][j] != val)
		return false;
	}
	return true;
}

bool ProveToeplitz(int top[N][M]) 
{
	// Check the rows and the columns
	for (int i = 0; i < N; i++)
	{
		// check if Toeplitz
		if (!CheckDiagonal(top, 0, i))
			return false;
	}
	for (int j = 0; j < M; j++)
	{
		// check toeplitz
		if (!CheckDiagonal(top, j, 0))
			return false;
	}
	return true;
}

void PrintArray(int top[N][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << top[i][j] << " ";
		}
		cout << endl;
	}
}

void PointerPrintArray(int *top)
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << top[i*N + j] << " ";
		}
		cout << endl;
	}
}