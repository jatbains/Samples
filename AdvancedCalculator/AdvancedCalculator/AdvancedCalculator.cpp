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

int main()
{
	string exp = "5*(4+6/2)-3+20/5";


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
int CalculateResult(string exp)
{
	string::iterator it;
	stack<char> oper;
	stack<float> result;

	for (it = exp.begin(); it != exp.end(); it++)
	{
		if (*it >= '0' && *it <= '9')
		{
			result.push(*it);
		}

		if (*it == '(')    // Treat it like another operator
		{
			oper.push(*it);
		}

		 
	}

}