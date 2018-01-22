// IterativePreOrderTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}Node;

Node *InsertNode(Node *node, int x);
Node *AllocNode(int x);
void IterativePre(Node *node);
void RecursivePrint(Node *node);
void InOrderPrint(Node *root);

int main()
{
	Node *root = NULL;
	int data[] = { 10,2,6,3,11,5,17,21,9 };
	int size = sizeof(data) / sizeof(data[0]);


	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	IterativePre(root);

	cout << endl;
	RecursivePrint(root);

	cout << endl;
	InOrderPrint(root);

	system("pause");
    return 0;
}

void InOrderPrint(Node *root)
{
	if (root == NULL)
		return;

	InOrderPrint(root->left);
	cout << "Value " << root->val << endl;
	InOrderPrint(root->right);
}

void RecursivePrint(Node *node)
{
	if (node == NULL)
		return;

	cout << "Value " << node->val << endl;
	RecursivePrint(node->left);
	RecursivePrint(node->right);
}

void IterativePre(Node *node)
{
	stack<Node*> tStack;

	// Insert the root
	tStack.push(node);

	while (!tStack.empty())
	{
		Node *t = tStack.top();
		cout << "Value " << t->val << endl;
		tStack.pop();

		if (t->right)
		tStack.push(t->right);
		if (t->left)
		tStack.push(t->left);

	}
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
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->val = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
