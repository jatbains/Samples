// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

typedef struct Node
{
	int num;
	char op;
	bool IsNum;
	struct Node *next;
}Node;

Node * AllocNode(int val,char c, bool num);
Node * PushNumStack(Node *head, int val);
char PopCharStack(Node **head);
int PopIntStack(Node **head);
Node * PushCharStack(Node *head, char op);
Node * PushNumStack(Node *head, int val);
char PeekCharStack(Node *head);
int CalculateValue(int x, int y, char op);

int main()
{
	char *eq = "2*3+2/6*3+15";
	char *c = eq;
	int size = 0;
	int x = 0, y = 0;
	char *n;
	Node *numStack = NULL;
	Node *opStack = NULL;
	int result = 0;

	while (*c != '\0')
	{
		size++;
		c++;
	}
	// size is number of chracters
	c = eq;  // start of the string
	while (*c != '\0')
	{
		// Check for integer of operator
		if (*c >= '0' && *c <= '9')
		{
			n = c;
			n++;
			if (*n >= '0' && *n <= '9')
			{	                         // number is *c*10 + *n
				x = (*c - '0') * 10 + (*n - '0');
				c++;
			}
			else
			{
				x = (*c - '0');
			}
			// Push onto number stack
			numStack = PushNumStack(numStack, x);
		}
		if (*c == '*' || *c ==  '/' || *c == '+' || *c == '-')    // Multiply or divide take precedence
		{			
			// Peek at current operator
			char top = PeekCharStack(opStack);
			if (((*c == '+' || *c == '-') && (top == '*' || top == '/')) || ((*c == '*' || *c == '/') && (top == '*' || top == '/')))
			{
				// Push onto stack
				// Pop and process and push back
				int x = PopIntStack(&numStack);
				int y = PopIntStack(&numStack);
				top = PopCharStack(&opStack);
				result = CalculateValue(x, y, top);
				PushNumStack(numStack, result);

			}
			else if (((*c == '+' || *c == '-') && (top == '+' || top == '-')) || ((*c == '*' || *c == '/') && (top == '*' || top == '/')))
			{


				opStack = PushCharStack(opStack, *c);   // Push onto operator stack 
			}
			else
			{
				opStack = PushCharStack(opStack, *c);   // Push onto operator stack     
			}                     
		}
		c++;
	}
	// When done result will have values

	cout << " The result is " << result << endl;


	system("pause");
    return 0;
}

int CalculateValue(int x,int y, char op)
{

	// Process the elements on the two stacks
	if (op == '+')
	{
		return x + y;
	}
	if (op == '-')
	{
		return x - y;
	}
	if (op == '*')
	{
		return x*y;
	}
	if (op == '/')
	{
		return x / y;
	}


}

char PeekCharStack(Node *head)
{
	// Check the operator at top
	if (head == NULL)
		return NULL;
	char op = head->op;
	return op;
}





Node * AllocNode(int val,char c,bool num)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->num = val;
	temp->op = c;
	temp->next = NULL;
	temp->IsNum = num;

	return temp;
}

Node * PushCharStack(Node *head, char op)
{
	if (head == NULL)
	{
		head = AllocNode(NULL, op, false);
		return head;
	}
	Node *temp = AllocNode(NULL, op, false);
	temp->next = head;
	head = temp;
	return head;
}

int PopIntStack(Node **head)
{
	int va;
	Node *temp = *head;
	if (*head == NULL)
		return 0;
	if (temp->IsNum)
		va = temp->num;
	*head = (*head)->next;
	free(temp);
	return va;
}

char PopCharStack(Node **head)
{
	Node *temp = *head;
	char c;
	if (*head == NULL)
		return 0;
	if (!temp->IsNum)
		c = temp->op;
	*head = (*head)->next;
	free(temp);
	return c;	
}

Node * PushNumStack(Node *head, int val)
{
	if (head == NULL)
	{
		head = AllocNode(val, NULL, true);
		return head;
	}
	Node *temp = AllocNode(val,NULL, true);
	temp->next = head;
	head = temp;
	return head;
}