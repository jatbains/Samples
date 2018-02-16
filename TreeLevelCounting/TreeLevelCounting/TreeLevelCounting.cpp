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
int MaxAtLevel(TreeNode * node, int i, int l, int count);
int CountOfMaxNodes(TreeNode *node,int &level);

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
	cout << endl;

	system("pause");
    return 0;
}

int CountOfMaxNodes(TreeNode *node,int &level)
{
	int ht = HeightOfTree(node);
	int max_nodes = 0;
	int temp_nodes = 0;
	int max_level = 0;

	for (int i = 1; i <= ht; i++)
	{
		temp_nodes = MaxAtLevel(node, 0, i, 0);
		if (temp_nodes > max_nodes)
		{
			max_nodes = temp_nodes;
			max_level = i;
			
		}
	}
	level = max_level;
	return max_nodes;

}

int MaxAtLevel(TreeNode * node, int i, int l,int count)
{
	
	if (node == nullptr)
		return count;
	if (i == l)
	{
		return 1;
	}
	return (MaxAtLevel(node->left,i+1,l,count) + MaxAtLevel(node->right,i+1,l,count));
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