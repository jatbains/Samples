// ReverseDouble.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
}Node;


Node *AllocNode(int x);
Node *InsertNode(Node *head, int x);
void PrintList(Node * head);
Node * ReverseList(Node *head);

int main()
{
	Node *head = NULL;
	Node *tail = NULL;
	int data[] = { 12,5,9,21,19,15,17,31,28,7,15 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		head = InsertNode(head, data[i]);
	}

	PrintList(head);
	cout << endl << endl;
	tail = ReverseList(head);

	PrintList(tail);

	system("pause");
    return 0;
}

Node * ReverseList(Node *head)
{
	// Reverse the next and prev pointers
	Node *curr = head;
	Node *prev = NULL;
	while (curr != NULL)
	{
		// swap pointers
		Node *temp = curr->next;   // save for traversal
		curr->next = prev;        // point it back
		curr->prev = curr->next;
		prev = curr;
		curr = temp;
	}
	return prev;
}

void PrintList(Node * head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}

Node *InsertNode(Node *head,int x)
{
	if (head == NULL)
	{
		head = AllocNode(x);
		return head;
	}

	// Traverse to last node and insert
	Node *temp = head;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	// temp->next is NULL add the Node
	temp->next = AllocNode(x);
	temp->next->prev = temp;

	return head;     // head is unchanged
}

Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->val = x;
	tNode->next = tNode->prev = NULL;

	return tNode;
}
