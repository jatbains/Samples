// ReverseKNodesList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int key;
	struct Node *next;
}Node;
Node *AllocNode(int x);
Node *InsertNode(Node *head, int x);
void PrintList(Node *head);

int main()
{
	Node *head = nullptr;
	int data[] = { 10,2,5,14,19,12,7,21 };
	int size = sizeof(data)/sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		head = InsertNode(head, data[i]);
	}

	PrintList(head);

	system("pause");
    return 0;
}

void PrintList(Node *head)
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << " " << temp->key << " " << endl;
		temp = temp->next;
	}
}

Node *AllocNode(int x)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->key = x;
	temp->next = nullptr;
	return temp;
}

Node *InsertNode(Node *head, int x)
{
	bool isLast = true;
	if (head == nullptr)
	{
		head = AllocNode(x);
		return head;
	}

	Node *temp = head;
	Node *prev = nullptr;
	Node *tptr = nullptr;


	if (temp->next == nullptr)
	{
		tptr = AllocNode(x);
		if (x < temp->key)
		{
			tptr->next = head;
			return tptr;
		}
		else
		{
			head->next = tptr;
			return head;
		}
	}

	while (temp != nullptr)
	{
		if ( x < temp->key )
		{
			tptr = AllocNode(x);
			tptr->next = temp;
			prev->next = tptr;
			isLast = false;
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if (isLast)
	{
		tptr = AllocNode(x);
		prev->next = tptr;
	}
	return head;
}