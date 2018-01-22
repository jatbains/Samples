// DupLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

typedef struct Node
{
	int data;  // data field
	struct Node *next;
}Node;

void CreateList(Node **head, int data);
void PrintList(Node *head);
void RemoveDuplicates(Node *head);
int CountNodes(Node *head);
Node * RemoveKthNode(Node* head, int num);
void RemoveSpecificNode(Node *head);

int main()
{
	Node *head = NULL;
	Node *middle = NULL;
	int val[11] = { 2,21,25,4,3,9,7,4,13,17,15 };
	int k = 0,count=0;
	cout << "Enter the kth to last node" << endl;
	cin >> k;
	for (int i = 0; i <= 10; i++)
	{
		CreateList(&head, val[i]);
	}

	cout << "Total list is " << endl << endl;

	PrintList(head);
	count = CountNodes(head);
	// The node to remove is count -k

	cout << "The count of node is " << count << endl;

	head = RemoveKthNode(head,count - k);

	cout << "After removing the kth node " << endl << endl;
	PrintList(head);

	RemoveDuplicates(head);
	cout << endl <<"After Removing Duplicates" << endl << endl;
	PrintList(head);

	
	RemoveSpecificNode(head);
	cout << "After removing a spefific node in middle" << endl;
	PrintList(head);

	// Remove all nodes after a specific node
	// Solution copy data over from remaining nodes to the others
	

	getchar();
	getchar();
    return 0;
}

void RemoveSpecificNode(Node *head)
{
	int count = 0, mid = 0, i =0;
	Node *temp = head,*del = NULL;
	count = CountNodes(head);
	mid = count / 2;  // midway point

	while (i != mid)
	{
		temp = temp->next;
		i++;
	}
	// Delete node temp Copy all data from remaining nodes and delete last one
	cout << "Deleting node with value " << temp->data << endl;
	// It is a middle node

	while ((temp->next)->next != NULL)
	{
		temp->data = (temp->next)->data;
		temp = temp->next;
	}
	// Free the last Node
	temp->data = (temp->next)->data;
	del = temp->next;
	temp->next = NULL;
	free(del);

	PrintList(head);
}

int CountNodes(Node *head)
{
	int num = 0;
	Node *temp = NULL;
	temp = head;
	while (temp != NULL)
	{
		num++;
		temp = temp->next;
	}
	return num;
}

Node * RemoveKthNode(Node* head, int num)
{
	Node *curr = NULL;  // Wish to remove node num 
	Node *prev = NULL;    // Walk through the list and count until we get to num
	Node *temp;           // Use two pointers prev and curr 
	// Special case if num = 0 then remove first element
	curr = head;
	if (num == 0)
	{
		temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	else
	{
		int count = 1;
		// Go through the list
		prev = head;
		curr = head->next;
		while (curr != NULL)
		{
			if (count == num)
			{
				temp = curr;
				prev->next = curr->next;
				prev = prev->next;
				curr = (curr->next)->next;
				free(temp);
			}
			prev = prev->next;
			curr = curr->next;
			count++;
		}

		return head;
	}

}

void RemoveDuplicates(Node *head)
{
	int DupMap[50] = { 0 };
	Node *curr = head->next;
	Node *prev = head;
	Node *dupe = NULL;

	while (curr != NULL)
	{
		DupMap[curr->data]++;
		if (DupMap[curr->data] > 1)
		{
			// Duplicate found  remove this one
			dupe = curr;
			prev->next = curr->next;
			prev = prev->next;
			curr = (curr->next)->next;
			free(dupe);
		}
		prev = prev->next;
		curr = curr->next;
	}
	// Map table populated

}

void PrintList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << "The node is " << temp->data << endl;
		temp = temp->next;
	}
}

void CreateList(Node **head, int val)
{
	Node * temp = NULL;
	Node * p = NULL;

	temp = (Node *)malloc(sizeof(Node));
	temp->data = val;
	temp->next = NULL;

	if (*head == NULL)
	{
		(*head) = temp;
		(*head)->next = NULL;
	}
	else
	{
		p = *head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}

	return;
}
