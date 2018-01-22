// AddLinkedListNumbers.cpp : Defines the entry point for the console application.
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

void PrintList(Node *head);
Node * InsertNode(Node *head, int x);
Node *AllocNode(int x);
Node *ReverseList(Node *head);
int AddTwoLists(Node *num1, Node *num2);

int main()
{
	Node *num1 = NULL;
	Node *num2 = NULL;
	Node *revNum1 = NULL;
	Node *revNum2 = NULL;

	int data1[] = { 9,5,5 };
	int data2[] = { 8,5 };

	int size1 = sizeof(data1) / sizeof(data1[0]);
	int size2 = sizeof(data2) / sizeof(data2[0]);

	for (int i = 0; i < size1; i++) 
	{
		num1 = InsertNode(num1, data1[i]);
	}
	for (int i = 0; i < size2; i++)
	{
		num2 = InsertNode(num2, data2[i]);
	}

	PrintList(num1);
	cout << endl;
	PrintList(num2);

	revNum1 = ReverseList(num1);
	revNum2 = ReverseList(num2);

	cout << endl;

	PrintList(revNum1);
	cout << endl;
	PrintList(revNum2);

	cout << AddTwoLists(revNum1, revNum2);
	cout << endl;
	system("pause");
    return 0;
}

int AddTwoLists(Node *num1, Node *num2)
{
	int power = 1;
	int sum = 0;
	int carry = 0;
	Node *t1 = NULL, *t2 = NULL;

	t1 = num1;
	t2 = num2;

	while (t1 != NULL && t2 != NULL)
	{
		sum += power * (t1->val + t2->val + carry);
		carry = 0;
		if (sum >= 10*power)
		{
			sum %= 10*power;
			carry = 1;
		}
		power *= 10;
		t1 = t1->next;
		t2 = t2->next;
	}
	// Now we process any remaining nodes
	while (t1 != NULL)
	{
		sum +=power * (t1->val + carry);
		carry = 0;
		if (sum > 10*power)
		{
			sum %= 10*power;
			carry = 1;
		}
		power *= 10;
		t1 = t1->next;
	}

	while (t2 != NULL)
	{
		sum += power * (t2->val + carry);
		carry = 0;
		if (sum > 10*power)
		{
			sum %= 10*power;
			carry = 1;
		}
		power *= 10;
		t2 = t2->next;
	}
	// Add in the carry if present
	sum += power * carry;
	// Done processing
	return sum;
}

Node *ReverseList(Node *head)
{
	Node *prev = NULL;
	Node *curr = head;
	Node *temp = NULL;

	while (curr != NULL)
	{
		temp = curr->next;  // save pointer
		curr->next = prev;  // point back
		prev = curr;        // move pointers
		curr = temp;
	}

	return prev;
}

void PrintList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
	return;
}

Node * InsertNode(Node *head,int x)
{
	if (head == NULL)
	{
		head = AllocNode(x);
		return head;
	}
	// Insert into list
	Node *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;

	}
	temp->next = AllocNode(x);

	return head;

}


Node *AllocNode(int x)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = x;
	temp->next = NULL;

	return temp;
}