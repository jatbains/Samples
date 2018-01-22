// TreeMinLevel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}Node;


Node *AllocNode(int x);
void PrintTree(Node *node);
Node *InsertNode(Node *node, int val);
int Depth(Node *node);
void ModifiedPrint(Node *node, int l,int x);

int main()
{
	Node *root = NULL;
	int data[] = { 20,6,15,2,12,30,10,25,45,80 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	PrintTree(root);

	cout << endl << "Min Depth is " << Depth(root) << endl;

	ModifiedPrint(root,4,0);

	cout << endl;

	system("pause");
    return 0;
}

// Can we print elements on a single level?  level= 2

void ModifiedPrint(Node *node, int l,int x)
{
	if (node == NULL)
		return;
	ModifiedPrint(node->left, l,x+1);
	if (l == x)
		cout << node->val << " " << endl;
	ModifiedPrint(node->right, l,x+1);
	return;
}

void PrintTree(Node *node)
{
	if (node == NULL)    // Base case
		return;
	PrintTree(node->left);
	cout << node->val << " " << endl;
	PrintTree(node->right);
	return;
}

Node *InsertNode(Node *node, int val)
{
	// Base case root is NULL
	if (node == NULL)
	{
		node = AllocNode(val);
		return node;
	}
	if (val < node->val)
	{
		node->left = InsertNode(node->left, val);
	}
	else
	{
		node->right = InsertNode(node->right, val);
	}
	return node;
}

int Depth(Node *node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	if (node->left == NULL)
		return Depth(node->right) + 1;
	if (node->right == NULL)
		return Depth(node->left) + 1;

	return 1 + min(Depth(node->left), Depth(node->right));
}

Node *AllocNode(int x)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
