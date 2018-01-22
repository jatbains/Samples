// Maze.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


const static int N = 4;
void solveMaze(int Maze[][N]);
bool IsSafe(int maze[N][N], int x, int y);
void PrintSoln(int *Maze);
bool solveMazeUtil(int Maze[][N], int x, int y, int Soln[][N]);

// Algorithm is to recursively move through the maze and
// Test by moving right and down until we get to the exit
//  If blocked we mark that as invalid and backtrack

int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
	{ 1, 1, 0, 1 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 1, 1 }
	};

	solveMaze(maze);


	system("pause");
    return 0;
}


void PrintSoln(int *Maze)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << (*(Maze + i * N + j));
		}
		cout << endl;
	}

	return;
}

bool IsSafe(int maze[N][N],int x,int y)
{

	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;
	return false;

}

bool solveMazeUtil(int Maze[][N], int x, int y, int Soln[][N])
{
	// We need to recusrsively check to see if we find a path

	// Base Case
	if (x == (N - 1) && y == (N - 1))
	{
		Soln[x][y] = 1;
		return true;
	}
	// We need to check to see if path is safe
	if (IsSafe(Maze, x, y))
	{

		// Mark this path in Solution as visited
		Soln[x][y] = 1;

		// Move one space to right

		if (solveMazeUtil(Maze, x + 1, y, Soln) == true)
		{
			return true;   // path found
		}

		if (solveMazeUtil(Maze, x, y + 1, Soln) == true)
		{
			return true;
		}

		// Path Not found mark bad path in solution matrix and backtrack

		Soln[x][y] = 0;


	}
	return false;  // No path  found

}

void solveMaze(int Maze[][N])
{
	int soln[N][N] = { {0,0,0,0},
					{0,0,0,0},
					{ 0,0,0,0 },
					{0,0,0,0} };

	// Call the ustility to solve the maze problem
	if (!solveMazeUtil(Maze,0,0, soln)) {
		cout << "No solution found " << endl;
		return;
	}
	cout << endl;

	PrintSoln((int *)soln);
	cout << endl;
}
