// AdvancedCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// Parse a string of characters which is an arithmetic expression
// Evaluate the expression

float EvaluateOperator(char ops, float a, float b);
float CalculateResult(string exp);
bool HasPrecedence(char op1, char op2);

int main()
{
	string exp = "5*(4+6/2)-3+9/5";

	CalculateResult(exp);

	system("pause");
    return 0;
}
// Parse the string and calculate the results
// Parse from left to right with following rules
// If a bracket is encountered push elements onto a a stack and 
// evaluate when end of the bracket 
// If number then push onto a stack .  I an operator is encountered
//  then pop off two digits and perform operation and push result onto stack
//  If a * or / is encountered and next is + or - then perform it
//  If a + or - is encountered and next is a + or -  then perform it and push results
//  If a + or - is encountered and next is a * or / then push onto stack and perform next 
//  Operation
float CalculateResult(string exp)
{
	string::iterator it;
	float dig1 = 0;
	float dig2 = 0;
	char op;
	stack<char> ops;
	stack<float> values;


	// What we can do is read till end and push operators and chracters into stacks
	
	// Push from one stack to another to rearrange the elements	


	for (it = exp.begin(); it != exp.end(); it++)
	{
		if (*it == ' ')
			continue;
		if (*it >= '0' && *it <= '9')
		{
			string valString;
			/*while (it != exp.end() && *it >= '0' && *it <= '9')
			{
				valString += *it;
				it++;
			}*/
			values.push((float)atoi(valString.c_str()));
		}

		else if (*it == '(')    // Treat it like another operator
		{
			ops.push(*it);
		}
		// If oper is )  pop off until ( and evaluate
		else if (*it == ')')
		{
			while (ops.top() != '(')
			{
				op = ops.top();
				ops.pop();
				dig1 = values.top();
				values.pop();
				dig2 = values.top();
				values.pop();
				values.push(EvaluateOperator(op, dig1, dig2));
			}
		}
		else if (*it == '*' || *it == '/' || *it == '+' || *it == '-')
		{
			while (!ops.empty() && HasPrecedence(*it, ops.top()))
			{
				op = ops.top();
				ops.pop();
				dig1 = values.top();
				values.pop();
				dig2 = values.top();
				values.pop();
				values.push(EvaluateOperator(op, dig1, dig2));
			}

			// Push current token to 'ops'.
			ops.push(*it);
		}
	}
	while (!ops.empty())
	{
		op = ops.top();
		ops.pop();
		dig1 = values.top();
		values.pop();
		dig2 = values.top();
		values.pop();
		values.push(EvaluateOperator(op, dig1, dig2));

	}	
	return values.top();;
}

bool HasPrecedence(char op1, char op2)
{
	if (op2 == '(' || op2 == ')')
		return false;
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
		return false;
	else
		return true;
}

float EvaluateOperator(char ops, float a, float b)
{

	switch (ops)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		if (b != 0)
			return a / b;
		else
			return -1;
	default:
		return -1;
	}
}