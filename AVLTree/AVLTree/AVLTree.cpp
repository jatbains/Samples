// AVLTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int val;
	int height;

	struct Node *left;
	struct Node *right;

}Node;

Node *InsertNode(Node *node, int x, int height);
Node *AllocNode(int x);
void InOrderPrint(Node *node);
int TreeDepth(Node *node);

int main()
{
	Node *root = NULL;
	int data[] = { 17,3,21,7,15,19,27,10,13,29,31 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i], 0);
	}

	InOrderPrint(root);
	cout << endl;

	cout << "Height is " << TreeDepth(root) << endl;

	system("pause");
    return 0;
}

int TreeDepth(Node *node)
{
	if (node == NULL)
		return 0;
	int lh = TreeDepth(node->left);
	int rh = TreeDepth(node->right);
	return (lh > rh ? lh +1 : rh +1);
}

void InOrderPrint(Node *node)
{
	if (node == NULL)
	{
		return;
	}
	InOrderPrint(node->left);
	cout << "Node " << node->val << " Depth " << node->height << endl;
	InOrderPrint(node->right);
}

Node *InsertNode(Node *node, int x,int height)
{
	if (node == NULL)
	{
		node = AllocNode(x);
		node->height = height;
		return node;
	}
	if (x < node->val)
	{
		node->left = InsertNode(node->left, x, height + 1);
	}
	else
	{
		node->right = InsertNode(node->right, x, height + 1);
	}
	return node;
}

Node *AllocNode(int x)
{
	Node *tNode = (Node*)malloc(sizeof(Node));
	tNode->val = x;
	tNode->height = 0;
	tNode->left = tNode->right = NULL;

	return tNode;
}
