// DoublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node {

	int val;
	struct Node *prev;
	struct Node *next;

}Node;

Node * AllocateNode(int val);
void CreateList(Node **head,Node **tail);
void PrintList(Node *head);
void PrintBackList(Node *tail);

int main()
{
	Node *head = NULL;
	Node *tail = NULL;
	// Create Doubly linked list with random numbers
	for (int i = 0; i < 20; i++)
	{
		CreateList(&head, &tail);
	}
	cout << endl;

	PrintList(head);
	// Print from the tail back
	PrintBackList(tail);

	cout << endl;
	system("pause");
    return 0;
}

void PrintBackList(Node *tail)
{
	Node *temp = NULL;
	temp = tail;
	cout << endl << "The list values Backwards are " << endl;
	while (temp->prev != NULL)
	{
		temp = temp->prev;
		cout << temp->val << endl;
	}
}


void PrintList(Node *head)
{
	Node *temp = NULL;
	temp = head;
	cout << endl << "The list values are " << endl;
	while (temp->next != NULL)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}
}

void CreateList(Node **head,Node **tail)
{
	int dat = rand();
	Node *temp = NULL;
	if (*head == NULL)
	{
		*head = AllocateNode(dat);
		*tail = *head;
		return;
	}
	// Append to list and update pointers
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = AllocateNode(dat);
	*tail = temp->next;
	(*tail)->prev = temp;
	return;

}

Node * AllocateNode(int val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = val;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}