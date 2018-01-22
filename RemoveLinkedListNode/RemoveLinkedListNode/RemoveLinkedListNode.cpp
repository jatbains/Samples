// RemoveLinkedListNode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>		

using namespace std;


class Node
{
public:
	int val;
	class Node *next;
};

Node *AllocNode(int x);
Node *InsertNode(Node *head, int x);
void PrintList(Node *head);
Node *NinthNode(Node *head);
void RemoveNode(Node *Ninth);

int main()
{
	Node *head = NULL;
	for (int i=0; i < 12; i++)
	{
		head = InsertNode(head, rand());
	}

	PrintList(head);

	// Remove 9th element
	Node *temp = NinthNode(head);


	// Adjust List
	RemoveNode(temp);
	cout << endl << endl;
	PrintList(head);

	system("pause");
    return 0;
}

void RemoveNode(Node *Ninth)
{
	Node *t = Ninth;
	Node *prev = NULL;
	while (t->next != NULL)
	{
		t->val = t->next->val;
		prev = t;
		t = t->next;
	}
	// At end remove last one
	prev->next = NULL;
	free(t);
	return;
}

Node *NinthNode(Node *head)
{
	Node *temp = head;
	int i = 0;
	while (i < 9)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

void PrintList(Node *head)
{
	Node *tNode = head;
	while (tNode->next != NULL)
	{
		cout << tNode->val << endl;
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
	Node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = AllocNode(x);
	temp->val = x;
	return head;

}
Node *AllocNode(int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));

	tNode->val = x;
	tNode->next = NULL;

	return tNode;
}