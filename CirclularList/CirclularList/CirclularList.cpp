// CirclularList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

typedef struct Node {
	struct Node *next;
	int val;
}Node;

Node * CreateList(int x);

int main()
{
	int num = 0;
	cout << "Enter a number " << "\n";
	cin >> num;
	Node *list = NULL;

	list = CreateList(num);

	getchar();
	return 0;
}

Node * CreateList(int x)
{
	Node *head = NULL;
	Node *temp = NULL;

	if (x == 0)
		return NULL;

	temp = (Node *)malloc(sizeof(Node));
	head = temp;
	temp->val = 0;

	for (int i = 1; i <= x; i++)
	{
		temp->next = (Node *)malloc(sizeof(Node));
		temp->val = i;
		temp = temp->next;
	}

	// POint last to head
	temp->next = head;
	return head;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
