// MinimalTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef struct Tree
{
	int val;
	struct Tree *left;
	struct Tree *right;
}Tree;

Tree *root;

void AddNode(Tree **root, int val);
Tree *NewNode(int val);
Tree* sortedArrayToBST(int arr[], int start, int end);
void PrintPreorder(Tree *node);
void PrintInOrder(Tree *node);
void PrintPostOrder(Tree *node);
bool IsBalanced(Tree *node);
int Height(Tree *node);
void ValidateBST(Tree *node, bool *isBal);
Tree* MinNodeInTree(Tree *node);




int main()
{
	int values[9] = { 1,2,3,4,5,6,7,8,9};
	int n = sizeof(values) / sizeof(values[0]);
	bool IsValidBST = true;
	cout << "The size of the array is " << n << endl;
	// Pick the mid point and add recursively to tree
	root = sortedArrayToBST(values, 0, n - 1);
	cout << "Print in In Order " << endl << endl;;
	PrintInOrder(root);
	cout << "Print in Pre Order " << endl << endl;;
	PrintPreorder(root);
	cout << "Print in Post Order " << endl << endl;;
	PrintPostOrder(root);

	cout << " The tree is " << (IsBalanced(root) ?  " Balanced " : " Unbalanced ") << endl << endl;

	cout << "Check if it is a Valid BST  " << endl;

	ValidateBST(root, &IsValidBST);
	cout << "This tree is " << (IsValidBST ? "Valid BST" : "Invalid BST") << endl;

	system("pause");
    return 0;
}

Tree * MinNodeInTree(Tree *node)
{
	Tree *current = node;
	// Traverse down to the left most leaf node
	while (current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

// Find the Inorder Sucessor
Tree* InOrderSuccessor(Tree *root, Tree *node)
{
	Tree *curr = NULL, *succ= NULL;
	// If the Right subtree is NULL then get minimum from left
	if (node->right != NULL)
	{
		curr = MinNodeInTree(node);
		return curr;
	}
	// Else start search from the root
	while (root != NULL)
	{
		if (node->val < root->val)
		{
			succ = root;
			root = root->left;
		}
		else if (node->val > root->val)
		{
			root = root->right;
		}
		else
			break;
	}
	return succ;
}

void ValidateBST(Tree *node , bool *isBal)
{
	// A binary search tree is valid the value of a node is greater than
	// left node and less than right node
	// Base case is when node is NULL
	if (node == NULL)
		return;
	// At any level check
	if (node->left != NULL)
	{
		if (node->val < (node->left->val))
			*isBal = false;
	}
	if (node->right != NULL)
	{
		if (node->val > (node->right->val))
			*isBal = false;
	}
	ValidateBST(node->left, isBal);
	ValidateBST(node->right, isBal);

	return;
}

// Determine if a tree is balanced
// Need to check the lh and rh and make sure they don't differs by more than one
bool IsBalanced(Tree *node)
{
	int lh;  // Left Height
	int rh;  // Right Height

	if (node == NULL)
		return true;

	// Check the left and right heights
	lh = Height(node->left);
	rh = Height(node->right);
	// We have the lh and rh compare them
	if (abs(lh - rh) <= 1 &&
		IsBalanced(node->left) &&
		IsBalanced(node->right))
		return 1;

	/* If we reach here then tree is not height-balanced */
	return 0;

}

int Height(Tree *node)
{
	if (node == NULL)
		return 0;
	
	return 1 + max(Height(node->left) , Height(node->right));
}

Tree* sortedArrayToBST(int arr[], int start, int end)
{
	/* Base Case */
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;
	struct Tree *root = NewNode(arr[mid]);

	/* Recursively construct the left subtree and make it
	left child of root */
	root->left = sortedArrayToBST(arr, start, mid - 1);

	/* Recursively construct the right subtree and make it
	right child of root */
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

Tree *NewNode(int val)
{
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void AddNode(Tree **node,int val)
{
	// Check for NULL
	if (*node == NULL)
	{
		*node = NewNode(val);
		return;
	}

	 // We need to recurse down to put in the leaf node
	if (val < (*node)->val)
	{
		AddNode(&(*node)->left, val);
	}
	else
	{
		AddNode(&(*node)->right, val);
	}

	return;
}
void PrintPreorder(Tree *node)
{
	if (node == NULL)
		return;
	cout << "The value is " << node->val << endl;
	PrintPreorder(node->left);
	PrintPreorder(node->right);

}
void PrintInOrder(Tree *node)
{
	if (node == NULL)
		return;
	PrintPreorder(node->left);
	cout << "The value is " << node->val << endl;
	PrintPreorder(node->right);
}
void PrintPostOrder(Tree *node)
{
	if (node == NULL)
		return;
	PrintPreorder(node->left);
	PrintPreorder(node->right);
	cout << "The value is " << node->val << endl;
}
