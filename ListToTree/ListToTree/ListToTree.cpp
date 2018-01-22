// ListToTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class BiNode
{
public:
	BiNode *node1, *node2;
	int data;
};

BiNode * AllocNode(int val);
BiNode * InsertInOrder(BiNode *node, int val);
void PrintNode(BiNode *node);
void PrintNodeRev(BiNode *node);

int main()
{
	BiNode *head = NULL;
	BiNode *tail = NULL;

	for (int i = 0; i < 10; i++)
	{
		head = InsertInOrder(head,rand());
	}

	cout << endl;

	PrintNode(head);
	
	cout << endl;

	tail = head;
	while (tail->node1 != NULL)
	{
		tail = tail->node1;
	}
	PrintNodeRev(tail);

	system("pause");
    return 0;
}

void PrintNodeRev(BiNode *node)
{
	BiNode *temp = node;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->node2;
	}
}

void PrintNode(BiNode *node)
{
	BiNode *temp = node;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->node1;
	}

}

BiNode * InsertInOrder(BiNode *node,int val)
{
	if (node == NULL)
	{
		node = AllocNode(val);
		return node;
	}
	// Check Value of val for head node
	if (val < node->data) 
	{
		BiNode *temp = AllocNode(val);
		temp->node1 = node;
		node->node2 = temp;
		return temp;
	}
	// Go through the list inserting nodes
	BiNode *temp = node;
	while (temp->node1 != NULL)
	{
		if (val < temp->data)
		{
			BiNode *node1= AllocNode(val);
			temp->node1->node2 = node1;
			node1->node1 = temp->node1;
			temp->node1 = node1;
			node1->node2 = temp;
			return node;
		}
		temp = temp->node1;
	}
	// Insert at end
	temp->node1 = AllocNode(val);
	temp->node1->node2 = temp;
	return node;

}

BiNode * AllocNode(int val)
{
	BiNode *temp = (BiNode*)malloc(sizeof(BiNode));
	temp->data = val;
	temp->node1 = NULL;
	temp->node2 = NULL;

	return temp;
}