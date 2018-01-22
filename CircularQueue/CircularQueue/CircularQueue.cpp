// CircularQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

class CircleQueue
{
private:
	CircleQueue * head;
	CircleQueue * tail;
	CircleQueue * next;
	int data;
	CircleQueue *AllocNode(int x);

public:
	CircleQueue(int x);
	void EnqueueElement(int val);
	int DequeueElement(void);
	void PrintValues(void);
};

void CircleQueue::PrintValues(void)
{
	CircleQueue *temp;
	temp = head;
	while (temp != tail)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int CircleQueue::DequeueElement(void)
{
	// Dequeue from the tail
	int data;
	CircleQueue *temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	// Adjust the tail
	tail = temp;
	data = temp->data;
	tail->next = NULL;
	delete(temp);
	return data;
}

void CircleQueue::EnqueueElement(int val)
{
	// Check the head
	if (head == NULL)
	{
		head = AllocNode(val);
		tail = head;	
		return;
	}
	// else add at the tail
	CircleQueue *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = AllocNode(val);
	// Adjust tail
	tail = temp->next;
	
}

CircleQueue * CircleQueue::AllocNode(int x)
{
	CircleQueue *temp = new CircleQueue(x);
	return temp;
}

CircleQueue::CircleQueue(int x)
{
	head = NULL;
	tail = NULL;
	next = NULL;
	data = x;
}


int main()
{
	CircleQueue *nQueue = new CircleQueue(1);
	int data[] = { 22,1,34,15,6,17,5,12,3,9,15,25,30,27 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i <= size; i++)
	{
		nQueue->EnqueueElement(data[i]);
	}

	// Print out the values
	nQueue->PrintValues();

	nQueue->DequeueElement();
	cout << endl;

	nQueue->PrintValues();

	system("pause");
    return 0;
}

