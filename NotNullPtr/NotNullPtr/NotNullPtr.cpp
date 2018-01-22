// NotNullPtr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>


using namespace std;

typedef struct Node {
	int index;
	int rand;
	struct Node *next;
}Node;

Node *InsertNode(Node *head, int x, int y);
Node *AllocNode(int x, int y);
void PrintList(Node *head);

int main()
{
	Node *head = nullptr;
	for (int i = 0; i < 10; i++)
	{
		head = InsertNode(head,i , rand()%20);
	}

	PrintList(head);

	system("pause");
    return 0;
}

void PrintList(Node *head)
{
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->index << "  " << temp->rand << "  " << endl;
		temp = temp->next;
	}
}

Node *InsertNode(Node *head, int x, int y)
{
	if (head == nullptr)
	{
		head = AllocNode(x, y);
		return head;
	}
	
	Node *temp = AllocNode(x, y);
	temp->next = head;
	head = temp;
	return head;
}


Node *AllocNode(int x,int y)
{
	Node *ptr = (Node *)malloc(sizeof(Node));
	ptr->index = x;
	ptr->rand = y;
	ptr->next = nullptr;

	return ptr;
}
