// CopyNode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct Node
{
	struct Node *one;
	struct Node *two;
}Node;

Node * CopyNode(Node *in);

int main()
{
	Node *myNode = (Node *)malloc(sizeof(Node));

	Node *copy = NULL;

	copy = CopyNode(myNode);


	system("pause");
    return 0;
}

Node * CopyNode(Node *in)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->one = in->one;
	temp->two = in->two;

	return temp;

}
