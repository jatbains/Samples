// BiNode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class BiNode
{
public :
	BiNode(BiNode *,BiNode *,int x);
		BiNode *node1, *node2;
		int data;
};

BiNode *InsertNode(BiNode *node, int x);
BiNode *AllocNode(int x);
void PrintInOrder(BiNode *node);
void PrintPreOrder(BiNode *node);
void BinaryTreeToLinkedList(BiNode * root, BiNode ** head);
void PrintList(BiNode *head);

vector<BiNode*> PutNodesIntoList(BiNode *node, vector<BiNode*> list);
BiNode * LinkList(vector<BiNode*> list);

BiNode::BiNode(BiNode *val1,BiNode *val2,int x)
	:node1(val1)
	,node2(val2)
	,data(x)
{}

int main()
{
	BiNode *root = NULL;
	int data[] = { 9,2,15,7,22,13,4,1,11,19 };
	int size = sizeof(data) / sizeof(data[0]);
	vector<BiNode*> list;
	BiNode *head = NULL;

	for (int i = 0; i < size; i++)
	{
		root = InsertNode(root, data[i]);
	}

	PrintInOrder(root);
	// Put items into a queue order
	cout << endl;
	PrintPreOrder(root);

	//list = PutNodesIntoList(root, list);

	// process the list
	//head = LinkList(list);
	BinaryTreeToLinkedList(root, &head);

	PrintList(head);

	system("pause");
    return 0;
}

void PrintList(BiNode *head)
{
	BiNode *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->node1;
	}
}

void BinaryTreeToLinkedList(BiNode * root, BiNode ** head)
{
	if (root == NULL)   // Base case the tree is processed
		return;

	static BiNode *prev=NULL;   // static so it is available in all recursions

	// Recursively do left subtree
	BinaryTreeToLinkedList(root->node1, head);

	// Convert this node
	if (prev == NULL)
	{
		*head = root;
	}
	else
	{
		root->node1 = prev;
		prev->node2 = root;

	}
	prev = root;


	// Recursively do the right subtree
	BinaryTreeToLinkedList(root->node2, head);
}

// Like into a list
BiNode * LinkList(vector<BiNode*> list)
{
	BiNode * head = NULL;
	vector<BiNode*>::iterator it;

	BiNode *prev = NULL;
	for (it = list.begin(); it != list.end(); it++)
	{
		head->node1 = *it;
		(*it)->node2 = prev;
		prev = *it;
	}

	return head;

}

vector<BiNode*> PutNodesIntoList(BiNode *node, vector<BiNode*> list)
{
	// Base case
	if (node != NULL) {

		list.push_back(node);
		PutNodesIntoList(node->node1, list);
		PutNodesIntoList(node->node2, list);
	}
	return list;
}


void PrintPreOrder(BiNode *node)
{
	if (node == NULL)
		return;
	cout << node->data << endl;
	PrintPreOrder(node->node1);
	PrintPreOrder(node->node2);
}

void PrintInOrder(BiNode *node)
{
	if (node == NULL)
		return;
	PrintInOrder(node->node1);
	cout << node->data << endl;
	PrintInOrder(node->node2);
}

BiNode *InsertNode(BiNode *node, int x)
{
	if (node == NULL)
	{
		node = AllocNode(x);
	
		return node;
	}

	if (x < node->data)   // left of node
	{
		node->node1 = InsertNode(node->node1, x);
	}
	else
	{
		node->node2 = InsertNode(node->node2, x);
	}
	return node;
}

BiNode *AllocNode(int x)
{
	
	BiNode *node = new BiNode(NULL, NULL, x);
	return node;
}
