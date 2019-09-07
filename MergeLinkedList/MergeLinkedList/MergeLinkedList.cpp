// MergeLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

Node *AllocNode(int x)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = x;
	temp->next = NULL;

	return temp;
}

Node *InsertIntoList(Node *head, int x)
{
	Node *temp = head;
	if (head == NULL)
	{
		temp = AllocNode(x);
		return temp;
	}

	// Add to the end
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = AllocNode(x);
	return head;
}

void PrintList(Node *head)
{
	int x = 1;
	while (head != NULL)
	{
		cout << "Node is " << x << " Val is " << head->val << endl;
		head = head->next;
		x++;
	}
}

Node *ReverseList(Node *head)
{
	Node *temp = NULL;
	Node *prev = NULL;

	if (head == NULL)
	{
		return head;
	}
	while (head != NULL)
	{
		temp = head->next; // Save pointer
		head->next = prev;
		prev = head;       // Move prev forward
		head = temp;       // Move temp forward
	}

	return prev;          // New head
}

int main()
{
	Node *head = NULL;
	int num = 20;

	for (int i = 0; i < num; i++)
	{
		head = InsertIntoList(head, rand() % 100);
	}
	cout << "List is " << endl;
	PrintList(head);

	// Reverse
	head = ReverseList(head);
	cout << "Reversed List " << endl << endl;
	PrintList(head);
	getchar();
	return 0;
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
