// GraphDFSBFS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;


class Node
{
public:
	int i;   // node number
	list<Node> adj;

	Node() {};
	Node(int i)
	{
		this->i = i;

	}
	void addAdjacency(int n)
	{
		Node mNode(n);
		adj.push_front(mNode);
	}
}mNode;



class Graph
{
	int V;  // Total number of vertices
	list<int>  *adj;  // Adjacency list for all vertices,  Array of lists

public:
	class Node mNode;

	unordered_map<int, Node>  nodeMap;

	Graph(int V) : mNode(Node(V))
	{
		this->V = V;
		adj = new list<int>[V];

	};  // Constructor

	void addEdge(int v, int w);

	void BFS(int s);

};



void Graph::addEdge(int v, int w)
{
	// Add w as an adjacency of v
	adj[v].push_back(w);
	
	Node mNode(v);

	nodeMap[v]=mNode;

}

void Graph::BFS(int s)
{
	// Created a visited array
	bool *isVisited = new bool[V];  // same as isVisited = (bool*) malloc(sizeof(bool)*V);
	for (int i = 0; i < V; i++)
	{
		isVisited[i] = false;
	}


	// We use a queue and pull nodes off front and add the adjacencies to end FIFO
	list<int> queue;

	// Get the first node and add adjacencies to this queue
	isVisited[s] = true;

	// Put it into the queue
	queue.push_back(s);

	// Use a list iterator

	list<int>::iterator i;

	while (!queue.empty())
	{
		// Get front

		s = queue.front();
		cout << s << endl;
		queue.pop_front();

		// Go through the adjacencies
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			// Pull off the nodes from queue and mark them as visited
			// Check the adjacencies
			if (!isVisited[*i])
			{
				isVisited[*i] = true;
				queue.push_back(*i);

			}

		}

	}


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

	g.BFS(2);

	system("pause");
    return 0;
}

