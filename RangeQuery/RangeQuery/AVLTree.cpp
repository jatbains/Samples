/* 
	This is the module that implements the methods for the AVL
	Tree class.  The tree supports a Query which returns the nodes
	that fall into a range being queried.
*/


#include "stdafx.h"
#include "AVLTree.h"
#include <iostream>
#include "RangeIds.h"

using namespace std;

AVLTree::AVLTree()
{
	root = nullptr;
	count = 0;
}

void AVLTree::PrintTree(void)
{
	PrintInOrderTree(root);
}

void AVLTree::PrintInOrderTree(Node *node)
{
	if (node == nullptr)
		return;
	PrintInOrderTree(node->left);
	cout << node->key << " " << node->index << endl;
	PrintInOrderTree(node->right);
}
int AVLTree::NodeHeight(Node *node)
{
	if (node == nullptr)
		return 0;
	return node->height;
}

Node * AVLTree::AllocNode(long key, short index)
{
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->index = index;
	temp->key = key;
	temp->height = 1;
	temp->left = temp->right = nullptr;
	return temp;
}

void AVLTree::BuildTree(long key, short index)
{
	root = InsertNode(root, key, index);
}

int AVLTree::GetBalance(Node *node)
{
	if (node == nullptr)
		return 0;

	return (NodeHeight(node->left) - NodeHeight(node->right));
}

int AVLTree::MaxVal(int x, int  y)
{
	return (x > y ? x : y);
}

Node *AVLTree::RightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = MaxVal(NodeHeight(y->left), NodeHeight(y->right)) + 1;
	x->height = MaxVal(NodeHeight(x->left), NodeHeight(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node *AVLTree::LeftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	//  Update heights
	x->height = MaxVal(NodeHeight(x->left), NodeHeight(x->right)) + 1;
	y->height = MaxVal(NodeHeight(y->left), NodeHeight(y->right)) + 1;

	// Return new root
	return y;
}


Node *AVLTree::InsertNode(Node *node, long key, short index)
{
	if (node == nullptr)
	{
		node = AllocNode(key, index);
		return node;
	}
	if (key < node->key)
	{
		node->left = InsertNode(node->left, key, index);
	}
	else
	{
		node->right = InsertNode(node->right, key, index);
	}
	return node;

	// Update Height of the Ancestor node
	node->height = 1 + MaxVal(NodeHeight(node->left), NodeHeight(node->right));

	// Get the balance factor
	int balance = GetBalance(node);

	if (balance > 1 && key < node->left->key)
		return RightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return LeftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = LeftRotate(node->left);
		return RightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = RightRotate(node->right);
		return LeftRotate(node);
	}

	return node;
}

int AVLTree::FindNodes(RangeIds *range,Node *node, long fromValue, long toValue)
{
	if (node == nullptr)
		return 0;

	if (fromValue < node->key)
	{
		// Search left
		FindNodes(range,node->left, fromValue, toValue);
	}
	if (fromValue <= node->key && toValue >= node->key)
	{
		// cout << "Value is " << node->key << " Index is " << node->index << endl;
		// Store these in the Ids
		range->StoreValues(node->index);
	}

	if (toValue >= node->key)
	{
		FindNodes(range,node->right, fromValue, toValue);
	}
}

int AVLTree::FindNodesInRange(RangeIds *range,long fromValue, long toValue)
{
	return FindNodes(range,root,fromValue,toValue);
}

int AVLTree::FindNodesInRange(RangeIds *range, long fromValue, long toValue, bool fromIncl, bool toIncl)
{
	return FindNodes(range, root, fromValue, toValue,fromIncl,toIncl);
}

int AVLTree::FindNodes(RangeIds *range, Node *node, long fromValue, long toValue,bool fromIncl,bool toIncl)
{
	if (node == nullptr)
		return 0;

	if (fromValue < node->key)
	{
		// Search left
		FindNodes(range, node->left, fromValue, toValue,fromIncl,toIncl);
	}
	if (fromIncl && toIncl)
	{
		if (fromValue <= node->key && toValue >= node->key)
		{
			// cout << "Value is " << node->key << " Index is " << node->index << endl;
			// Store these in the Ids
			range->StoreValues(node->index);
		}
	}
	if (!fromIncl && toIncl)
	{
		if (fromValue < node->key && toValue >= node->key)
		{
			// cout << "Value is " << node->key << " Index is " << node->index << endl;
			// Store these in the Ids
			range->StoreValues(node->index);
		}
	}
	if (fromIncl && !toIncl)
	{
		if (fromValue <= node->key && toValue > node->key)
		{
			// cout << "Value is " << node->key << " Index is " << node->index << endl;
			// Store these in the Ids
			range->StoreValues(node->index);
		}
	}
	if (!fromIncl && !toIncl)
	{
		if (fromValue < node->key && toValue > node->key)
		{
			// cout << "Value is " << node->key << " Index is " << node->index << endl;
			// Store these in the Ids
			range->StoreValues(node->index);
		}
	}

	if (toValue > node->key)
	{
		FindNodes(range, node->right, fromValue, toValue,fromIncl,toIncl);
	}
}