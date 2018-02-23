// SimpleCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;




int main()
{
	const char *input = "2+3*5-2+9/4";


	stack<char> ops;
	stack<float> dig;
	int digit1, digit2;
	float result;
	char oper1, oper2; 

	const char *p = input;  // points to the beginning of the string

					  // Parse the string from left to right and push the digits onto stack and
					  // the operators onto the stack  
					  // Pop the operators in order of precedence and calsulate the value and push back onto the stack


	while (*p != '\0')
	{
		if (*p - '0' >= 0 && *p - '9' <= 9)  // This is a digit
		{
			dig.push(*p-'0');

		}
		if (*p == '*' || *p == '/' || *p == '+' || *p == '-')
		{
			ops.push(*p);

		}
		p++;


	}
	// Now parse the stacks 

	while (!ops.empty())
	{
		// Pop off two digits and an operation
		// Peek at the next operation and if it is of a higher precedence
		// then evaluate

		digit1 = dig.top();
		dig.pop();
		digit2 = dig.top();
		dig.pop();
		oper1 = ops.top();
		ops.pop();
		if (!ops.empty())
			oper2 = ops.top();   // Peek  no pop
							 // Check the precedence for the operatos
		else
			oper2 = '\0';

		if (oper1 == '*' || oper1 == '/')
		{
			if (oper1 == '*')
			{
				result = digit1 * digit2;
				dig.push(result);
			}
			if (oper1 == '/')
			{
				result = digit2 / digit1;
				dig.push(result);
			}
		}

		if (oper1 == '+' || oper1 == '-')    // Adition and subtraction check operator2 
		{

			if (oper2 == '\0' || oper2 == '+' || oper2 == '-')
			{
				// evaluate
				if (oper1 == '+')
				{
					result = digit1 + digit2;
					dig.push(result);
				}
				if (oper1 == '-')
				{
					result = digit2 - digit1;
					dig.push(result);
				}
			}
			if (oper2 == '*' || oper2 == '/')
			{
				// Push the addition and subtraction back onto stack
				// Push digits back onto the stack   Evaluate later 
				// This is incorrect poping and pushing same values
				// evaluate this first
				int digit3 = dig.top();
				dig.pop();
				ops.pop(); // Pop operator 2
				// Evaluate digit3 and digit2
				if (oper2 == '*')
				{
					result = digit2 * digit3;
				}
				if (oper2 == '/')
				{
					result = digit3 / digit2;
				}
				// Push everything back onto stack
				dig.push(result);
				dig.push(digit1);

				ops.push(oper1);
			}
		}

	}

	// Result will be last element on stack
	cout << "The result is " << dig.top() << endl;

	system("pause");
    return 0;
}

