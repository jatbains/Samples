// TreeFromString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Node
{
	char c;
	struct Node *left;
	struct Node *right;

}Node;

Node *AllocNode(char c);
int Search(char arr[], int start, int end, char v);
Node* ConstructTree(char in[], char pre[], int inStrt, int inEnd);
void PrinInOrder(Node *root);
void PrintPreOrder(Node *root);

int main()
{
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
	int len = sizeof(in) / sizeof(in[0]);
	Node *root = NULL;

	root = ConstructTree(in, pre, 0, len - 1);

	cout << "In Order " << endl << endl;
	PrinInOrder(root);

	cout << endl;
	cout << "Pre Order " << endl << endl;

	PrintPreOrder(root);

	cout << endl;
	system("pause");
    return 0;
}

// The algorithm is to pick elements from the pre Order array and get index in the
//  in Order array and everything to left of it will be left subtree and everything 
//  to right will be right subtree

int Search(char arr[], int start, int end, char v)
{
	for (int i = start; i <= end; i++)
	{
		if (arr[i] == v)
			return i;
	}

}

Node* ConstructTree(char in[], char pre[], int inStrt, int inEnd) 
{
	static int preIndex = 0;
	//  Algorithm pick from preorder and check in In order to add to left or right
	if (inStrt > inEnd)   // Base case no more children
		return NULL;

	// Pick next index from preorder traversal

	Node *tNode = AllocNode(pre[preIndex++]);

	// Check for children
	if (inStrt == inEnd)
		return tNode;

	// Find index of this node in inorder traversal

	int InIndex = Search(in, inStrt, inEnd, tNode->c);

	tNode->left = ConstructTree(in, pre, inStrt, InIndex - 1);
	tNode->right = ConstructTree(in, pre, InIndex + 1, inEnd);

	return tNode;

}

void PrintPreOrder(Node *root)
{
	if (root == NULL)
		return;
	cout << " " << root->c << " ";
	PrinInOrder(root->left);
	PrinInOrder(root->right);
}

void PrinInOrder(Node *root)
{
	if (root == NULL)
		return;

	PrinInOrder(root->left);
	cout << " " << root->c << " ";
	PrinInOrder(root->right);
}


Node *AllocNode(char c)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->c = c;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
