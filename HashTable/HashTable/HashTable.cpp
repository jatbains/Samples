// HashTable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

typedef struct Node
{
	int val;
	int key;
	struct Node *next;
}Node;

const static int MAX_SIZE = 100;

class HashTable
{
private:
	int count;
	Node *list[MAX_SIZE];
	Node *AllocNode(int key, int x);

public:
	HashTable(void);
	void Insert(int key,int x);
	int Retreive(int key,int x);

};

int HashTable::Retreive(int key,int x)
{
	// get index
	int data = 0;
	int index = key % MAX_SIZE;
	// Check list
	if (list[index]->val == x)
	{
		Node *temp = list[index];
		data = temp->val;
		list[index] = temp->next;
		free(temp);
		return data;
	}
	// Not at front need to find it
	Node *prev = NULL;
	Node *temp = list[index];
	while (temp->val != x)
	{
		temp = temp->next;   // prev is one behind
		prev = temp;
	}
	// found it
	prev->next = temp->next;   
	data = temp->val;
	free(temp);
	return data;
}

Node * HashTable::AllocNode(int key, int x)
{
	Node *tNode = (Node *)malloc(sizeof(Node));
	tNode->key = key;
	tNode->val = x;
	tNode->next = NULL;

	return tNode;
}

void HashTable::Insert(int key, int val)
{
	Node *tNode = AllocNode(key, val);

	// Hash to find right bucket
	int index = key % MAX_SIZE;

	// Add it to the index list
	if (list[index] == NULL)
	{
		list[index] = tNode;
		return;
	}
	// Else we have an overflow
	Node *temp = list[index];
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = tNode;
	return;
}

HashTable::HashTable(void)
{
	count = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		list[i] = NULL;
	}
}



int main()
{


	system("pause");
    return 0;
}

