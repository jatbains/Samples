// ValidParenthesis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool CheckParentheses(char *st, int size);


int main()
{
	
	char exp[] = { '{','[','8',']','}','[','9',']' };
	int size = sizeof(exp) / sizeof(exp[0]);
	
	// Push the parentheses onto the char stack
	// disregard the numbers and 
	//  Push a left parentheses and pop a right parentheses if not the same then fail 

	cout << (CheckParentheses(exp, size) ? "Parentheses Matched" : "Parentheses Not matched") << endl << endl;

	system("pause");
    return 0;
}

bool CheckParentheses(char *st,int size)
{
	stack<char> stk;
	char brack;
	for (int i = 0; i < size; i++)
	{
		if (st[i] == '[' || st[i] == '{' || st[i] == '(')
		{
			stk.push(st[i]);
		}
		if (st[i] == ']' || st[i] == '}' || st[i] == ')')
		{
			brack = stk.top();
			switch (st[i])
			{
			case ']':
				if (brack != '[')
				{
					return false;
				}
				else
				{
					// pop it off
					stk.pop();
				}
				break;
			case '}':
				if (brack != '{')
				{
					return false;
				}
				else
				{
					stk.pop();
				}
				break;
			case ')':
				if (brack != '(')
				{
					return false;
				}
				else
				{
					stk.pop();
				}
				break;
			default:
				cout << "Invalid Bracket" << endl;
				break;
			}
		}
	}

	return true;

}
