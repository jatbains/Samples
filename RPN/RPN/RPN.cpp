// RPN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int StringToInt(const char *st);


int main()
{
	const char *tokens[] = {"4", "1", "+", "2.5", "*"};
	stack<double> stk;
	int size = sizeof(tokens) / sizeof(tokens[0]);
	double x = 0, y = 0;

	// Algorithm is to push elements on stack until an 
	// operator is encountered.  When encountered pop off 
	// two elements perform operation and push result onto stack
	for (int i = 0; i < size; i++)
	{
		if ((tokens[i][0] == '+') || (tokens[i][0]=='-') || (tokens[i][0]=='*') || (tokens[i][0]=='/'))
		{
			// We found a token process two elements
			x = stk.top();   // top element on stack
			stk.pop();
			y = stk.top();
			stk.pop();
			// Do the processing
			switch (tokens[i][0])
			{
			case '+':
				stk.push(x + y);
				break;
			case '-':
				stk.push(x - y);
				break;
			case '*':
				stk.push(x*y);
				break;
			case '/':
				stk.push(x / y);
				break;

			}


		}
		else // Found a number push onto to the stack
		{
			stk.push(atof(tokens[i]));

		}
		
	}

	cout << "Answer is " << stk.top() << endl;


	system("pause");
    return 0;
}

int StringToInt(const char *st)
{
	return atoi(st);
}