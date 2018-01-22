// TreeSearch.cpp : Defines the entry point for the console application.
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

Node *AlloNode(int x)
{
	Node *TNode = (Node*)malloc(sizeof(Node));
	TNode->val = x;
	TNode->left = TNode->right = NULL;
	return TNode;
}

Node *InsertNode(Node* node, int x)
{
	if (node == NULL)
	{
		node = AlloNode(x);
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

void PrintInOrder(Node *node)
{
	if (node == NULL)
		return;
	PrintInOrder(node->left);
	cout << node->val << endl;
	PrintInOrder(node->right);
}

int DepthofTree(Node *node)
{
	if (node == NULL)
		return 0;
	int lh = DepthofTree(node->left);
	int rh = DepthofTree(node->right);

	return (lh > rh ? lh + 1 : rh + 1);
}

int SearchValues(Node *node, int lValue, int rValue,int count)
{
	if (node == NULL)
		return count;

	if ((node->val > lValue) || (node->val < rValue))
	{
		count++;
	}
	// Search the entire tree
	SearchValues(node->left, lValue, rValue, count);
	SearchValues(node->right, lValue, rValue, count);

}

int main()
{
	Node *root = NULL;
	int data[] = { 15,3,6,21,12,1,24,18,13,27,9,16,32 };
	int size = sizeof(data) / sizeof(data[0]);
	int count = 0;
	int depth = 0;

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	PrintInOrder(root);

	cout << "Depth of Tree " << DepthofTree(root) << endl;
	depth = DepthofTree(root);
	// Count values between 10 and 20

	cout << "Values in range  " << SearchValues(root, 10, 20, 0) << endl;

	system("pause");
    return 0;
}

