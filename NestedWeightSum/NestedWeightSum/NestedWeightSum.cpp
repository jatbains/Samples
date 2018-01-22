// NestedWeightSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int FindNextSum(string list);

int main()
{
	//int data[] = { { 1,1 },2,{ 1,1 } };
	string nestList = "{{1,1},2,{1,1}}";


	cout << "The Nested Weighted Sum is " << FindNextSum(nestList) << endl;

	system("pause");
    return 0;
}

int FindNextSum(string list)
{
	stack<int> val;
	int x = 0, y = 0;
	int res = 0;
	int depth = 0;
	int len = list.length();

	// process the string
	for (int i = 0; i != list.length(); i++)
	{
		if (list[i] == '{')
		{
			//  Increment depth
			depth++;
		}
		if (list[i] == '}')
		{
			depth--;
		}
		if (list[i] == ',')
		{
			// Pop two values add and multiply by weight decrement weight and push result
			x = val.top();
			val.pop();
			i++;
			if (list[i] - '0' > 0 && list[i] - '0' < 9)
			{
				y = list[i] - '0';
				res = (x + y)*depth;
				val.push(res);
				continue;
			}
			else
			{
				val.push(x);
				i--;
			}

		}

		if (list[i]-'0' > 0 && list[i]-'0' < 9)
		{
			val.push(list[i]-'0');
		}

	}

	// The result will be at the top of the stack
	res = 0;
	while (!val.empty())
	{
		res += val.top();
		val.pop();
	}
	return res;
}
