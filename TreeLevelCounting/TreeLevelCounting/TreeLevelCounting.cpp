// TreeLevelCounting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct TreeNode
{
	int key;
	struct TreeNode *left;
	struct TreeNode *right;
	
}TreeNode;

TreeNode * AllocNode(int x);
TreeNode * InsertNode(TreeNode *node, int x);
void PrintTree(TreeNode *node);
int HeightOfTree(TreeNode *node);
int MaxAtLevel(TreeNode * node, int i, int l);
int CountOfMaxNodes(TreeNode *node,int &level);
void MaxAtLevel(TreeNode * node, int i, int l, int &count);
int MaxNodeAtLevel(TreeNode *node, int &level);
int GetWidth(TreeNode *node, int level);
int TreeWidth(TreeNode *node);

int main()
{
	TreeNode *root = nullptr;
	int data[] = { 13,2,15,8,5,18,21,6,9,23,11 };
	int size = sizeof(data) / sizeof(data[0]);
	int max_level = 0;

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	PrintTree(root);
	cout << endl;
	cout << "Height of tree is " << HeightOfTree(root) << endl;

	cout << "Count of Max Nodes at level " << max_level << " is " << CountOfMaxNodes(root,max_level) << endl;
	cout << "Count of Max Nodes at level " << max_level << " is " << MaxNodeAtLevel(root, max_level) << endl;
	cout << endl;

	cout << "Width of the tree is " << TreeWidth(root) << endl;

	system("pause");
    return 0;
}


int TreeWidth(TreeNode *node)
{
	int ht = HeightOfTree(node);
	bool isLeft = true;
	int width = 0;
	int temp_wd = 0;
	for (int i = 0; i < ht; i++)
	{
		temp_wd = GetWidth(node, i);
		if (temp_wd > width)
		{
			width = temp_wd;
		}
	}
	return width;
}

int GetWidth(TreeNode *node, int level)
{
	if (node == nullptr)
		return 0;
	if (level == 1)
		return 1;
	else
		return (GetWidth(node->left, level - 1) + GetWidth(node->right, level - 1));
}

int CountOfMaxNodes(TreeNode *node,int &level)
{
	int ht = HeightOfTree(node);
	int max_nodes = 0;
	int temp_nodes = 0;
	int max_level = 0;

	for (int i = 0; i < ht; i++)
	{
		temp_nodes = MaxAtLevel(node, 0, i);

		if (temp_nodes > max_nodes)
		{
			max_nodes = temp_nodes;
			max_level = i;
			
		}
	}
	level = max_level;
	return max_nodes;
}

int MaxNodeAtLevel(TreeNode *node, int &level)
{
	int ht = HeightOfTree(node);
	int max_nodes = 0;
	int temp_nodes = 0;
	int max_level = 0;
	int count = 0;

	for (int i = 0; i < ht; i++)
	{	
		MaxAtLevel(node, 0, i, count);
		if (count > max_nodes)
		{
			max_nodes = count;
			max_level = i;
		}
		count = 0;
	}
	level = max_level;
	return max_nodes;
}
int MaxAtLevel(TreeNode * node, int i, int l)
{
	if (node == nullptr)   // At the bottom of tree
		return 0;
	if (i == l)
	{
		return 1;  	 // Found a node at level
	}
	return (MaxAtLevel(node->left,i+1,l) + MaxAtLevel(node->right,i+1,l));
}

void MaxAtLevel(TreeNode * node, int i, int l,int &count)
{
	if (node == nullptr)   // At the bottom of tree
		return;
	if (i == l)
	{
		count++;
		return;// Found a node at level
	}
	
	MaxAtLevel(node->left, i + 1, l,count);
	MaxAtLevel(node->right, i + 1, l,count);
	return;
}

int HeightOfTree(TreeNode *node)
{
	if (node == nullptr)
		return 0;
	int lh = HeightOfTree(node->left);
	int rh = HeightOfTree(node->right);

	return (lh > rh ? lh + 1 : rh + 1);
}

void PrintTree(TreeNode *node)
{
	if (node == nullptr)
		return;
	// go left
	PrintTree(node->left);
	cout << "Key is " << node->key << endl;
	PrintTree(node->right);
}

TreeNode * AllocNode(int x)
{
	TreeNode *tNode = (TreeNode *)malloc(sizeof(TreeNode));
	tNode->key = x;
	tNode->left = tNode->right = nullptr;
	return tNode;
}

TreeNode * InsertNode(TreeNode *node, int x)
{
	if (node == nullptr)
	{
		node = AllocNode(x);
		return node;
	}
	
	if (x < node->key)
	{
		node->left = InsertNode(node->left, x);
	}
	else
	{
		node->right = InsertNode(node->right, x);
	}
	return node;
}