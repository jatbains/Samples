// TreeBFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct Node {
	int val;
	struct Node *left;
	struct Node *right;
}Node;

Node * AllocNode(int val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

Node *InsertNode(Node *root,int input)
{
	if (root == NULL)
	{
		return AllocNode(input);
	}
	if (root->val > input)
	{
		// Insert left
		root->left = InsertNode(root->left, input);
	}
	else
	{
		root->right = InsertNode(root->right, input);
	}
	return root;
}

void PrintTreeInOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	// Go left
	PrintTreeInOrder(root->left);
	cout << root->val << endl;
	PrintTreeInOrder(root->right);
}

void PrintPreOrder(Node *root)
{
	if (root == NULL)
		return;

	cout << root->val << endl;
	PrintPreOrder(root->left);
	PrintPreOrder(root->right);
}

void PrintPostOrder(Node *root)
{
	if (root == NULL)
		return;
	
	PrintPostOrder(root->left);
	PrintPostOrder(root->right);
	cout << root->val <<endl;
}
void DFSSearch(Node *root, int x)
{
	if (root == NULL)
		return;
	if (root->val == x)
	{
		cout << "Found the value " << endl;
	}
	// Search left
	if (root->val > x)
	{
		DFSSearch(root->left, x);
	}
	else
	{
		DFSSearch(root->right, x);
	}

	return;
}

void BFSSearch(Node *root, int x)
{
	queue<Node *> bfsQueue;
	Node *temp = NULL;

	if (root == NULL)
	{
		return;
	}
	// add it to queue
	bfsQueue.push(root);

	while (!bfsQueue.empty())
	{
		temp = bfsQueue.front();
		bfsQueue.pop();
		// Check temp
		if (temp->val == x)
		{
			cout << "Found the value " << endl;
			break;
		}
		// Push the right and left nodes into the queue
		if (temp->right != NULL)
		{
			bfsQueue.push(temp->right);
		}
		if (temp->left != NULL)
		{
			bfsQueue.push(temp->left);
		}
	}
}
int main()
{
	queue<Node> depthQueue;
	Node *root = NULL;

	for (int i = 0; i <= 20; i++)
	{
		root = InsertNode(root, rand() %100);
	}
	// Add one more
	root = InsertNode(root, 50);

	cout << "In order " << endl;
	PrintTreeInOrder(root);
	cout << "Pre order " << endl;
	PrintPreOrder(root);
	cout << "Post order " << endl;
	PrintPostOrder(root);

	cout << "DFS search " << endl;
	DFSSearch(root, 50);

	cout << "BFS search " << endl;
	BFSSearch(root,50);
	getchar();
	return 0;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
