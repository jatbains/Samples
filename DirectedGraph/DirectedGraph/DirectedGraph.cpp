// DirectedGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX_STRING = 20;
const int MAX_CHILD = 10;

typedef struct Node
{
	char name[MAX_STRING];
	struct Node *child;
}Node;

class Graph
{
private:

	Node nodes[];
public:
	Node* FindAdjacent();
	Node* DepthFirstSearch();
	Node* BreadthFirstSearch();
};

Node* Graph::BreadthFirstSearch()
{
	Node *ptr = NULL;


	return ptr;
}

Node* Graph::DepthFirstSearch()
{
	Node *ptr = NULL;


	return ptr;
}

Node* Graph::FindAdjacent()
{
	Node *ptr = NULL;


	return ptr;
}

int main()
{
    return 0;
}

