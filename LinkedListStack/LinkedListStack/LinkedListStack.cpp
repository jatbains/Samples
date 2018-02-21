// LinkedListStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node
{
	int key;
	struct Node *next;
	struct Node *lower;
}Node;



// This Program goes through a linked list which has nodes in the below direction
// Print out the list and the lower list
Node *AllocNode(int x);
Node *InsertNode(Node *node, int x);
void PrintList(Node *head);

int main()
{
	Node *head = nullptr;
	Node *lHead = nullptr;
	int data[] = { 23,12,4,19,17,7,9,27,2,25 };
	int size = sizeof(data) / sizeof(data[0]);
	stack<Node*> lStack;

	for (int i = 0; i < size; i++)
	{
		head = InsertNode(head, data[i]);
	}

	PrintList(head);

	// Populate the lower list
	lHead = head->lower;
	cout << endl;
	// Add nodes to lower list
	for (int i = 0; i < size; i++)
	{
		lHead = InsertNode(lHead, rand()%100);
	}
	Node *temp = lHead;
	while (temp != nullptr)
	{
		lStack.push(temp);
		temp = temp->next;
	}

	PrintList(lHead);
	cout << endl;
	// Pop off Nodes and print Values
	while (!lStack.empty())
	{
		temp = lStack.top();
		cout << temp->key << endl;
		lStack.pop();
	}

	system("pause");
    return 0;
}


void PrintList(Node *head)
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->key << endl;
		temp = temp->next;
	}
}

Node *AllocNode(int x)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->key = x;
	temp->next = temp->lower = nullptr;
	return temp;
}

Node *InsertNode(Node *node, int x)
{
	if (node == nullptr)
	{
		node = AllocNode(x);
		return node;
	}
	Node *temp = node;

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = AllocNode(x);
	return node;
}