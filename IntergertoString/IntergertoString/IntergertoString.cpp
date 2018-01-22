// IntergertoString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef enum Style
{
	English,
	Indian
}Style;

string IntToString(int num, Style intStyle);
map<Style, vector<int>> style_map;


int main()
{
	int num = 0;
	cout << "Enter a number " << endl;
	cin >> num;

	style_map[English] = { 3, 6, 9, 12, 15 };
	style_map[Indian] = { 3, 5, 7, 9, 11, 13 };

	cout << "The Number is " << IntToString(num, English) << endl;

	system("pause");
    return 0;
}

string IntToString(int num,Style intStyle)
{
	string numStr = "";
	int count = 0;
	vector<int> vecStyle = style_map[intStyle];
	int n = vecStyle.size();
	int x = 0;

	while (num > 0)
	{
		if (count == vecStyle[x])
		{
			numStr += ",";      // count 
			x++;
			continue;
		}
		
		numStr += (char)((num % 10) + '0');
		count++;
		num /= 10;
	}

	reverse(numStr.begin(), numStr.end());
	return numStr;
}
