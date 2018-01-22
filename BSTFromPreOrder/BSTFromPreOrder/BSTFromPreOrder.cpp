// BSTFromPreOrder.cpp : Defines the entry point for the console application.
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
int GetIndex(int arr[], int lStrt, int hEnd, int val);
Node *ConstructTree(int arr[], int *preINdex,int lStrt, int hEnd,int size);
void PrintPreOrder(Node *node);
void PrintInOrder(Node *node);
// We have a Preorder list which we process
// In Preorder the root is first element and then we find the next element
// greater than root and we divide left adn right trees.  We do this recursively
// until we get the complete tree

int main()
{
	Node *root = NULL;
	int data[] = { 40,3,10,25,30,45,65,38,50,35 };
	int size = sizeof(data) / sizeof(data[0]);
	int preIndex = 0;

	root = ConstructTree(data, &preIndex, 0, size - 1, size);

	cout << "Print in PreOrder" << endl;
	PrintPreOrder(root);
	cout << "Print In Order" << endl;
	PrintInOrder(root);
	cout << endl;
	system("pause");
    return 0;
}

void PrintInOrder(Node *node)
{
	if (node == NULL)
		return;
	PrintInOrder(node->left);
	cout << " " << node->val << " " << endl;
	PrintInOrder(node->right);
}

void PrintPreOrder(Node *node)
{
	// Base case
	if (node == NULL)
		return;
	// Visit root first
	cout << " " << node->val << " " << endl;
	PrintPreOrder(node->left);
	PrintPreOrder(node->right);
}

Node *ConstructTree(int arr[], int *preIndex, int lStrt, int hEnd,int size)
{
	if (*preIndex > size || lStrt > hEnd)   // Done processing
		return NULL;

	// Get Next value in Pre Order list
	int val = arr[*preIndex];
	// Alocate a node
	Node *tNode = AllocNode(val);
	*preIndex += 1;

	// Check for no Children

	if (lStrt == hEnd)
		return tNode;

	int index = GetIndex(arr, lStrt, hEnd, val);

	// Else we need to add this node into the tree
	// Add elements smaller than it to left and elements 
	// larger than it to the right
	tNode->left = ConstructTree(arr, preIndex, *preIndex, index - 1,size);
	tNode->right = ConstructTree(arr, preIndex, index, hEnd,size);

	return tNode;
}

int GetIndex(int arr[],int lStrt,int hEnd, int val)
{
	// We go through the list and find index of ist value greater than current
	for (int i = lStrt; i <= hEnd; ++i)
	{
		if (arr[i] > val)
			return i;
	}

}


Node *AllocNode(int x)
{
	Node *tNode = (Node*)malloc(sizeof(Node));
	tNode->val = x;
	tNode->left = NULL;
	tNode->right = NULL;

	return tNode;
}