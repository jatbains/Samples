// ListofTrees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Tree
{
	int val;
	struct Tree* left;
	struct Tree* right;
}Tree;

void CreateTree(Tree **node, int val);
void PrintPreOrder(Tree *node);
void PrintInOrder(Tree *node);
void PrintPostOrder(Tree *node);
int TreeDepth(Tree *node);
int MaxHeight(Tree *node);
bool IsBalanced(Tree *node);
Tree *NewNode(int val);
Tree * AddNode(Tree *node, int val);

int main()
{
	int i = 0;
	Tree *root = NULL;
	int data[] = { 50,32,74,21,66,19,83,11,87,5,55,13,67,2,72,18};
	for (int i = 0; i < 16; i++)
	{
		//CreateTree(&root, data[i]);
		root = AddNode(root, data[i]);
	}

	PrintInOrder(root);

	cout << "Min depth of tree is " << TreeDepth(root) << endl;
	cout << "Max depth of tree is " << MaxHeight(root) << endl;
	cout << "The tree is " << (IsBalanced(root) ? "Balaced" : "Not Balanced") << endl;
	system("pause");
    return 0;
}

int TreeDepth(Tree *node)
{
	int ld = 0;
	int rd = 0;
	if (node == NULL)
		return 0;
	if ((node->left == NULL)&&(node->right == NULL))
		return 1;
	// Recurse left and right

	ld = TreeDepth(node->left)+1;
	rd = TreeDepth(node->right)+1;
	return (1 + ld < rd ? ld : rd);
}
bool IsBalanced(Tree *node)
{
	int lh = 0, rh = 0;
	if (node == NULL)
		return true;
	lh = MaxHeight(node->left);
	rh = MaxHeight(node->right);
	if ((lh > rh ? lh - rh : rh - lh)<=1 &&
		IsBalanced(node->left)&&
		IsBalanced(node->right))
		return true;
	return false;
}
int MaxHeight(Tree *node)
{
	int ld = 0, rd = 0;
	if (node == NULL)
		return 0;
	ld = 1 + MaxHeight(node->left);
	rd = 1 + MaxHeight(node->right);
	return (ld > rd ? ld : rd);
}

void PrintPreOrder(Tree *node)
{
	if (node == NULL)
		return;
	cout << "Value is " << node->val << endl;
	PrintPreOrder(node->left);
	PrintPreOrder(node->right);
}
void PrintInOrder(Tree *node)
{
	if (node == NULL)
		return;

	PrintPreOrder(node->left);
	cout << "Value is " << node->val << endl;
	PrintPreOrder(node->right);
}
void PrintPostOrder(Tree *node)
{
	if (node == NULL)
		return;

	PrintPreOrder(node->left);
	PrintPreOrder(node->right);
	cout << "Value is " << node->val << endl;

}

Tree * AddNode(Tree *node,int val)
{
	if (node == NULL)
		return NewNode(val);

	// Recur down the tree
	if (node->val > val)
		node->left = AddNode(node->left, val);
	else if (node->val <= val)
		node->right = AddNode(node->right, val);

	return node;
}

Tree *NewNode(int val)
{
	Tree *temp = (Tree *)malloc(sizeof(Tree));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void CreateTree(Tree **node, int val)
{
	
	if ((*node) == NULL)
	{

		(*node) = NewNode(val);
		return;
	}

	if ((*node)->val > val)
	{
		// Recurse left
		CreateTree(&(*node)->left,val);
	}
	else if ((*node)->val > val)
	{
		CreateTree(&(*node)->right, val);
	}

}
