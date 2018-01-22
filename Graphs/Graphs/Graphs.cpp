// Graphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>


using namespace std;

class Node
{
public:
	int val;
	Node *next;

	int getValue(void)const
	{
		return val;
	}
	bool operator()(const Node &lhs, const Node &rhs) const
	{

		int t1Val = lhs.getValue();
		int t2Val = rhs.getValue();
		return t1Val < t2Val;
	}

};


Node *AllocNode(int val);


int main()
{
	
	stack<Node> myStack;
	queue<Node> myQueue;

	priority_queue<Node> mypQueue;

	for (int i = 0; i < 10; i++)
	{
		Node *temp = AllocNode(rand());
		myStack.push(*temp);
		myQueue.push(*temp);
		mypQueue.push(*temp);
	}


	system("pause");
    return 0;
}

Node *AllocNode(int val)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->val = val;
	temp->next = NULL;

	return temp;
}

