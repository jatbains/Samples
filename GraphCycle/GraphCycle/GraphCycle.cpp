// GraphCycle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Edge
{
	int src;
	int dest;
}Edge;

typedef struct Graph
{
	int V, E;

	Edge *edge;  // Pointer to list of edges
}Graph;


Graph *CreateGraph(int V, int E)
{
	Graph * graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->E = E;

	graph->edge = (Edge *)malloc(sizeof(Edge));

	return graph;
}

int find(int parent[], int i)
{
	if (parent[i] == -1)
	{
		return i;
	}
	return find(parent, parent[i]);
}

void Union(int parent[], int X, int Y)
{
	int xset = find(parent, X);
	int yset = find(parent, Y);
	parent[xset] = yset;
}

int isCycle(struct Graph *graph)
{
	// Allocate memory for V subsets
	int *parent = (int *)malloc(graph->V * sizeof(int));

	// Initialize the subsets 
	memset(parent, -1, sizeof(int)*graph->V);

	// Iterate through the edges of the graph  
	// Find subsets of both vertices of every edge
	for (int i = 0; i < graph->E; i++)
	{
		int x = find(parent, graph->edge->src);
		int y = find(parent, graph->edge->dest);

		if (x == y)
			return 1;

		Union(parent, x, y);
	}
	return 0;
}


int main()
{
	/* Let us create following graph
	0
	|  \
	|    \
	1-----2 */
	int V = 3, E = 3;
	struct Graph* graph = CreateGraph(V, E);

	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	// add edge 1-2
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	// add edge 0-2
	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if (isCycle(graph))
		printf("graph contains cycle");
	else
		printf("graph doesn't contain cycle");

	cout << endl;
	system("pause");
    return 0;
}

