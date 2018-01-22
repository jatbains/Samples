// BFSGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <queue>


using namespace std;

// Graph Class

class Graph
{
private:
	int V;
	list<int> *adj;

public:
	Graph(int v);
	void addEdge(int v,int w);  // Add Edge
	void BFS(int v);            // Print BFS

};

void Graph::addEdge(int v, int w)
{
	// Add edge means you add w adjacency to v list
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];

	for (int i = 0; i < V; i++)
		visited[i] = false;

	//  Create BFS queue
	list<int> queue;

	visited[s] = true;    // Push it back onto queue after visiting it

	queue.push_back(s);


	list<int>::iterator i;

	// Do the search
	while (!queue.empty())
	{
		// Pop an vertex off queue and print it
		s = queue.front();
		cout << s << " ";

		queue.pop_front();

		// Get all adjacent vertexes and if not visited then mark them as visited
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{

			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);    // Push back visited vertexes on queue 
			}
		}
	}

}

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int>[V];
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);
	cout << endl;
	system("pause");
    return 0;
}

