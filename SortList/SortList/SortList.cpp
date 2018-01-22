// SortList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>	


typedef struct Node
{
	int val;
	struct Node *next;
}Node;


using namespace std;
Node *AllocNode(int dat);
Node *InsertNode(Node *head, int dat);
void PrintList(Node *head);

void FrontBackSplit(Node *head, Node **a, Node **b);
Node *SortedMerge(Node *frontRef, Node *backRef);
void MergeSort(Node **headRef);
Node *Reverse(Node *head);

int main()
{
	Node *head = NULL;
	int data[] = { 2,12,32,4,19,6,22,15,9,24,13,27 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		head = InsertNode(head, data[i]);
	}

	PrintList(head);

	MergeSort(&head);

	cout << endl;

	PrintList(head);

	head = Reverse(head);

	PrintList(head);

	system("pause");
    return 0;
}

Node *Reverse(Node *head)
{
	Node *prev = NULL;
	Node *curr = head;
	Node *temp = NULL;
	while (curr != NULL)
	{
		temp = curr->next;  // save pointer
		curr->next = prev;     // point backwards
		prev = curr;      
		curr = temp;            // move forwards
	}
	return prev;   // New head
}

void MergeSort(Node **headRef)
{
	Node *head = *headRef;
	Node *a = NULL;
	Node *b = NULL;

	// Base case 
	if (head == NULL || head->next == NULL)   
		return;

	// Split the lists into a abd b sublists  
	FrontBackSplit(head, &a, &b);

	// Merge Sort the sub lists recursively
	MergeSort(&a);
	MergeSort(&b);

	// Merge the haves together
	*headRef = SortedMerge(a, b);
}

Node *SortedMerge(Node *frontRef, Node *backRef)
{
	// Nerge the sub lists by sorted them
	Node *result = NULL;

	// Check for base case
	if (frontRef == NULL)
		return backRef;
	if (backRef == NULL)
		return frontRef;

	// Check data types
	if (frontRef->val <= backRef->val)    // Smallest to front
	{
		result = frontRef;
		result->next = SortedMerge(frontRef->next, backRef);
	}
	else
	{
		result = backRef;
		result->next = SortedMerge(frontRef, backRef->next);

	}
	return result;
}

void FrontBackSplit(Node *head, Node **frontRef, Node **backRef)
{
	Node *fast, *slow;
	// Split this into two lists with fast and slow pointer
	// Check for i node
	if (head == NULL || head->next == NULL)
	{
		*frontRef = head;
		*backRef = NULL;
		return;
	}
	slow = head;
	fast = slow->next;
	// Go through list and when fast reaches end slow will be in middle
	while (fast != NULL)
	{
		fast = fast->next;      // Twice in while
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontRef = head;          // Split it at slow
	*backRef = slow->next;
	slow->next = NULL;

	return;
}

void PrintList(Node *head)
{
	Node *temp = head;
	while (temp->next != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << temp->val << " " << endl;
}


// InsertAtEnd Not sorted
Node * InsertNode(Node *head, int dat)
{
	if (head == NULL)
	{
		head = AllocNode(dat);
		return head;
	}
	// Insert at end of the list
	Node *temp = head;   // start at head
	while (temp->next != NULL)
	{
		temp = temp->next;    // move forward
	}
	temp->next = AllocNode(dat);
	return head;  // Remains unchanged
}


Node *AllocNode(int dat)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = dat;
	temp->next = NULL;

	return temp;
}