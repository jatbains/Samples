// CrossStreet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

const static int MAX_DIST = 5;
bool IsSafe(int Adj[][MAX_DIST], int row, int col,int cost);
void PrintPath(int Adj[][MAX_DIST]);
bool FindMinPath(int Adj[][MAX_DIST]);
bool FindMinPathUtil(int Adj[][MAX_DIST], int x, int y, int Sol[][MAX_DIST]);

list<int> myCost;

int main()
{
	int Adj[MAX_DIST][MAX_DIST] = { {1,1,1,1,1},
									{9,9,9,9,1},
									{1,3,3,3,1},
									{1,9,9,9,9},
									{1,1,1,1,1} };

	
	list<int> myList;
			
	// Wish to minimize cost going from (0,0) to (4,4)
	// Recursively go through adjacencies and try to minimize cost


	FindMinPath(Adj);




	system("pause");
    return 0;
}


bool FindMinPathUtil(int Adj[][MAX_DIST], int x, int y,int Sol[][MAX_DIST])
{
	int cost = 0;
	// Find the lowest cost path
	if ((x == MAX_DIST - 1) && (y == MAX_DIST - 1))
	{
		Sol[x][y] = 1;
		return	true;
	}
	cost += Adj[x][y];
	if (IsSafe(Adj, x, y,cost))
	{
		// Try to minimize cost

		if (FindMinPathUtil(Adj, x + 1, y, Sol) == true)
			return true;

		if (FindMinPathUtil(Adj, x, y+1, Sol) == true)
			return true;

		Sol[x][y] = 0;
		return false;

	}
	return false;
}

bool FindMinPath(int Adj[][MAX_DIST])
{
	int Sol[MAX_DIST][MAX_DIST] = { 0 };

	// Find the minimum cost path
	if (FindMinPathUtil(Adj, 0, 0, Sol) == false)
	{
		cout << "No Solution" << endl;
		return false;
	}

	PrintPath(Sol);
	return true;
	// Print out Solution
}

void PrintPath(int Sol[][MAX_DIST])
{
	for (int i = 0; i < MAX_DIST; i++)
	{
		for (int j = 0; j < MAX_DIST; j++)
		{
			cout << Sol[i][j] << endl;
		}
	}
}

bool IsSafe(int Adj[][MAX_DIST], int row, int col,int cost)
{
	if (!myCost.empty())
	{
		int prevcost = myCost.front();
		if (cost < prevcost)
		{
			myCost.pop_front();      // Push on the new cost
			myCost.push_front(cost);
		}
		else
		{
			return false;
		}
	}
	else
	{
		myCost.push_front(cost);
	}
	

	if (row >= 0 && row <= 4 && col >= 0 && col <= 4)
	{
		return true;
	}
	return false;
}