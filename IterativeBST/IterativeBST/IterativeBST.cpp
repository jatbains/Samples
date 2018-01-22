// IterativeBST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}Node;

Node * CreateTree(int pre[], int size);
Node *ConstructTree(int pre[], int *preIndex, int lStrt, int rEnd, int size);
int GetIndex(int arr[], int x, int low, int high);
Node *AllocNode(int x);
void PrintPreOrder(Node *root);
void IterativePreOrder(Node *root);

int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);
	
	Node *root = CreateTree(pre, size);

	PrintPreOrder(root);
	cout << "Iterative PreOrder" << endl;

	IterativePreOrder(root);


	system("pause");
    return 0;
}

void IterativePreOrder(Node *root)
{
	if (root == NULL)   // Empty tree
		return;

	stack<Node*> preStack;

	// Push root onto the stack
	preStack.push(root);    // Push the root onto the stack

	// While stack is not empty pop off entries
	// Print them out and push first right then left entries
	while (!preStack.empty())
	{
		Node *tNode = preStack.top();   // Get top element

		cout << " " << tNode->val <<" " << endl;

		preStack.pop();

		// Push right and then left chidren
		if (tNode->right)
			preStack.push(tNode->right);
		if (tNode->left)
			preStack.push(tNode->left);

	}

}

void PrintPreOrder(Node *root)
{
	if (root == NULL)  // Done
		return;   

	cout << " " << root->val << " " << endl;
	PrintPreOrder(root->left);
	PrintPreOrder(root->right);
	return;
}

Node * CreateTree(int pre[],int size)
{
	int preIndex = 0;
	return ConstructTree(pre, &preIndex, 0, size - 1, size);
}

Node *ConstructTree(int pre[], int *preIndex, int lStrt, int rEnd,int size)
{
	if (*preIndex >= size || lStrt > rEnd)    // At the end of the data set
		return NULL;


	// Allocate a new node
	Node *tNode = AllocNode(pre[*preIndex]);

	*preIndex += 1;
	// If lStrt and rEnd are equal  no children
	if (lStrt == rEnd)
		return tNode;

	// Find the first element greater than root
	int i = GetIndex(pre, pre[*preIndex], lStrt, rEnd);

	// Now we add smaller values under left and larger under right

	tNode->left = ConstructTree(pre, preIndex, *preIndex, i - 1, size);
	tNode->right = ConstructTree(pre, preIndex, i , rEnd, size);

	return tNode;

}

int GetIndex(int arr[], int x,int low, int high)
{
	for (int i = low; i <= high; ++i)
	{
		if (arr[i] > x)
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