// LinkLoop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;
}Node;


Node * AddNode(Node *head, int val);
void CorruptList(Node *head);
bool DetectCycle(Node *head);
void PrintList(Node *head);

int main()
{
	Node *head = NULL;

	// Create a list
	for (int i = 0; i < 20; i++)
	{
		head = AddNode(head, rand());
	}
	PrintList(head);
	// Corrupt the List Put in a cycle
	CorruptList(head);

	// Detect A Cycle
	cout << (DetectCycle(head) ? "Cycle Detected" : "No cycle" ) << endl;

	system("pause");
    return 0;
}

void PrintList(Node *head)
{
	while (head->next != NULL)
	{

		cout << "Node is " << head->val << endl;
		head = head->next;
	}
}

bool DetectCycle(Node *head)
{
	Node *p = NULL, *q = NULL;
	p = q = head;
	// We detect a cycle if we move two pointers at different rates 
	// If they equal each other that is where the cycle is
	while ((p->next != NULL) && (q->next->next != NULL))
	{
		if (p == q)
		{
			// cycle is found
			return true;
		}
		p = p->next;
		q = q->next->next;
	}

}

void CorruptList(Node *head)
{
	Node *p = NULL;
	Node *t = NULL;
	
	p = t =  head;
	int count = 0;
	// Link last to  5th Node
	while (t->next != NULL)
	{
		if (count == 5)
		{
			p = t;
		}
		t = t->next;
		count++;
	}
	// Create loop
	t->next = p;

}

Node * AddNode(Node *head, int val)
{
	Node *p = NULL;
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = val;
	temp->next = NULL;

	if (head == NULL)
	{
		// Set head to temp
		
		return temp;
	}
	// Move through list add at end
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = temp;
	return head;
}

