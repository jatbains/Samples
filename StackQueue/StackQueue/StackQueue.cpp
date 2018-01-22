// StackQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
const int MAX_STACK = 20;
const int MAX_QUEUE = 20;

class StackQueue 
{
public:
	StackQueue()
	{
		mIndex = -1;
		qIndex = -1;
	}
	int StackQueuePop(void);
	void StackQueueEnqeue(int);
	bool IsStackFull(void);
	int StackQueueDequeue(void);
	void StackQueuePush(int);
	int StackTop(void);
	int StackSize(void);

private:
	int mIndex;
	int qIndex;
	int mainStack[MAX_STACK];
	int queueStack[MAX_STACK];

};

int StackQueue::StackSize(void)
{
	return mIndex;
}

int StackQueue::StackQueueDequeue(void)
{
	// Pop from the queue stack
	int val = 0;
	if (qIndex >= 0)
	{
		val = queueStack[qIndex];
		qIndex--;
	}
	return val;
}

int StackQueue::StackTop(void)
{
	return mainStack[mIndex];
}

void StackQueue::StackQueuePush(int val)
{
	// Push onto queue stack
	if (qIndex < MAX_STACK)
	{
		qIndex++;
		queueStack[qIndex] = val;
	}
}

void StackQueue::StackQueueEnqeue(int val)
{
	if (mIndex < MAX_STACK)
	{
		mIndex++;
		mainStack[mIndex] = val;
	}
}

int StackQueue::StackQueuePop(void)
{
	int val = 0;
	if (mIndex >= 0)
	{
		val = mainStack[mIndex];
		mIndex--;
	}
	return val;
}

bool StackQueue::IsStackFull(void)
{
	if (mIndex == MAX_STACK - 1)
		return true;
	else
		return false;
}

int main()
{
	int i = 0, val = 0;
	int stackSize = 0;
	StackQueue myQueue;
	// Wish to create a queue 
	// Populate the stack first
	for (i = 0; i < MAX_STACK; i++)
	{
		myQueue.StackQueueEnqeue(rand());
		cout << "The values being pushed are " << myQueue.StackTop() << endl;
	}
	// Pop from queue move all elements to queue stack and pop of on from top
	stackSize = myQueue.StackSize();
	for (i = 0; i <= stackSize; i++)
	{
		val = myQueue.StackQueuePop();
		cout << "Value popped from main is " << val << endl;
		// Push onto second
		myQueue.StackQueuePush(val);

	}
	// Popping oldest element
	cout << "Popping off the Oldest element " << myQueue.StackQueueDequeue() << endl;


	system("pause");
    return 0;
}

