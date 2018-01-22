// Graphing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

typedef struct Adj
{
	int val;
	struct Adj *next;
}Adj;

typedef struct Vertex
{
	int val;
	Adj *adjList;

}Vertex;

const static int MAX_VERTEX = 10;

void BFSGraph(Vertex vList[], int size, bool Visited[]);
void DFSRecur(Adj *adj, bool Visited[]);
void DFSGraph(Vertex vList[], int size, bool Visited[]);

void AddVertex(Vertex vList[], int x)
{
	vList[x].val = x;
}

void AddAdj(Vertex vList[], int ver, int adj)
{
	Adj *temp = (Adj*)malloc(sizeof(Adj));

	temp->val = adj;
	temp->next = NULL;
	if (vList[ver].adjList == NULL)
	{
		vList[ver].adjList = temp;
		return;
	}
	temp->next = vList[ver].adjList;
	vList[ver].adjList = temp;
	return;
}

int main()
{
	bool Visited[MAX_VERTEX] = { false };
	Vertex vList[MAX_VERTEX];
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		vList[i].val = 0;
		vList[i].adjList = NULL;
	}

	AddVertex(vList, 1);
	AddVertex(vList, 2);
	AddVertex(vList, 3);
	AddVertex(vList, 4);
	AddVertex(vList, 5);
	AddVertex(vList, 6);
	// Add the adjacencies
	AddAdj(vList, 1, 2);
	AddAdj(vList, 2, 3);
	AddAdj(vList, 3, 1);
	AddAdj(vList, 3, 5);
	AddAdj(vList, 1, 4);
	AddAdj(vList, 4, 3);
	AddAdj(vList, 5, 6);
	AddAdj(vList, 6, 3);

	BFSGraph(vList, 6, Visited);

	cout << endl;
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		Visited[i] = false;
	}

	DFSGraph(vList, 6, Visited);

	system("pause");
    return 0;
}

void BFSGraph(Vertex vList[],int size,bool Visited[])
{
	Adj *temp = NULL;
	for (int i = 1; i <= size; i++)
	{
		temp = vList[i].adjList;
		while (temp != NULL)
		{
			// Visit the Node
			if (!Visited[i])
			{
				Visited[i] = true;
				cout << "Visit Node  " << i << endl;
			}
			temp = temp->next;
		}
	}
}

void DFSRecur(Adj *adj, bool Visited[])
{
	if (adj == NULL)
		return;
	if (Visited[adj->val]==false)
	{
		cout << "Visit Node " << adj->val << endl;
		Visited[adj->val] = true;
	}
	DFSRecur(adj->next, Visited);
	return;
}

void DFSGraph(Vertex vList[], int size, bool Visited[])
{
	// Recursively visit nodes
	for (int i = 1; i <= size; i++)
	{
		DFSRecur(vList[i].adjList, Visited);
	}
}