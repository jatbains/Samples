// TreeLevelCount.cpp : Defines the entry point for the console application.
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
void PrintInOrder(Node *node);
int TreeDepth(Node *node);
int CountNodesAtLevel(Node *node, int l);

int main()
{
	Node *root = NULL;
	int data[] = { 15,3,7,19,21,6,12,25,18,27 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	PrintInOrder(root);

	cout << endl <<  "Height is " << TreeDepth(root) << endl;

	cout << "Count at level 3 is " << CountNodesAtLevel(root, 3) << endl;

	system("pause");
    return 0;
}

int CountNodesAtLevel(Node *node, int l)
{
	static int count;
	if (node == NULL)
	{
		return count;
	}
	if (l == 0)
	{
		count++;
	}
	CountNodesAtLevel(node->left, l - 1);
	CountNodesAtLevel(node->right, l - 1);
}

int TreeDepth(Node *node)
{
	if (node == NULL)
		return 0;

	int lh = TreeDepth(node->left);
	int rh = TreeDepth(node->right);

	return (lh > rh ? lh + 1 : rh + 1);
}


void PrintInOrder(Node *node)
{
	if (node == NULL)     // Base case
		return;

	PrintInOrder(node->left);
	cout << " " << node->val << " " << endl;
	PrintInOrder(node->right);
}

Node *AllocNode(int x)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = x;
	temp->left = temp->right = NULL;

	return temp;
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
