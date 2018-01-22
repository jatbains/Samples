// isGraphCyclic.cpp : Defines the entry point for the console application.
//

// Using a stack LIFO and Depth First Search detect a cycle

#include "stdafx.h"
#include <iostream>
#include <string>

// A C++ Program to detect cycle in a graph
#include <list>
#include <limits.h>

using namespace std;

class Graph
{
	int V;    // No. of vertices
	list<int> *adj;    // Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], bool rs[]);  // used by isCyclic()
public:
	Graph(int V);   // Constructor
	void addEdge(int v, int w);   // to add an edge to graph
	bool isCyclic();    // returns true if there is a cycle in this graph
};

bool Graph::isCyclicUtil(int v, bool visited[], bool recStack[])
{
	// Recursively try to determine if a cycle exists
	if (visited[v] == false)
	{
		// Mark as visited
		visited[v] = true;
		recStack[v] = true;

		list<int>::iterator i;
		for  (i=adj[v].begin(); i != adj[v].end(); ++i)
		{
			//  Iterate through collection
			if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
				return true;
			else if (recStack[*i])             // Already seen in stack
				return true;   

		}

	}

	recStack[v] = false;
	return false;
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);     //  Add w to v's list

}
bool Graph::isCyclic(void)
{
	bool *Visited = new bool[V];      // Verices visited and not in recStack
	bool *recStack = new bool[V];   

	for (int i = 0; i < V; i++)
	{
		Visited[i] = false;
		recStack[i] = false;
	}

	// Call utility function to detect a cycle
	for (int i = 0; i < V; i++)
	{
		if (isCyclicUtil(i, Visited, recStack))    // Detected a cycle
			return true;
	}
	return false;
}

int main()
{

	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	if (g.isCyclic())
		cout << "Graph contains cycle";
	else
		cout << "Graph doesn't contain cycle";


	system("pause");
    return 0;
}

