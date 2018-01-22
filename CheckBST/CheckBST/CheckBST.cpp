// CheckBST.cpp : Defines the entry point for the console application.
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

};

Node *AllocNode(int x);
Node *InsertNode(Node *node, int x);
void PrintTree(Node *node);
void PreOrder(Node *node);

int main()
{
	Node *root = NULL;
	int data[] = { 1,12,3,25,6,5,30,9,10,15,2,17,21,7,16 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	cout << endl << "In Order" << endl;
	PrintTree(root);

	cout << endl <<"Pre Order" << endl;

	PreOrder(root);
	cout << endl;
	system("pause");
    return 0;
}

void PreOrder(Node *node)
{
	if (node == NULL)
		return;
	cout << node->val << " " ;
	PreOrder(node->left);
	PreOrder(node->right);
}

void PrintTree(Node *node)
{
	if (node == NULL)
		return;
	PrintTree(node->left);
	cout << node->val << " ";
	PrintTree(node->right);
}

Node *InsertNode(Node *node,int x)
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
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = x;
	temp->left = temp->right = NULL;

	return temp;
}