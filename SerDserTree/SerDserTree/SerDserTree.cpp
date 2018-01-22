// SerDserTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
}Node;


Node *AllocNode(int dat);
Node * InsertNode(Node *root, int dat);
void PrintInOrder(Node *root);

void PreOrder(Node *root, fstream &stream);
void PreOrder(Node *root, ofstream &stream);
Node * DeSerializeTree(Node *root, fstream &inStream);

int main()
{
	Node *root = NULL;
	Node *dRoot = NULL;
	int data[] = { 22,3,12,9,17,6,15,14,5,11,24,1 };
	// Insert Nodes into tree
	int size = sizeof(data) / sizeof(data[0]);
	ofstream outStream;
	fstream myStream;
	
	//myStream.open("Tree.txt");
	outStream.open("Tree.txt");

	string myFile;

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	PrintInOrder(root);
	cout << endl;
	PreOrder(root, outStream);
	outStream.close();

	myStream.close();

	myStream.open("Tree.txt");

	cout << endl << endl;

	if (myStream.is_open())
	{
		while (!myStream.eof())
		{
			getline(myStream, myFile);
			cout << myFile;
		}
	}
	cout << endl << endl;

	myStream.clear();
	myStream.seekg(0, ios::beg);
	// Deserialize the tree
	// Drive the logic from outside of the tree

	dRoot = DeSerializeTree(dRoot, myStream);

	PrintInOrder(dRoot);

	myStream.close();

	system("pause");
    return 0;
}



Node * DeSerializeTree(Node *root, fstream &inStream)
{
	char c;
	bool nullL = false, nullR = false;
	int x = 0;
	int power = 1;
	if (inStream.eof())   // File is empty
		return NULL;
	if (root == NULL)
	{
		while (!inStream.eof()) 
		{ 
			c = inStream.get();
			if (c == ',')
				break;
			if (c >= '0' && c <= '9')
			{
				x = x* power + (c - '0');
				power *= 10;
			}
		}

		root = InsertNode(root,x);
		x = 0;
		power = 1;
	}
	
	while (!inStream.eof())
	{
		c = inStream.get();
		if (c == ',')
		{
			char p = inStream.peek();
			if (p >= '0' && p <= '9')    // Process this node
				break;
			continue;                    // Continue until node full read in
		}
		if (c >= '0' && c <= '9')
		{
			x = x* power + (c - '0');
			power *= 10;
		}
		if (c == 'L')
			nullL = true;
		if (c == 'R')
			nullR = true;
	}

	if (!nullL)
	{
		root->right = InsertNode(root->right,x);
	}
	if (!nullR)
	{
		root->left = InsertNode(root->right, x);
	}

	return root;
}

void PreOrder(Node *root, ofstream &stream)
{

	if (root == NULL)
		return;
	stream << root->val << ",";
	cout << root->val << " ";
	if (root->left == NULL)
	{
		stream << "L" << ",";
		cout << "L";
	}
	if (root->right == NULL)
	{
		stream << "R" << ",";
		cout << "R";
	}
	cout << endl;
	PreOrder(root->left, stream);
	PreOrder(root->right, stream);
}

void PreOrder(Node *root, fstream &stream)
{	
	if (root == NULL)
		return;
	stream << root->val << ",";
	cout << root->val << " ";
	if (root->left == NULL)
	{
		stream << "L" << ",";
		cout << "L";
	}
	if (root->right == NULL)
	{
		stream << "R" << ",";
		cout << "R";
	}
	cout << endl;
	PreOrder(root->left,stream);
	PreOrder(root->right,stream);
}

void PrintInOrder(Node *root)
{
	if (root == NULL)    // Base case
		return;

	PrintInOrder(root->left);
	cout <<  " " << root->val << " " << endl;
	PrintInOrder(root->right);

	return;
}

Node * InsertNode(Node *root, int dat) 
{ 
	if (root == NULL)    // Empty
	{
		root = AllocNode(dat);
		return root;
	}
	// Insert Into the tree
	if (root->val > dat)
	{
		root->left = InsertNode(root->left, dat);
	}
	else
	{
		root->right = InsertNode(root->right, dat);
	}
	return root;
}

Node *AllocNode(int dat)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = dat;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
