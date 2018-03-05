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
	int size = 10;

	for (int i = 0; i < 12; i++)
	{
		head = InsertNode(head, rand() % 20);
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
	if (head == nullptr)
	{
		head = AllocNode(x);
		return head;
	}

	Node *temp = head;
	Node *prev = nullptr;
	Node *tptr = nullptr;

	if (x < temp->key)
	{
		tptr = AllocNode(x);
		tptr->next = head;
		return tptr;
	}

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
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}