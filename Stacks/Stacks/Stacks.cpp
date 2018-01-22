// Stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

typedef struct Node
{
	int age;
	struct Node *next;
}Node;

class Stack
{
public:
	Stack()
	{
		// Initialize variables
		top = NULL;
		size = 0;
	}
	void Push(int age);
	int Pop(void);
	bool IsEmpty(void)
	{
		if (size == 0)
			return true;
		else
			return false;
	}
	int Size(void)
	{
		return size;
	}

private:
	Node *top;  // Top of stack
	int size;   // Size of stack

};

void Stack::Push(int age)
{
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->age = age;
	if (top == NULL)
	{
		temp->next = NULL;
		top = temp;
	}
	else
	{
		temp->next = top;
		top = temp;
	}
	size++;
}

int Stack::Pop(void)
{
	Node *temp;
	int age;
	temp = top;
	if (top->next != NULL)
		top = top->next;
	else
		top = NULL;
	size--;
	age = temp->age;
	free(temp);
	return
		age;
}

int main()
{
	cout << "A simple Stack with Linked Lists " << endl;
	Stack People;
	for (int i = 1; i < 10; i++)
	{
		People.Push(i);
		cout << "Size of stack is " << People.Size() << endl;
	}
	cout << "Popping 5 elements off list " << endl;

	for (int i = 1; i < 5; i++)
	{
		cout << "Popped item " << People.Pop() << " off the stack" << "Size is " << People.Size() << endl;
	}

	getchar();
    return 0;
}

