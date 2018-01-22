// PrintKNodesAwayInTree.cpp : Defines the entry point for the console application.
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

Node *InsertNode(Node *root, int x);
Node *AllocNode(int x);
void PrintkDistanceDown(Node *node, int k);
int PrintKDistanceNode(Node *node, int target, int k);

int main()
{
	int data[] = { 11,2,15,4,9,17,21,25,5,7 };
	int size = sizeof(data) / sizeof(data[0]);
	Node *root = NULL;

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	// Find a Node k distance from a specific node
	// assume node is one with value 17
	// check for node->val== 17
	PrintKDistanceNode(root, 17, 2);

	system("pause");
    return 0;
}

void PrintkDistanceDown(Node *node,int k)
{
	// Base case
	if (node == NULL || k < 0)
		return;

	// Value found
	if (k == 0)
	{
		cout << "Node " << node->val << endl;
		return;
	}


	// Recur down the tree
	PrintkDistanceDown(node->left, k - 1);
	PrintkDistanceDown(node->right, k - 1);
}


int PrintKDistanceNode(Node *node, int target, int k)
{
	// Base case Node == NULL done
	if (node == NULL)
		return -1;

	if (node->val == target)  // found the node of interest and call function for k away
	{
		PrintkDistanceDown(node, k);
		return 0;
	}

	// Recur for left tree
	int dl = PrintKDistanceNode(node->left,target, k);
	// Check dl
	if (dl != -1)
	{
		// If root is at k from target
		if (dl + 1 == k)
			cout << "Node " << node->val << endl;
		else
			PrintkDistanceDown(node->right, k);  // Print values in right subtree
		return dl + 1;
	}
	
	// Recur for the right subtree
	int dr = PrintKDistanceNode(node->right, target, k);

	if (dr != -1)
	{
		if (dr + 1 == k)
			cout << "Node " << node->val << endl;
		else
			// process the left subtree
			PrintkDistanceDown(node->left, k);
		return dr + 1;
	}
}


Node *InsertNode(Node *root, int x)
{
	if (root == NULL)
	{
		root = AllocNode(x);
		return root;
	}
	if (x < root->val)
	{
		root->left = InsertNode(root->left, x);
	}
	else
	{
		root->right = InsertNode(root->right, x);
	}
	return root;
}

Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->val = x;
	tNode->left = tNode->right = NULL;

	return tNode;
}
