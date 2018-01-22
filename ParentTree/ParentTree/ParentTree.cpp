// ParentTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
}Node;

Node *AllocNode(int x);
Node *InsertNode(Node *node, Node *prev, int x);
void PrintPreOrder(Node *node);

int main()
{
	Node *root = NULL;
	int data[] = { 13,4,17,7,12,21,3,9,24,1 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, NULL, data[i]);
	}

	PrintPreOrder(root);

	system("pause");
    return 0;
}

void PrintPreOrder(Node *node)
{
	if (node == NULL)
		return;
	// Print out the root node first
	cout << "Value is " << node->val << endl;
	cout << "Parent of this node is " << node->parent << endl;
	PrintPreOrder(node->left);
	PrintPreOrder(node->right);
}


Node *InsertNode(Node *node, Node *prev, int x)
{
	if (node == NULL)
	{
		node = AllocNode(x);
		node->parent = prev;
		return node;
	}
	if (x < node->val)
	{
		node->left = InsertNode(node->left, node, x);
	}
	else if (x > node->val)
	{
		node->right = InsertNode(node->right, node, x);
	}
	return node;
}

Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->val = x;
	tNode->parent = tNode->left = tNode->right = NULL;
	return tNode;
}
