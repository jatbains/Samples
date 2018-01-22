// Djikstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const static int MAX_VERT = 9;

// This is a Greedy algorithm
void dijkstra(int graph[MAX_VERT][MAX_VERT], int s);
void PrintSolution(int dist[MAX_VERT]);
int MinDistance(int dist[], bool sptSet[]);

int main()
{
	/* Let us create the example graph discussed above */
	int graph[MAX_VERT][MAX_VERT] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	dijkstra(graph, 0);


	system("pause");
    return 0;
}

// Check if vertex is in the set and find min distance vetex not yet added

int MinDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index = 0;

	for (int v = 0; v < MAX_VERT; v++)
	{
		if ((sptSet[v] == false) && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}




void PrintSolution(int dist[MAX_VERT])
{
	cout << "Vertex Distance from source" << endl;
	for (int i = 0; i < MAX_VERT; i++)
	{
		cout << i << "\t\t" << dist[i] << endl;
	}
}


void dijkstra(int graph[MAX_VERT][MAX_VERT], int src)
{
	// Create the distance array and the sptSet (vertex added) boolean array
	bool sptSet[MAX_VERT];
	int dist[MAX_VERT];

	for (int i = 0; i < MAX_VERT; i++)
	{
		sptSet[i] = false;
		dist[i] = INT_MAX;
	}

	dist[src] = 0;   // Set distance of source vertex from itself is 0

	// Find the shortest paths

	for (int i = 0; i < MAX_VERT - 1; i++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = MinDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update distance values of adjacent vetices

		for (int v = 0; v < MAX_VERT; v++)
		{
			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && (dist[u] != INT_MAX)
				&& dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
			}

		}

	}

	PrintSolution(dist);
}