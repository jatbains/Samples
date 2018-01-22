// ListTreeNodes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}Node;

Node *AllocNode(int x);
Node *InsertNode(Node *node, int x);
void PrintPreOrder(Node *node);

int main()
{
	int data[] = { 9,3,15,4,8,17,21 };
	int size = sizeof(data) / sizeof(data[0]);
	// Create a list of Nodes
	list<Node*> tNodes;
	Node *root = NULL;

	for (int i = 0; i < size; i++)
	{
		// Create Tree
		root = InsertNode(root, data[i]);
		tNodes.push_back(AllocNode(data[i]));
		
	}

	list<Node*>::iterator it;
	for (it=tNodes.begin(); it != tNodes.end(); it++)
	{
		cout << (*it)->val << endl;
	}

	cout << endl;
	PrintPreOrder(root);


	system("pause");
    return 0;
}

void PrintPreOrder(Node *node)
{
	if (node == NULL)
		return;
	cout << node->val << endl;
	PrintPreOrder(node->left);
	PrintPreOrder(node->right);
}

Node *InsertNode(Node *node, int x)
{
	if (node == NULL)
	{
		node = AllocNode(x);
		return node;
	}

	if (x < node->val)
	{
		node->left = InsertNode(node->left, x);
	}
	else if (x > node->val)
	{
		node->right = InsertNode(node->right, x);
	}
	return node;
}

Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->val = x;
	tNode->left = tNode->right = NULL;
	return tNode;
}
