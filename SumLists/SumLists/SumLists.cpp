// SumLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	int digit;
	struct Node *next;
}Node;

void CreateNumLists(Node **head, int num[]);
void PrintLists(Node *head);
int SumOfLists(Node *pNum1, Node *pNum2);
int PowerOf(int pow);

int main()
{
	int num1[3] = { 7,1,6 };
	int num2[3] = { 5,9,2 };
	Node *pNum1 = NULL, *pNum2 = NULL;
	// Create two linked lists with digits
	CreateNumLists(&pNum1, num1);
	CreateNumLists(&pNum2, num2);
	cout << "List one is  " << endl;
	PrintLists(pNum1);
	cout << "List two is " << endl;
	PrintLists(pNum2);
	cout << "The sum of the lists is " << SumOfLists(pNum1, pNum2) << endl;

	system("pause");
    return 0;
}

int SumOfLists(Node *pNum1, Node *pNum2)
{
	int sum = 0;
	int power = 0;
	Node *temp = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (pNum1 != NULL)
		{
			sum += pNum1->digit * PowerOf(i);
		}
		if (pNum2 != NULL)
		{
			sum += pNum2->digit * PowerOf(i);
		}
		pNum1 = pNum1->next;
		pNum2 = pNum2->next;
	}
	return sum;
}
int PowerOf(int pow)
{
	int i = 0;
	int mul = 1;
	if (pow == 0)
		return 1;
	if (pow > 0)
	{
		while (i < pow)
		{
			mul *= 10;
			i++;
		}
		return mul;
	}
}
void PrintLists(Node *head)
{
	Node *temp;
	temp = head;
	while (temp->next != NULL)
	{
		cout << "Value is " << temp->digit << "  ";
		temp = temp->next;
	}
	cout << endl;
}

void CreateNumLists(Node **head, int num[])
{
	Node *temp = NULL,*ptr = NULL;
	int count = 3; // Each number is three digits long
	// Check for head
	for (int i = 0; i <= count; i++)
	{
		temp = (Node *)malloc(sizeof(Node));
		temp->next = NULL;
		if (*head == NULL)
		{
			*head = temp;
			(*head)->digit = num[i];
		}
		else
		{
			ptr = *head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = temp;
			temp->digit = num[i];
		}
	}
}

