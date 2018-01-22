// TreeRefresh.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;

}Node;


class Tree {

public:
	Tree() {
		root = NULL;
		count = 0;
	}
	void CreateTree(int dat);


	void PrintTree(void);
	int NumberOfNodes(void)
	{
		return count;
	}
	bool IsNodePresent(Node *root,int val);
	Node * GetRootNode(void);
	void SetRoot(Node *node)
	{
		root = node;
	}
	int MinDepthofTree(void);
	int TreeHeight(void);
	bool IsBalanced(void);

private:
	bool IsTreeBalanced(Node *root);
	int HeightofTree(Node *root);
	Node * AddNode(Node *root, int val);
	Node * CreateNode(int dat);
	void PrintInOrder(Node *root);
	void PrintPreOrder(Node *root);
	void PrintPostOrder(Node *root);
	int DepthOfTree(Node *root);
	Node* root;
	int count;

};

bool Tree::IsBalanced(void)
{
	return IsTreeBalanced(root);
}

bool Tree::IsTreeBalanced(Node *root)
{
	int lh, rh;
	if (root == NULL)
		return true;

	lh = HeightofTree(root->left);
	rh = HeightofTree(root->right);

	if ((lh < rh ? rh - lh : rh - lh) && 
		IsTreeBalanced(root->left) &&
		IsTreeBalanced(root->right))
		return 1;

	return 0;

}

int Tree::TreeHeight(void)
{
	return HeightofTree(root);
}

int Tree::HeightofTree(Node *root)
{
	if (root == NULL)
		return 0;

	int lh = HeightofTree(root->left);
	int rh = HeightofTree(root->right);

	return (1 + (lh > rh ? lh : rh));
}

int Tree::MinDepthofTree(void)
{
	return DepthOfTree(root);
}

int Tree::DepthOfTree(Node *root)
{
	if (root == NULL)  //Empty
		return 0;

	if (root->left == NULL || root->right == NULL)
		return 1;

	if (!root->left)
		return DepthOfTree(root->right) + 1;
	if (!root->right)
		return DepthOfTree(root->left) + 1;

	return ((DepthOfTree(root->left) < DepthOfTree(root->right) ? DepthOfTree(root->left) : DepthOfTree(root->right)) + 1);


}

void Tree::PrintTree(void)
{
	// Print all three methods of 
	cout << "In order is" << endl;
	PrintInOrder(root);
	cout << "Pre order is " << endl;
	PrintPreOrder(root);
	cout << "Post order is " << endl;
	PrintPreOrder(root);
}

Node * Tree::GetRootNode(void)
{
	return root;
}

bool Tree::IsNodePresent(Node *root,int val)
{
	if (root == NULL)
		return false;  // didn't find it
	if (root->val == val)
		return true;
	if (root->val > val)
		return IsNodePresent(root->left, val);
	else
		return IsNodePresent(root->right, val);
}

void Tree::PrintInOrder(Node *root)
{
	if (root == NULL)
		return;
	PrintInOrder(root->left);
	cout << " Node Value is " << root->val << endl;
	PrintInOrder(root->right);
}

void Tree::PrintPreOrder(Node *root)
{
	if (root == NULL)
		return;
	cout << " Node Value is " << root->val << endl;
	PrintInOrder(root->left);
	PrintInOrder(root->right);
}

void Tree::PrintPostOrder(Node *root)
{
	if (root == NULL)
		return;
	PrintInOrder(root->left);
	PrintInOrder(root->right);
	cout << " Node Value is " << root->val << endl;
}

void Tree::CreateTree(int dat)
{
	root = AddNode(root,dat);
}

Node * Tree::AddNode(Node *root, int val)
{
	if (root == NULL)
	{
		return root = CreateNode(val);
	}
	// Empty tree
	// Recursively add nodes to tree
	if (val < root->val)
	{
		root->left = AddNode(root->left, val);
	}
	else
	{
		root->right = AddNode(root->right, val);
	}
	return root;
}
 
Node * Tree::CreateNode(int dat)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = dat;
	temp->left = NULL;
	temp->right = NULL;
	count++;
	return temp;
}


int main()
{
	int data[] = { 33,2,12,29,67,53,15,7,29,42,34,9,22 };
	Tree myTree;
	Node *root = NULL;
	int size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < size; i++)
	{
		//root = myTree.AddNode(root,data[i]);
		myTree.CreateTree(i);
	}
	//

	// Print out the Tree in order
	myTree.PrintTree();

	

	cout << endl << "Min Depth of tree " << myTree.MinDepthofTree() << endl;

	cout << endl << "Height of tree is " << myTree.TreeHeight() << endl;

	cout << endl << "Is the tree balanced " << myTree.IsBalanced() << endl;


	system("pause");
    return 0;
}

