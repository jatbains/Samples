// LinkedListGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Vertex
{
	int val;
	struct Vertex *list;

}Vertex;

const static int MAX_VERTEX = 10;

Vertex VList[10];

void InsertAdjacency(Vertex list[], int v, int x);
Vertex *AddAdjacency(int x);
void PrintLists(Vertex list[]);

int main()
{
	// Add all the Vertexes first
	for (int i = 0; i < MAX_VERTEX; i++)
	{
		VList[i].val = 2*i;
		VList[i].list = NULL;
	}

	// Create some adjacencies for the vertexes
	InsertAdjacency(VList, 2, 8);
	InsertAdjacency(VList, 4, 2);
	InsertAdjacency(VList, 4, 6);
	InsertAdjacency(VList, 6, 2);
	InsertAdjacency(VList, 8, 6);
	InsertAdjacency(VList, 8, 4);
	InsertAdjacency(VList, 8, 8);

	PrintLists(VList);

	system("pause");
    return 0;
}

void PrintLists(Vertex list[])
{
	Vertex *temp = NULL;
	for (int i = 0; i <= MAX_VERTEX; i++)
	{
		temp = list[i].list;
		cout << "Vertex " << i << endl;
		while (temp != NULL)
		{
			cout << "Adjacency is " << temp->val << " " << endl;
			temp = temp->list;
		}
	}

}

void InsertAdjacency(Vertex list[], int v,int x)
{
	if (list[v].list == NULL)
	{
		list[v].list = AddAdjacency(x);
	}
	// Add add the beginning of list
	Vertex *temp = AddAdjacency(x);
	temp->list = list[v].list;
	list[v].list = temp;

}

Vertex *AddAdjacency(int x)
{
	Vertex *temp = (Vertex *)malloc(sizeof(Vertex));
	temp->val = x;
	temp->list = NULL;

	return temp;
}
