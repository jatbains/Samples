// SortStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	int val;
	struct Node *next;

}Node;

class Stack
{
private:
	Node *top;   // top if stack
	int count;  // count of items
	Node * AllocNode(int val);
public:
	Stack(void);
	void Push(int val);
	int Pop(void);
	int Peek(void);
	bool IsEmpty(void);
	void PrintStack(void);
};

void Stack::PrintStack(void)
{
	Node *temp = top;
	while (temp->next != NULL)
	{
		cout << "Stack Val is " << temp->val << endl;
		temp = temp->next;
	}
	// Print last
	cout << "Stack Val is " << temp->val << endl;
}

Stack::Stack(void)
{
	top = NULL;
	count = 0;
}

void Stack::Push(int val)
{
	Node *temp = AllocNode(val);
	temp->next = top;  // Add at the top
	top = temp;        // Move pointer to the top
	count++;
}

int Stack::Peek(void)
{
	if (count > 0)
		return top->val;
}

int Stack::Pop(void)
{
	int val = 0;
	Node *temp = NULL;
	temp = top;
	if (top != NULL)
	{
		top = top->next;
		count--;
		val = temp->val;
		free(temp);
		return val;
	}
	// Empty
	return -1;
}

bool Stack::IsEmpty(void)
{
	if (!count)
		return true;
	else
		return false;
}

Node * Stack::AllocNode(int val)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

int main()
{
	Stack myStack;
	Stack secStack;
	int val = 0;
	int temp = 0;
	int data[] = { 12,5,18,7,19,13,27,3,9 };
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		myStack.Push(data[i]);
	}

	myStack.PrintStack();

	// Sort stack and put elements in secStack
	// Pop elements of first int temp compare to top of sec stack
	// if item is smaller add it else pop it off push on first then add item

	while (!myStack.IsEmpty())
	{
		val = myStack.Pop();
		while (!secStack.IsEmpty() && secStack.Peek() > val)
		{
			myStack.Push(secStack.Pop());
		}
		secStack.Push(val);
		// Copy elements back to main stack
	}
	while (!secStack.IsEmpty())
	{
		myStack.Push(secStack.Pop());
	}
	// Print secondary stack
	
	cout << endl << "The sorted stack is" << endl;
	myStack.PrintStack();

	system("pause");
    return 0;
}

