// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "malloc.h"

typedef struct Node
{
	int data;
	struct Node *next;
} Node;

Node *createNode(int i)
{
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	p->data = i;
	p->next = NULL;	
	return p;
}

void PrintList(Node *hptr);
Node *ReverseList(Node *hptr);
void DeleteNode(Node *hptr, int val);

int main()
{
	Node *tptr = NULL,*hptr = NULL,*temp = NULL;
	int i = 20;

	
	hptr = tptr;

	for (i = 0; i <= 20; i++)
	{
		tptr = createNode(i);

		if (hptr == NULL)
		{
			hptr = tptr;
			temp = hptr;
		}
		else
		{
			temp->next = tptr;
			temp = temp->next;
		}
		
	}
	

	PrintList(hptr);

	// Reverse the List
	tptr = NULL;
	Node *prev = NULL;
	Node *curr = hptr;
	while (curr != NULL)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	hptr = prev;
	PrintList(hptr);
	hptr = ReverseList(hptr);

	PrintList(hptr);

	DeleteNode(hptr, 10);

	PrintList(hptr);

	getchar();
    return 0;
}

void DeleteNode(Node *hptr, int val)
{
	Node *prev = NULL;
	Node *curr = hptr;
	Node *temp = NULL;

	// Check for fist node
	if (hptr->data == val)
	{
		temp = hptr;
		hptr = hptr->next;
	}
	else
	{
		// Go through the list
		while (curr != NULL)
		{
			if (curr->data == val)
			{
				temp = curr;
				prev->next = curr->next;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}

	free(temp);
}

Node *ReverseList(Node *hptr)
{
	Node *tprt = NULL;
	Node *prev = NULL;
	Node *curr = hptr;

	while (curr != NULL)
	{
		tprt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tprt;
	}
	return prev;
}

void PrintList(Node *hptr)
{
	Node *temp = hptr;
	while (temp != NULL)
	{
		printf("Node value is %d \n", temp->data);

		temp = temp->next;
	}

}

