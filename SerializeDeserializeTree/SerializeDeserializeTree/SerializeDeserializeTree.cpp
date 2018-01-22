// SerializeDeserializeTree.cpp : Defines the entry point for the console application.
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

Node *InsertNode(Node * node, int x);
Node *AllocNode(int x);
void PrintPreOrder(Node *root,int ser[],int &i);
Node * Deserailize(Node *root, int val);

int main()
{
	int data[] = { 10,14,9,12,17,22,4,6,15,29 };
	int ser[25] = { 0 };
	Node *root = NULL;
	Node *droot = NULL;
	int size = sizeof(data)/sizeof(data[0]);
	static int index = 0;

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	PrintPreOrder(root,ser,index);

	for (int i = 0; i < 25; i++)
	{
		cout << ser[i] << endl;
	}

	for (int i = 0; i < 25; i++)
	{
		//droot = Deserailize(droot, ser[i]);
	}

	cout << endl;
	system("pause");
    return 0;
}

Node * Deserailize(Node *root,int val)
{
	if (val == -1)
		return NULL;
	//else
	root = AllocNode(val);
	root->left = Deserailize(root->left, val);
	root->right = Deserailize(root->right, val);

	return root;
}

void PrintPreOrder(Node *root,int ser[],int &i)
{ 
	i++;
	if (root == NULL)    // Finished
	{
		cout <<" " << -1 << " ";
		ser[i] = -1;
		return;
	}


	cout << " " << root->val << " ";
	ser[i] = root->val;
	PrintPreOrder(root->left,ser,i);
	PrintPreOrder(root->right,ser,i);
}

Node *InsertNode(Node * node, int x)
{
	if (node == NULL)
	{
		node = AllocNode(x);     // root node
		return node;
	}

	// Check Left or right subtrees
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