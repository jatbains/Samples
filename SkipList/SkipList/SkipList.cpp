// SkipList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct SkipNode
{
	int key;
	struct SkipNode *next;
	struct SkipNode *level;
}SkipNode;

static const int MaxLevels = 10;
SkipNode * AllocNode(int x);
SkipNode * InsertValue(SkipNode *head, int x);

int main()
{
	SkipNode *list[10] = { nullptr };   // pointer to pointer
	// Create a skiplist with levels
	// Array of pointers
	SkipNode **SkipList = (SkipNode **) malloc(sizeof(SkipNode*)*MaxLevels);

	// memset values to zero
	memset(SkipList, 0, sizeof(SkipNode*)*MaxLevels);

	// Add nodes into this list we have the head nodes

	for (int i = 0; i < MaxLevels; i++)
	{
		if (SkipList[i] != nullptr)
		{
			
			SkipList[i] = InsertValue(SkipList[i], 10*i);
			SkipList[i]->key = 10 * i;
		}
		
	}
	cout << endl;


	system("pause");
    return 0;
}

SkipNode * AllocNode(int x)
{
	SkipNode *tNode = (SkipNode*)malloc(sizeof(SkipNode));
	tNode->key = x;
	tNode->level = tNode->next = nullptr;
	return tNode;
}

SkipNode * InsertValue(SkipNode *head, int x)
{
	if (head == nullptr)
	{
		head = AllocNode(x);
		return head;
	}
	SkipNode *temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = AllocNode(x);
	return head;
}