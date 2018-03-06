// ScrambledString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	char c;
	int index;
	struct Node *left;
	struct Node *right;
}Node;

Node *AllocNode(int i, char s);
Node *InsertNode(Node *node, int i, char c);
void PrintInOrder(Node *node);
void Scramble(Node **orig, Node **scram);

int main()
{
	Node *oRoot = nullptr;
	Node *nRoot = nullptr;
	string word = "speaker";
	
	int mid = word.length() / 2;

	for (int i = mid; i >= 0; i--)
	{
		oRoot = InsertNode(oRoot, i, word[i]);
	}

	for (int i = mid + 1; i < word.length(); i++)
	{
		oRoot = InsertNode(oRoot, i, word[i]);
	}

	PrintInOrder(oRoot);

	cout << endl;

	Scramble(&oRoot, &nRoot);

	cout << endl;

	PrintInOrder(nRoot);
	cout << endl;
	system("pause");
    return 0;
}

Node *AllocNode(int i,char s)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->c = s;
	temp->index = i;
	temp->left = temp->right = nullptr;

	return temp;
}

Node *InsertNode(Node *node, int i,char c)
{
	if (node == nullptr)
	{
		node = AllocNode(i,c);
		return node;
	}
	if (i < node->index)
	{
		node->left = InsertNode(node->left, i, c);
	}
	else
	{
		node->right = InsertNode(node->right, i, c);
	}
	return node;
}

void Scramble(Node **orig, Node **scram)
{
	if (*orig == nullptr)
		return;
	Node *temp = AllocNode((*orig)->index, (*orig)->c);
	*scram = temp;
	Scramble(&(*orig)->left, &(*scram)->right);
	Scramble(&(*orig)->right, &(*scram)->left);
}

void PrintInOrder(Node *node)
{
	if (node == nullptr)
		return;
	PrintInOrder(node->left);
	cout << " Index " << node->index << " char " << node->c ;
	PrintInOrder(node->right);
}