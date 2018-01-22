// BFSOfTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}Node;

using namespace std;

void PrintInOrder(Node *root);
Node *InsertIntoTree(Node *root, int x);
Node *AllocNode(int x);
void PreOrder(Node *root);
bool DFSSearchOfTree(Node *root, int x);

int main()
{
	Node *root = NULL;
	int data[] = { 9,3,12,7,18,2,21,10,5,17,1 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		root = InsertIntoTree(root, data[i]);
	}

	PrintInOrder(root);

	cout << endl;

	PreOrder(root);

	// Search for a Node in Tree
	cout << (DFSSearchOfTree(root, 18) ? "Node was found" : "Node not Found") << endl;

	system("pause");
    return 0;
}

bool DFSSearchOfTree(Node *root,int x)
{
	// Do a DFS search of the tree 
	// How to do this on a recursive structure 
	// Use a queue and put in the root first then pop if off and
	// investigate.  Then insert left and right nodes and investigate and pop
	//  until queue is empty
	queue<Node*> dfsq;
	Node *t = NULL;

	// Check root first
	if (root->val == x)
		return true;

	dfsq.push(root);

	while (!dfsq.empty())
	{
		
		Node *temp = dfsq.front();  // Getting nodes from the front of queue
		dfsq.pop();

		cout << "Queue size " << dfsq.size() << endl;

		if (temp->val == x)
		{
			cout << endl << "Node Value is " << temp->val << endl;
			return true;
		}


		// else push right and left onto queue
		if (temp->left != NULL)
			dfsq.push(temp->left);
		if (temp->right != NULL)
			dfsq.push(temp->right);
	

	}
	
	return false;

}

void PreOrder(Node *root)
{
	if (root == NULL)
		return;
	cout << "Value " << root->val << endl;
	PreOrder(root->left);
	PreOrder(root->right);
}

void PrintInOrder(Node *root)
{
	if (root == NULL)
		return;

	PrintInOrder(root->left);
	cout << "Value " << root->val << endl;
	PrintInOrder(root->right);

}

Node *InsertIntoTree(Node *root, int x)
{
	if (root == NULL)
	{
		root = AllocNode(x);
		return root;
	}
	// Recurse and add to the tree
	if (x < root->val)
	{
		root->left = InsertIntoTree(root->left, x);
	}
	else
	{
		root->right = InsertIntoTree(root->right, x);
	}
	return root;
}

Node *AllocNode(int x) 
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}