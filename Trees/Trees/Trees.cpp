// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;



typedef struct Tree
{
	int data;
	struct Tree *right;
	struct Tree *left;

}Tree;

void AddNode(Tree ** root,int val);
void DeleteNode(int val);
void PrintInTree(Tree *root);
void PrintPostTree(Tree *root);
void PrintPreTree(Tree *root);

int main()
{
	Tree *root = NULL;
	cout << " Creating a Binary tree " << endl;
	
	for (int i = 1; i <= 20; i++)
	{
		AddNode(&root,rand());
	}

	cout << "Inorder Tree is " << endl;
	PrintInTree(root);
	cout << "Preorder tree is " << endl;
	PrintPreTree(root);
	cout << "Postorder tree is " << endl;
	PrintPostTree(root);

	getchar();
    return 0;
}

void AddNode(Tree** root, int val)
{
	
	if (*root == NULL)
	{
		*root = (Tree *)malloc(sizeof(Tree));
		(*root)->data = val;
		cout << "Random number is " << val << endl;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return;
	}
	if ((*root)->data > val)
	{
		AddNode(&(*root)->left, val);
	}
	else
	{
		AddNode(&(*root)->right, val);
	}
	return;
}

void PrintInTree(Tree *root)
{
	if (root == NULL)
		return;
	PrintInTree(root->left);
	cout << "Node Value is " << root->data << endl;
	PrintInTree(root->right);
}

void PrintPostTree(Tree *root)
{
	if (root == NULL)
		return;
	PrintPostTree(root->left);
	PrintPostTree(root->right);
	cout << "Node value is " << root->data << endl;

}
void PrintPreTree(Tree *root)
{
	if (root == NULL)
		return;
	cout << "Node value is " << root->data << endl;
	PrintPreTree(root->left);
	PrintPreTree(root->right);

}
void DeleteNode(int val)
{


}
