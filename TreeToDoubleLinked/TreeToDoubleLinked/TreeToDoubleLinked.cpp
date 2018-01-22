// TreeToDoubleLinked.cpp : Defines the entry point for the console application.
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
void PrintPreTree(Node *node);
void InOrder(Node *node);
Node *BinTreeList(Node *node);
Node *BinTreeListUtil(Node *node);
void PrintList(Node* head);

const static int MAX_SIZE = 20;

int main()
{
	Node *root = NULL;
	Node *list = NULL;
	int data[] = { 10,8,13,19,4,3,11,21};
	int size = sizeof(data) / sizeof(data[0]);
	
	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}
	
	PrintPreTree(root);
	cout << endl;

	InOrder(root);

	list = BinTreeList(root);

	PrintList(list);
	cout << endl << endl;
	system("pause");
    return 0;
}

void PrintList(Node* head)
{
	if (head == NULL)
		return;

	Node *temp = head;
	while (temp != NULL)
	{
		cout << " " << temp->val << " ";
		temp = temp->right;
	}
}

Node *BinTreeListUtil(Node *node)
{
	if (node == NULL)
		return node;  // Base case

	if (node->left != NULL)
	{
		// Convert left subtree
		Node *left = BinTreeListUtil(node->left);
		// Find the inorder predecessor
		while (left->right != NULL)
			left = left->right;

		// Make root as next of predecessor
		// next of the predecessor
		left->right = node;

		// Make predecessor as previous of root
		node->left = left;

	}
	if (node->right != NULL)
	{
		// Process right subtree
		Node *right = BinTreeListUtil(node->right);

		// Find the successors and link in
		while (right->left != NULL)
			right = right->left;

		// Make the node as previous of this node
		right->left = node;

		// Make the sucessor as next of node
		node->right = right;
	}

	return node;
}

Node *BinTreeList(Node *node)
{
	if (node == NULL)
		return node;

	node = BinTreeListUtil(node);

	// Return root of converted list
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

void PrintPreTree(Node *node)
{
	if (node == NULL)
		return;

	cout << node->val << " ";
	PrintPreTree(node->left);
	PrintPreTree(node->right);
}

void InOrder(Node *node)
{
	if (node == NULL)
		return;
	InOrder(node->left);
	// Creat a linked list node
	cout << node->val << " " << endl;
	InOrder(node->right);
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
	else if (x > node->val)
	{
		node->right = InsertNode(node->right, x);
	}
	return node;
}

Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->val = x;
	tNode->left = NULL;
	tNode->right = NULL;

	return tNode;
}