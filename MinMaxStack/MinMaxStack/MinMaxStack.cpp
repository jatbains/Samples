// MinMaxStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int MAX_SIZE = 40;
const int MIN_INDEX = -1;

class MinMaxStack
{
public:
	MinMaxStack()
	{
		index = MIN_INDEX;
		myArray[MAX_SIZE] = { 0 };
		minVal = 0;
		maxVal = 0;
	}
	int PopOffStack(void);
	void PushOnStack(int val);
	bool IsStackFull(void);
	int GetMinValue(void);
	int GetMaxValue(void);
	int GetValStack(void);

private:
	int myArray[MAX_SIZE];
	int index;
	int minVal;
	int maxVal;
};

int MinMaxStack::GetValStack(void)
{
	return myArray[index];
}

int MinMaxStack::GetMinValue(void)
{
	return minVal;
}
int MinMaxStack::GetMaxValue(void)
{
	return maxVal;
}

void MinMaxStack::PushOnStack(int val)
{
	if (index <= 0) 
		minVal = val;
	if (val <= minVal)
		minVal = val;
	if (val >= maxVal)
		maxVal = val;
	// Push on stack
	if (index < MAX_SIZE - 1)
	{
		index++;
		myArray[index] = val;
	}
}
int MinMaxStack::PopOffStack(void) 
{
	int val = 0;
	if (index > -1)
	{
		val = myArray[index];
		index--;
	}
	// Update min and max
	for (int i = 0; i <= index; i++)
	{
		if (minVal > myArray[i])
			minVal = myArray[i];
		if (maxVal < myArray[i])
			maxVal = myArray[i];
	}
	return val;
}


bool MinMaxStack::IsStackFull(void)
{
	if (index == (MAX_SIZE - 1))
		return true;
	else
		return false;
}

int main()
{ 
	MinMaxStack myStack;
	cout << "Push Values onto the stack " << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		myStack.PushOnStack(rand());
		cout << "Value added on Stack  " << myStack.GetValStack() << endl;
	}


	cout << "The max value is " << myStack.GetMaxValue() << endl;
	cout << "The min value is " << myStack.GetMinValue() << endl;
	 
	cout << "Is the stack full " << myStack.IsStackFull() << endl;

	system("pause");
    return 0;
}

