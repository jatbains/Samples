// PrintTreeLevelByLevel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}Node;

Node *AllocNode(int x);
Node *InsertNode(Node *node, int x);
int TreeHeight(Node *node);
void PrintPreOrder(Node *node);
void PrintTreeLevel(Node *node, int l);
void PrintLevelByLevel(Node *node);

int main()
{
	int data[] = { 13,3,16,7,11,19,21,5,8,25 };
	int size = sizeof(data) / sizeof(data[0]);
	Node *root = NULL;

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	PrintPreOrder(root);

	cout << endl;
	cout << "Height is " << TreeHeight(root) << endl;

	cout << endl;

	PrintLevelByLevel(root);

	system("pause");
    return 0;
}

// Print Tree level by level 
// Run a loop and call recursive function to print values for height where 
// loop variable goes from 1 to height

void PrintTreeLevel(Node *node, int l)
{
	if (node == NULL)  // Base case
		return;
	if (l == 1)
	{
		cout << "   " << node->val << " ";
	}

	PrintTreeLevel(node->left, l - 1);
	PrintTreeLevel(node->right, l - 1);
}

void PrintLevelByLevel(Node *node)
{
	int h = TreeHeight(node);  // height of tree

	for (int i = 1; i <= h; i++)
	{
		cout << " Level is " << i << endl;
		PrintTreeLevel(node, i);
		cout << endl;
	}
}

void PrintPreOrder(Node *node)
{
	if (node == NULL)
		return;
	cout << "Value is " << node->val << endl;
	PrintPreOrder(node->left);
	PrintPreOrder(node->right);

}

int TreeHeight(Node *node)
{
	if (node == NULL)  // Base case
		return 0;

	int lh = TreeHeight(node->left);
	int rh = TreeHeight(node->right);

	return (lh > rh ? lh + 1 : rh + 1);
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
	else
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