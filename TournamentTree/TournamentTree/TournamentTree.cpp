// TournamentTree.cpp : Defines the entry point for the console application.
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

Node *InsertNode(Node *node, int x);
Node *AllocNode(int x);
void PrintPreOrder(Node *node);
int SecondMinValue(Node *node, int min);
int FindTheSecondMin(Node *node);
int MaxDepth(Node *node);

int main()
{
	Node *root = NULL;
	int data[] = { 2,2,4,2,3,5,3 };
	int size = sizeof(data) / sizeof(data[0]);

	// Construct tree
	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}


	PrintPreOrder(root);

	cout << endl;

	cout << SecondMinValue(root, root->val) << endl;

	cout << FindTheSecondMin(root) << endl;

	cout << "Max Depth is " << MaxDepth(root) << endl;

	system("pause");
    return 0;
}

int MaxDepth(Node *node)
{
	if (node == NULL)
		return 0;
	int ld = MaxDepth(node->left);
	int rd = MaxDepth(node->right);

	return (ld > rd ? ld + 1 : rd + 1);
}

int SecondMinNode(Node *node, int small)
{
	if (node == NULL || node->val > small)
		return small;
}

int FindTheSecondMin(Node *node)
{
	if (node == NULL)
		return 0;

	int left = SecondMinNode(node->left, node->val);
	int right = SecondMinNode(node->right, node->val);

	return (left < right ? left : right);
}

int SecondMinValue(Node *node, int min)
{
	if (node == NULL)
	{
		return min;
	}
	

	if (min < node->val)
	{
		min = node->val;
	}
	int minl = SecondMinValue(node->left, min);
	int minr = SecondMinValue(node->right, min);
	return (minl < minr ? minl : minr);
	
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
