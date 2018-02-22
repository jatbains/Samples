// KDTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int k = 2;

// A structure to represent node of kd tree
typedef struct Node
{
	int point[k];           // To store k dimensional point
	Node *left, *right;
}Node;

Node *AllocNode(int arr[]);
Node *InsertPoint(Node *root, int point[], int depth);
Node *InsertRec(Node *root, int point[]);
bool FindNode(Node *root, int point[]);
bool CompareNodes(Node *p1, Node *p2);
bool ComparePoints(int p1[], int p2[]);
bool SearchTree(Node *root, int point[], int depth);
bool FindNode(Node *root, int point[]);

int main()
{
	struct Node *root = nullptr;    // Root of the tree
	int points[][k] = { { 3, 6 },{ 17, 15 },{ 13, 15 },{ 6, 12 },
						{ 9, 1 },{ 2, 7 },{ 10, 19 } };

	int size = sizeof(points) / sizeof(points[0]);

	for (int i = 0; i < size; i++)
	{
		root = InsertRec(root, points[i]);
	}

	int point1[] = { 10, 19 };
	cout << "Searching point " << point1[0] << " " << point1[1] << ": " << (FindNode(root, point1)) ? cout << " Found\n" : cout << "Not Found\n";

	int point2[] = { 12, 19 };
	cout << "Searching point " << point2[0] << " " << point2[1] << ": " << (FindNode(root, point2)) ? cout << " Found\n" : cout << "Not Found\n";

	system("pause");
    return 0;
}

bool CompareNodes(Node *p1,Node *p2)
{
	for (int i = 0; i < k; i++)
	{
		if (p1->point[i] != p2->point[i])
			return false;
	}
	return true;
}

bool ComparePoints(int p1[], int p2[])
{
	for (int i = 0; i < k; i++)
	{
		if (p1[i] != p2[i])
			return false;
	}
	return true;
}

// Recursively search the tree for a point
bool SearchTree(Node *root, int point[],int depth)
{
	if (root == nullptr)
		return false;

	if (ComparePoints(root->point, point))
	{
		return true;
	}
	// check the depth
	unsigned cd = depth % k;

	// Search left or right depending on value
	if (point[cd] < root->point[cd])
	{
		return SearchTree(root->left, point, depth + 1);
	}
	else
	{
		return SearchTree(root->right, point, depth + 1);
	}

}

bool FindNode(Node *root, int point[])
{
	return (SearchTree(root, point, 0));
}

Node *AllocNode(int arr[])
{
	Node *temp = (Node *)malloc(sizeof(Node));
	for (int i = 0; i < k; i++)
	{
		temp->point[i] = arr[i];
	}

	temp->left = temp->right = nullptr;
	return temp;
}
// Insertion is based on the plane
Node *InsertPoint(Node *root, int point[],int depth)
{
	if (root == nullptr)
	{
		// root node
		root = AllocNode(point);
		return root;
	}
	// Insert Depending on the depth
	unsigned cd = depth % k;    // The current depth
	if (point[cd] < root->point[cd])
	{
		root->left = InsertPoint(root->left, point, depth + 1);
	}
	else
	{
		root->right = InsertPoint(root->right, point, depth + 1);
	}
	return root;
}

Node *InsertRec(Node *root, int point[])
{
	root = InsertPoint(root, point, 0);
	return root;
}