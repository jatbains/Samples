// GraphDFSBFSClasses.cpp : Defines the entry point for the console application.
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
	list<Node> adj;
	
	int i;
	Node() {}
	Node(int i)
	{
		this->i = i;	
	}
	void addAdjacency(Node n)
	{
		adj.push_front(n);
	}
};

class Graph
{
	int V;
public:
	bool *isVisit;
	Graph(int V);
	unordered_map<int, Node> nMap;

	Node getNode(int i);
	void addNode(int i);
	void addEdge(int i, int j);

	bool hasDFS(int source, int dest);
	//void BFS(int i);
	bool DFSVisited(Node s, Node q);
};

bool Graph::hasDFS(int source, int dest)
{
	Node s = getNode(source);
	Node q = getNode(dest);

	return DFSVisited( s, q);
}

bool Graph::DFSVisited(Node s, Node q)
{
	if (isVisit[s.i])
		return false;

	isVisit[s.i] = true;
	cout << "Visit " << s.i << endl;

	if (s.i == q.i)
	{
		cout << "Path found" << endl;
		return true;
	}


	list<Node>::iterator t;
	for (t = s.adj.begin(); t != s.adj.end(); ++t)
	{
		if (DFSVisited(*t, q))
		{
			return true;
		}
	}
	return false;
}



void Graph::addEdge(int i, int j)
{
	Node s = getNode(i);
	Node q = getNode(j);
	s.addAdjacency(q);
}

void Graph::addNode(int i)
{
	Node nNode(i);
	nMap[i] = nNode;
}

Node Graph::getNode(int i)
{
	return nMap[i];
}
Graph::Graph(int V)
{
	this->V = V;
	this->isVisit = new bool[V];
	for (int i = 0; i < V; i++) {
		this->isVisit[i] = false;
	}
}


int main()
{

	Graph mygraph(4);
	mygraph.addNode(0);
	mygraph.addNode(1);
	mygraph.addNode(2);
	mygraph.addNode(3);
	mygraph.addEdge(0, 1);
	mygraph.addEdge(0, 2);
	mygraph.addEdge(1, 2);
	mygraph.addEdge(2, 0);
	mygraph.addEdge(2, 3);
	mygraph.addEdge(3, 3);


	mygraph.hasDFS(1, 3);

	system("pause");
    return 0;
}

