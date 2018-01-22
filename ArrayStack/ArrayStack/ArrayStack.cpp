// ArrayStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

const int MAXSIZE = 20;

class ArrayStack
{
public:
	ArrayStack()
	{
		Num = -1;
		Stack[MAXSIZE] = { 0 };
	}
	bool IsStackFull();
	bool IsStackEmpty();
	void PushOnStack(int val);
	int PopOffStack(void);
	int ValueOnTop(void);
private:
	int Num;
	int Stack[MAXSIZE];

};

bool ArrayStack::IsStackFull()
{
	if (Num == MAXSIZE-1)
		return true;
	else
		return false;
}
bool ArrayStack::IsStackEmpty()
{
	if (Num == -1)
		return true;
	else
		return false;

}
void ArrayStack::PushOnStack(int val)
{
	if (Num < MAXSIZE-1)
	{
		Num++;
		Stack[Num] = val;
	}
}

int ArrayStack::PopOffStack(void)
{
	int element = 0;
	if (Num > -1)
	{
		element = Stack[Num];
		Num--;
	}
	return element;
}

int ArrayStack::ValueOnTop(void)
{
	return Stack[Num];
}

int main()
{
	ArrayStack RandStack;
	// Populate the stack
	cout << "Adding Random numbers to stack" << endl;
	for (int i = 0; i < MAXSIZE; i++)
	{
		RandStack.PushOnStack(rand());
		cout << "Value Pushed onto Stack is " << RandStack.ValueOnTop() << endl;
	}

	cout << "Popping off 10 numbers from stack " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "Value Popped Off is " << RandStack.PopOffStack() << endl;
	}
	cout << "Value on the top os stack is " << RandStack.ValueOnTop() << endl;
	// Modify Array So three stacks can be represented


	system("pause");

    return 0;
}

