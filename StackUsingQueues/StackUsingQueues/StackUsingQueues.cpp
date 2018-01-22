// StackUsingQueues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class QueueStack
{
private:
	queue<int> queue1;
	queue<int> queue2;
	int activeQ;
	int count;
public:
	QueueStack();
	void PushOnStack(int x);

	int TopOfStack(void);
};

QueueStack::QueueStack(void)
{
	count = 0;
	activeQ = 1;
	queue1.empty();
	queue2.empty();
}

void QueueStack::PushOnStack(int x)
{
	if (activeQ == 1)
	{
		queue1.push(x);
		count++;
	}
	if (activeQ == 2)
	{
		queue2.push(x);
		count++;
	}

}


int QueueStack::TopOfStack(void)
{
	int val = 0;
	int newcount = 0;
	if (activeQ == 1)
	{
		while (count!=1)
		{
			val = queue1.front();
			queue2.push(val);
			count--;
			newcount++;
		}
		queue1.empty();
		count = newcount;
		activeQ = 2;
	}
	if (activeQ == 2)
	{
		while (count != 1)
		{
			val = queue2.front();
			queue1.push(val);
			count--;
			newcount++;
		}
		queue2.empty();
		count = newcount;
		activeQ = 1;
	}
	return val;
}

int main()
{
	int data[] = { 13,6,32,16,21,9,18,11 };
	QueueStack qStack;
	int size = sizeof(data) / sizeof(data[0]);

	for (int i = 0; i < size; i++)
	{
		qStack.PushOnStack(data[i]);
	}

	cout << "Pop off Value " << qStack.TopOfStack() << endl;


	system("pause");
    return 0;
}
