// LargeNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class LargeNumber
{
private:
	char *num;
	int size;
	void DoubleSize();
public:
	LargeNumber(int size);
	void WriteNumber(int index,int i);
	void AddNumberToIt(int i);
	void DisplayNumber();
};

LargeNumber::LargeNumber(int x)
{
	size = x;
	num = (char *)malloc(sizeof(char)*x);
}

void LargeNumber::WriteNumber(int index,int i)
{
	if (i == -1)
	{
		num[index] = '\0';
	}
	else
	{
		num[index] = (char)(i+'0');
	}
	
}

void LargeNumber::AddNumberToIt(int i)
{
	// Add i to the end of the number
	char *p = num;
	bool carry = false;
	int digit = 0;
	while (*p != '\0')
	{
		p++;
	}
	p--;
	// Add it to the big number
	while (p != num)
	{
		digit = *p - '0';
		
		if ((digit + i) > 9)
		{
			*p = (char)(((digit + i) % 10)+'0');
			carry = true;
			i = 0;  // Done processing
		}
		else if (carry)
		{
			*p = (char)((digit + 1) + '0');
			carry = false;
		}
		else
		{
			*p = (char)((digit + i) + '0');
			carry = false;	
			i = 0;
		}
		p--;
	}
	// If carry is still true then we need to double size
	if (carry)
	{
		DoubleSize();
	}
}

void LargeNumber::DoubleSize()
{
	int count = size;
	size = size * 2;
	char *p = num;
	char *dNum = (char*)malloc(sizeof(char)*size);
	*dNum = 1;
	while (count <= size+1)
	{
		dNum++;
		*dNum = 0;
	}
	dNum++;
	*dNum = '\0';
	char *temp = num;
	num = dNum;
	free(temp);    // Free up old array
}



void LargeNumber::DisplayNumber()
{
	char *p = num;
	while (*p != '\0')
	{
		cout << " " << *p << " ";
		p++;
	}
	cout << endl;
	return;
}

int main()
{
	int size = 10;
	unsigned int x = 0;
	LargeNumber *myNum = new LargeNumber(size);

	for (int i = 0; i < size-1; i++)
	{
		x = rand() % 10;
		myNum->WriteNumber(i,x);
	}
	myNum->WriteNumber(size-1, -1);

	myNum->DisplayNumber();
	cout << endl;

	myNum->AddNumberToIt(1);
	myNum->DisplayNumber();
	system("pause");
    return 0;
}

