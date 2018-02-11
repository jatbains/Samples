#pragma once
/*
	This defines the custom AVL Tree class which will be used for storing 
	and querying the input data.
*/
#include "RangeIds.h"

typedef struct Node
{
	short index;
	long key;
	int height;
	struct Node *left;
	struct Node *right;
}Node;

class AVLTree
{
private:
	Node * root;
	int count;
	void PrintInOrderTree(Node *node);
	Node * InsertNode(Node *node, long key, short index);
	Node * AllocNode(long key, short index);
	Node *RightRotate(struct Node *y);
	Node *LeftRotate(struct Node *x);
	int GetBalance(Node *node);
	int MaxVal(int x, int  y);
	int FindNodes(RangeIds *range,Node *root, long fromValue, long toValue);
	int FindNodes(RangeIds *range, Node *root, long fromValue, long toValue,bool fromIncl,bool toIncl);
public:
	AVLTree();
	void BuildTree(long key, short index);
	void PrintTree();
	int NodeHeight(Node *node);
	int FindNodesInRange(RangeIds *range,long fromValue, long toValue);
	int FindNodesInRange(RangeIds *range, long fromValue, long toValue,bool fromIncl,bool toIncl);
};
