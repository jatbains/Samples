// ClosestValInTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef struct Node
{
	int key;
	struct Node *left, *right;
}Node;

Node *AllocNode(int x);
Node *InsertNodeInTree(Node *node, int x);
void PrintInOrder(Node *node);
void FindClosestNode(Node *node, int x, int &min_diff, int &min_diff_key,Node **mNode);

int main()
{
	Node *root = nullptr;
	Node *cNode = nullptr;
	int data[] = { 15,3,7,16,21,11,17,23,14,1,25 };
	int size = sizeof(data) / sizeof(data[0]);
	int min_diff = INT_MAX, min_diff_key = -1;

	for (int i = 0; i < size; i++)
	{
		root = InsertNodeInTree(root, data[i]);
	}

	PrintInOrder(root);

	FindClosestNode(root, 20,min_diff,min_diff_key,&cNode);

	if (cNode != nullptr)
		cout << "Closest Value is " << cNode->key << endl;
	cout << "Closest Value is " << min_diff_key << endl;

	system("pause");
    return 0;
}

void FindClosestNode(Node *node, int x, int &min_diff, int &min_diff_key,Node **mNode)
{
	if (node == nullptr)
	{
		return;
	}

	if (x == node->key)
	{
		min_diff_key = x;
		return;
	}


	if (min_diff > abs(node->key - x))
	{
		min_diff = abs(node->key - x);
		min_diff_key = node->key;
		*mNode = node;
	}
	// get the min	

	if (x < node->key)
	{
		return FindClosestNode(node->left, x,min_diff,min_diff_key,mNode);
	}
	else
	{
		return FindClosestNode(node->right, x,min_diff,min_diff_key,mNode);
	}
	
}

void PrintInOrder(Node *node)
{
	if (node == nullptr)
		return;

	PrintInOrder(node->left);
	cout << node->key << endl;
	PrintInOrder(node->right);
}

Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->key = x;
	tNode->left = tNode->right = nullptr;
	return tNode;
}

Node *InsertNodeInTree(Node *node, int x)
{
	if (node == nullptr)
	{
		node = AllocNode(x);
		return node;
	}
	if (x < node->key)
	{
		node->left = InsertNodeInTree(node->left, x);
	}
	else
	{
		node->right = InsertNodeInTree(node->right, x);
	}
	return node;
}