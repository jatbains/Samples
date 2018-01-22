// ListPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int dat;
	struct Node *next;
}Node;

Node * AddNode(Node *head, int val);
Node *AllocNode(int val);
void PrintList(Node *head);
Node * ReverseList(Node *head);
bool AreTheListsPallindrome(Node *h1, Node *r1);

int main()
{
	Node *head = NULL;
	Node *rhead = NULL;
	int data[] = { 4,3,2,1,2,3,4 };
	// Create a list
	int size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < size; i++) 
	{
		head = AddNode(head, data[i]);
	}

	PrintList(head);

	rhead = ReverseList(head);

	PrintList(rhead);

	// Compare the two heads.
	cout << "The lists " << (AreTheListsPallindrome(head, rhead) ? "are Palindrome" : "are not Palindrome") << endl;

	system("pause");
    return 0;
}

bool AreTheListsPallindrome(Node *h1, Node *r1)
{
	Node *t1 = h1, *t2 = r1;
	// Go through lists to see if the same
	while (t1->next != NULL && t2->next != NULL)
	{
		if (t1->dat != t2->dat)
		{
			return false;
		}
		t1 = t1->next;
		t2 = t2->next;
	}
	return true;
}

Node * ReverseList(Node *head)
{
	Node *curr = head, *prev = NULL;
	Node *temp = NULL;

	while (curr != NULL)
	{
		temp = curr->next;
		curr->next = prev; // Point it backwards
		// Move forwards
		prev = curr;
		curr = temp;  // Move forward
	}
	return prev;  // New head
}

void PrintList(Node *head)
{
	Node *temp = head;
	cout << " The list is " << endl;
	while (temp->next != NULL)
	{
		cout << " Value  " << temp->dat << endl;
		temp = temp->next;
	
	}
	// Print last value
	cout << " Value  " << temp->dat << endl;
}

Node * AddNode(Node *head, int val)
{
	Node *temp = NULL;
	temp = head;

	if (head == NULL)
	{
		head = AllocNode(val);
		return head;
	}
	// Add to end
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = AllocNode(val);
	return head;

}
Node *AllocNode(int val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->dat = val;
	temp->next = NULL;
	return temp;
}