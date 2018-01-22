// FixLinkListLoop.cpp : Defines the entry point for the console application.
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

Node *AllocNode(int x);
Node *InsertInList(Node *head, int x);
void Printlist(Node *head);
void CorruptList(Node *head);
Node *DetectLoop(Node *head);
void RemoveLoop(Node *head, Node *loop);

const static int MAX_NODES = 20;

int main()
{
	Node *head = NULL;
	Node *loop = NULL;

	for (int i = 0; i <= MAX_NODES; i++)
	{
		head = InsertInList(head, rand());
	}

	Printlist(head);

	CorruptList(head);

	loop = DetectLoop(head);

	RemoveLoop(head, loop);

	Printlist(head);

	system("pause");
    return 0;
}

void RemoveLoop(Node *head, Node *loop)
{
	Node *p1 = head;
	Node *l1 = loop;
	// Go through the list and increment p1 one at a time until
	// Reachable by l1
	while (1)
	{
		l1 = loop;  // Reset it to beginning

		while (l1->next != loop && l1->next != p1)
		{
			l1 = l1->next;
		}

		// Check if found
		if (l1->next == p1)
		{
			break;
		}
		// Not found increment p1
		p1 = p1->next;
		
	}
	// Here set l1->next to NULL
	l1->next = NULL;

}

Node  *DetectLoop(Node *head)
{
	Node *fast = NULL;
	Node *slow = head;
	
	if (head == NULL)
		return false;
	if (slow->next != NULL)
		fast = slow->next;

	while (slow->next != NULL && fast->next->next != NULL)
	{
		if (slow == fast)   // Loop Detected
		{
			cout << "Value " << dec << slow->val  << "  " << hex << slow->next << endl;
			return slow;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return NULL;
}

void CorruptList(Node *head)
{
	// Set last node to point into 5th node
	Node *p = head;
	Node *t = head;
	int x = 0;

	while (t->next != NULL)
	{
		if (x == 5)
		{
			p = t;
		}
		x++;
		t = t->next;
	}
	// t->next is at the end point it back to 5th Node 
	t->next = p;  // The list has been corrupted

	// Proof
	t = head;
	x = 0;
	while (1 && t!=NULL)
	{
		cout << "Value " << dec << t->val << "  " << hex << t << endl;
		if (x > 40)
			break;
		x++;
		t = t->next;
	}

}


void Printlist(Node *head)
{
	Node *tNode = head;
	while (tNode != NULL)
	{
		cout << dec << "Value " << tNode->val << endl;
		tNode = tNode->next;
	}
}

Node *InsertInList(Node *head, int x)
{
	if (head == NULL)
	{
		head = AllocNode(x);
		return head;
	}

	Node *tNode = head;
	while (tNode->next != NULL)
	{
		tNode = tNode->next;
	}
	tNode->next = AllocNode(x);
	return head;
}

Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->val = x;
	tNode->next = NULL;

	return tNode;
}