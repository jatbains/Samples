// LinkedRecur.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

Node *AllocNode(int dat);
void InsertNode(Node **node, int val);
void PrintNodes(Node *head);
void Reverse(Node **head);
void ReverseUtil(Node *curr, Node *prev, Node **head);
void ReverseRecur(Node **head);


int main()
{
	Node *head = NULL;

	for (int i = 0; i < 20; i++)
	{
		InsertNode(&head, rand());
	}

	PrintNodes(head);

	Reverse(&head);
	cout << endl;

	PrintNodes(head);

	ReverseRecur(&head);

	cout << endl;

	PrintNodes(head);

	system("pause");
    return 0;
}

void ReverseUtil(Node *curr, Node *prev, Node **head)
{
	// Check for the base case
	if (curr->next == NULL)
	{
		*head = curr;
		curr->next = prev;
		return;
	}
	
	Node *temp = curr->next;
	curr->next = prev;

	ReverseUtil(temp, curr, head);
}

void ReverseRecur(Node **head)
{
	if (*head == NULL)
		return;
	ReverseUtil(*head, NULL, head);
}

void Reverse(Node **head)
{
	Node *curr = *head;
	Node *prev = NULL;
	
	while (curr != NULL)
	{
		Node *temp = curr->next;   // save pointer
		curr->next = prev;        // ponint backwards
		prev = curr;                // move prev forward
		curr = temp;                // Move curr forward
	}
	// New head id prev
	*head = prev;
}

void PrintNodes(Node *head)
{
	Node *temp = head;

	while (temp->next != NULL)
	{
		cout << temp->val << " " << endl;
		temp = temp->next;
	}
	cout << temp->val << " " << endl;
}

Node *AllocNode(int dat)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->val = dat;
	temp->next = NULL;

	return temp;
}

void InsertNode(Node **node,int val)
{
	if (*node == NULL)
	{
		Node *temp = AllocNode(val);
		*node = temp;
		return;
	}
	// Add New nodes at end of list
	Node *temp = *node;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = AllocNode(val);

	return;
}