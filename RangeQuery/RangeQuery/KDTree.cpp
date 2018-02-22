#include "stdafx.h"
#include "KDTree.h"
#include <iostream>

using namespace std;

static const int k = 2;

KNode * KDTree::AllocNode(int ind, long val)
{
	KNode *temp = (KNode *)malloc(sizeof(KNode));
	temp->index = ind;
	temp->value = val;
	temp->left = temp->right = nullptr;
	return temp;
}

void KDTree::BuildTree(int ind, long val)
{
	root = Insert(root, ind, val);
}

KDTree::KDTree()
{
	root = nullptr;
}

KNode * KDTree::InsertTree(KNode *node, int ind, long val, int depth)
{
	if (node == nullptr)
	{
		node = AllocNode(ind, val);
		return node;
	}

	// Alternate between even and odd rows
	if (depth%k == 0)
	{
		if (ind < node->index)
		{
			node->left = InsertTree(node->left, ind, val, depth + 1);
		}
		else
		{
			node->right = InsertTree(node->right, ind, val, depth + 1);
		}
	}
	else
	{
		if (val < node->value)
		{
			node->left = InsertTree(node->left, ind, val, depth + 1);
		}
		else
		{
			node->right = InsertTree(node->right, ind, val, depth + 1);
		}
	}
	return node;
}

KNode * KDTree::Insert(KNode *node, int ind, long val)
{
	return InsertTree(node, ind, val, 0);
}

bool KDTree::CompareVals(KNode *node, int ind, long val)
{
	if (node->index != ind || node->value != val)
		return false;
	else
		return true;
}

bool KDTree::SearchTree(KNode *node, int ind, long val, int depth)
{
	if (node == nullptr)
		return false;

	if (CompareVals(node, ind, val))
		return true;
	// Else we need to search the tree
	if (depth%k == 0)
	{
		if (ind < node->index)
		{
			SearchTree(node->left, ind, val, depth + 1);
		}
		else
		{
			SearchTree(node->right, ind, val, depth + 1);
		}
	}
	else
	{
		if (val < node->value)
		{
			SearchTree(node->left, ind, val, depth + 1);
		}
		else
		{
			SearchTree(node->right, ind, val, depth + 1);
		}
	}
}

bool KDTree::Search(int ind, long val)
{
	return SearchTree(root, ind, val, 0);
}