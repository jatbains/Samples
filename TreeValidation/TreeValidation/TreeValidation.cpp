// TreeValidation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *right;
	struct Node *left;
}Node;

Node * AllocNode(int val);
Node * InsertNode(Node *node, int val);
void PrintInOrder(Node *node);
int SmallestValue(Node *node);
Node * MinValueNode(Node *node);
Node * DeleteNode(Node *node, int val);

int main()
{
	Node *root = NULL;
	int data[] = { 12,4,6,13,9,2,15,5,24,19,7,27,8,21,25,29 };
	int size = sizeof(data) / sizeof(data[0]);
	
	for (int i = 0; i < size; i++)
	{
		//root = InsertNode(root, rand());
		root = InsertNode(root, data[i]);
	}

	PrintInOrder(root);

	cout << "Smallest Value is " << SmallestValue(root) << endl;
	//cout << "Address of smallest node is " << MinValueNode(root) << endl;

	// Delete a node Delete node 19
	root = DeleteNode(root, 19);

	PrintInOrder(root);

	system("pause");
    return 0;
}

Node * DeleteNode(Node *node, int val)
{
	if (node == NULL)
		return node;   // empty
	// Recurse left or right
	if (val < node->val)
		node->left = DeleteNode(node->left, val);
	else if (val > node->val)
		node->right = DeleteNode(node->right, val);

	else
	{
		// Node with one child
		if (node->left == NULL)
		{
			Node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			Node *temp = node->left;
			free(node);
			return temp;
		}
		// Node with two children get inorder successor smallest in right subtree
		Node *temp = MinValueNode(node->right);
		// Copy inorder successors value to this node
		node->val = temp->val;
		// Delete in order successor 
		node->right = DeleteNode(node->right, temp->val);

	}
	return node;
}

int SmallestValue(Node *node)
{
	if (node == NULL)
		return 0;
	// Recurse to left most value
	if (node->left != NULL)
	{
		SmallestValue(node->left);
	}
	else
	{
		return node->val;
	}
}

Node * MinValueNode(Node *node)
{
	Node *current = node;
	if (node == NULL)
		return NULL;
	while (current->left != NULL)
		current = current->left;
	return current;
}

void PrintInOrder(Node *node)
{
	if (node == NULL)   // Base case
		return;

	PrintInOrder(node->left);
	cout << "Node Value is " << node->val << endl;
	PrintInOrder(node->right);

}

Node * InsertNode(Node *node,int val)
{
	if (node == NULL)
	{
		node = AllocNode(val);
		return node;
	}
	// Recurse left or right depending on value
	if (node->val > val)
	{
		node->left = InsertNode(node->left, val);
	}
	else
	{
		node->right = InsertNode(node->right, val);
	}
	return node;
}
Node * AllocNode(int val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}