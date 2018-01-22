// TernaryToBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	char c;
	struct Node *right;
	struct Node *left;
}Node;

Node * InsertNode(Node *,char c, char op);
Node * AllocNode(char c);
Node * ConvertExpression(string str, int i);
void PrintInOrder(Node *node);

int main()
{
	string str = "a?b?c:d:e";  // We wish to convert this to a binary tree
	Node *root;
	char *c;

	root = ConvertExpression(str, 0);

	PrintInOrder(root);

	system("pause");
    return 0;
}

// Print out the Tree in Order
void PrintInOrder(Node *node)
{
	if (node == NULL)
		return;
	PrintInOrder(node->left);
	cout << "Node Value is " << node->c << endl;
	PrintInOrder(node->right);

}

// The Insert Routine will

// need to insert based on the string
Node * ConvertExpression(string str, int i)
{
	if (i > str.size())   // End of the string
		return NULL;

	Node *root = AllocNode(str[i]);  // First node
	i++;                              // Move forward
	 
	// Go left or right depending on the value
	if (i < str.size() && str[i] == '?')  // Go left
	{
		root->left = ConvertExpression(str, i+1);
	}
	else if (i < str.size() && str[i] == ':')
	{
		root->right = ConvertExpression(str, i+1);
	}
	
	return root;
}
Node * InsertNode(Node *node,char c, char op)
{
	if (node == NULL)
	{
		node = AllocNode(c);
		return node;
	}
	// Recurse based on op
	if (op == '?')
	{
		node->left = InsertNode(node->left, c, op);
	}
	else if (op == ':')
	{
		node->right = InsertNode(node->right, c, op);
	}
	return node;

}
Node * AllocNode(char c)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->c = c;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

