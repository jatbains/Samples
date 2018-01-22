// StackMIddle.cpp : Defines the entry point for the console application.
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

class Stack
{
private:
	int count;
	int minVal;
	Node *head;
public:
	Stack();
	void Push(int x);
	int Pop(void);
	int top(void);
	int getMin(void);
	int getCount(void);

};

int Stack::getCount(void)
{
	return count;
}

Stack::Stack(void)
{
	count = 0;
	head = NULL;
	minVal = 0;
}
void Stack::Push(int x)
{
	if (count == 0)
	{
		minVal = x;
	}
	else if (x < minVal)
	{
		minVal = x;
		x = 2 * x - minVal;
	}
	count++;
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->val = x;
	temp->next = head;
	head = temp;
}

int Stack::Pop(void)
{
	int val = 0;
	int mint = 0;
	count--;
	if (head != NULL)
	{
		Node *temp = head;
		head = head->next;
		val = temp->val;
		if (val < minVal)
		{
			mint = minVal;
			minVal = 2 * minVal - val;
		}
		else
		{
			mint = val;
		}
		free(temp);
		return mint;
	}
	
}

int Stack::getMin(void)
{
	if (head != NULL)
		return minVal;
 }
int Stack::top(void)
{
	if (head != NULL)
	{
		return (head->val < minVal ? minVal : head->val);
	}
		
}


int main()
{
	Stack *minStack = new Stack();
	int data[] = { 3,5,2,6,10,11,7,1,4,9 };
	int size = sizeof(data) / sizeof(data[0]);
	for (int i = 0; i < size; i++)
	{
		minStack->Push(data[i]);
	}

	cout << "Top " << minStack->top() << " Count " << minStack->getCount() << " MinVal " << minStack->getMin() << endl;


	cout << endl;
	// Pop 3 items
	for (int i = 0; i < 3; i++)
	{
		cout << "Pop " << minStack->Pop() << endl;
	}

	system("pause");
    return 0;
}

