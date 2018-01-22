// TrickyClasses.cpp : Defines the entry point for the console application.
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

class T
{
private:
	int V;
	Node node;

public:
	T(int x);
	void AddNode(int x);
	void Print(void);
};

void T::Print(void)
{
	cout << node.val << " " << V << endl;
}

void T::AddNode(int x)
{
	node.next = (Node *)malloc(sizeof(Node));
	node.val = x;
}

T::T(int x)
{
	V = x;
	node.next = NULL;
	node.val = 0;
}

int main()
{
	T Arr(10);
	Arr.AddNode(20);

	Arr.Print();

	system("pause");
    return 0;
}


