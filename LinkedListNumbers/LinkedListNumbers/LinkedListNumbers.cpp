// LinkedListNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

Node * InsertNode(Node *head, int dat);
Node *AllocNode(int dat);
void PrintNumber(Node *n);
int AddLists(Node *n1, Node *n2);
int GetDigit(Node *n, int d);

int main()
{
	Node *n1 = NULL;
	Node *n2 = NULL;
	int count = 3;

	n1 = InsertNode(n1,5);
	n1 = InsertNode(n1,6);
	n1 = InsertNode(n1,3);

	n2 = InsertNode(n2,8);
	n2 = InsertNode(n2,4);
	n2 = InsertNode(n2,2);

	PrintNumber(n1);
	PrintNumber(n2);

	cout << AddLists(n1, n2);


	cout << endl;
	system("pause");
    return 0;
}

int AddLists(Node *n1, Node *n2)
{
	int d1 = 0, d2 = 0;
	int v1 = 0, v2 = 0;
	Node *temp1 = NULL;
	Node *temp2 = NULL;
	int c1 = 0, c2 = 0;
	int power = 1;
	int sum = 0;
	// How to add the numbers in lists  traverse to find number of nodes in each
	// Traverse each list to a specific digit get the values and add them according to their
	// powers of 10 to a sum
	temp1 = n1;
	while (temp1 != NULL)
	{
		d1++;
		temp1 = temp1->next;
	}
	temp2 = n2;
	while (temp2 != NULL)
	{
		d2++;
		temp2 = temp2->next;
	}
	// Now we travel down to an equal depth and get values
	temp1 = n1;
	temp2 = n2;
	if (d1 == d2)  // same number of digits
	{
		while (c1 != d1 && c2 != d2)
		{
			while (c1 < d1-1)
			{
				temp1 = temp1->next;
				c1++;
			}

			sum += temp1->val*power;
			while (c2 < d2-1)
			{
				temp2 = temp2->next;
				c2++;
			}
			
			sum += temp2->val*power;

			c1 = 0;
			c2 = 0;

			d1--;
			d2--;
			if (d1 == 0 && d2 == 0)
				break;
			temp1 = n1;
			temp2 = n2;
			power *= 10;
		}
	}
	cout << "Sum is " << sum << endl;

	return sum;
}

int GetDigit(Node *n,int d)
{
	Node *temp = n;
	int i = 0;
	while (i != d)
	{
		temp = temp->next;
		i++;
	}
	return temp->val;
}

void PrintNumber(Node *n)
{
	Node *temp = n;
	cout << endl;
	while (temp != NULL)
	{
		cout << temp->val;
		temp = temp->next;
	}
	cout << endl;
}
Node * InsertNode(Node *head, int dat)
{
	Node *temp = head;
	if (head == NULL)
	{
		head = AllocNode(dat);
		return head;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = AllocNode(dat);

	return head; // head is unchanged
}

Node *AllocNode(int dat)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = dat;
	temp->next = NULL;
	return temp;
}