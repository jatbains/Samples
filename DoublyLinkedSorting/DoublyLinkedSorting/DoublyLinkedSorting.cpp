// DoublyLinkedSorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *prev;
	struct Node *next;
}Node;

Node *InsertNode(Node *head, int x);
Node *AllocNode(int x);
void PrintList(Node *head);
Node *PrintBackwards(Node *head, Node *tail);
void Swap(int *a, int *b);
void QuickSortRecur(Node *head, Node *tail);
Node *Partition(Node *l, Node *h);

int main()
{
	Node *head = NULL;
	Node *tail = NULL;

	for (int i = 0; i <= 20; i++)
	{
		head = InsertNode(head, rand());
	}

	PrintList(head);
	cout << endl;

	tail = PrintBackwards(head, tail);

	QuickSortRecur(head, tail);

	cout << endl;
	PrintList(head);

	system("pause");
    return 0;
}

Node *Partition(Node *l, Node *h)
{
	// Partition the list use the last element 
	// as the pivot and sort
	int x = h->val;

	// Get previous Node
	Node *i = l->prev;

	// Move pointers
	for (Node *j = l; j != h; j = j->next)
	{
		if (j->val <= x)   // Swap the values
		{
			i = (i == NULL) ? l : i->next;   // increment i

			Swap(&(i->val), &(j->val));

		}
	}

	i = (i == NULL) ? l : i->next;   // increment i
	// Swap the pivot back
	Swap(&(i->val), &(h->val));

	return i;
}


void QuickSortRecur(Node *l, Node *h)
{
	// Check for the base condition
	// where l is low and h is high
	if (h != NULL && l != h && l != h->next)
	{
		// Partition the list
		Node *p = Partition(l, h);
		QuickSortRecur(l, p->prev);
		QuickSortRecur(p->next, h);

	}

}

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

Node *PrintBackwards(Node *head, Node *tail)
{
	Node *tNode = head;

	tNode = head;
	while (tNode->next!=NULL)
	{
		tNode = tNode->next;
	}
	tail = tNode;
	while (tNode != NULL)
	{
		cout << tNode->val << endl;
		tNode = tNode->prev;
	}
	return tail;
}


void PrintList(Node *head)
{
	Node *tNode = head;
	while (tNode != NULL)
	{
		cout << " " << tNode->val << " " << endl;
		tNode = tNode->next;
	}

}

Node *InsertNode(Node *head, int x)
{
	if (head == NULL)
	{
		head = AllocNode(x);
		return head;
	}
	// Loop through the list and add a node at end
	Node *tNode = head;
	while (tNode->next != NULL)
	{
		tNode = tNode->next;
	}
	tNode->next = AllocNode(x);  // Add at the end
	tNode->next->prev = tNode;   // Point the prev back to last Node
	return head;
}

Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->val = x;
	tNode->next = NULL;
	tNode->prev = NULL;

	return tNode;
}