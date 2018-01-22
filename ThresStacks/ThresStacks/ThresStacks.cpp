// ThresStacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 40;

typedef struct Stack
{
	int Array[MAX_SIZE];
	int topA;
	int sizeA;
	int topB;
	int sizeB;
	int topC;
	int sizeC;

}Stack;

void PushOnStack(Stack *stack, int val, int Num);

int main()
{
	Stack myStack;
	myStack.Array[MAX_SIZE] = { 0 };
	// Num is 1 for stack a for stack b and 3 for stack c
	PushOnStack( &myStack, rand(), 1);


    return 0;
}

void PushOnStack(Stack *stack, int val, int Num)
{
	if (Num == 1)
	{
		stack->topA++;
		stack->Array[stack->topA] = Num;
	}
	else if (Num == 2)
	{
		stack->topB++;
		stack->Array[stack->topB] = Num;
	}
	else if (Num == 3)
	{
		stack->topC++;
		stack->Array[stack->topC] = Num;
	}
}
