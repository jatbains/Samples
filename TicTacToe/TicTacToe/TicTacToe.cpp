// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	// Someone wins tic tac toe if they get three x or o in a row.
	//  Use a boolena and let false be O and true be X
	bool tic[3][3];   // Two dimensional array
	// Check this array for 3 false or 3 true in a row

	for (int i = 0; i < 3; i++)
	{
		// Check Rows
		if (tic[i][0] == tic[i][1] == tic[i][2])
		{
			cout << "Winner is " << (tic[i][0] ? "X" : "O" ) << endl;
		}
		// Check columns
		if (tic[0][i] == tic[1][i] == tic[2][i])
		{
			cout << "Winner is " << (tic[0][i] ? "X" : "O") << endl;
		}
		// Check diagonal
		if (tic[0][0] == tic[1][1] == tic[2][2])
		{
			cout << "Winner is " << (tic[0][0] ? "X" : "O") << endl;
		}
		if (tic[0][2] == tic[1][1] == tic[2][0])
		{
			cout << "Winner is " << (tic[0][2] ? "X" : "O") << endl;
		}
	}



	system("pause");
    return 0;
}

