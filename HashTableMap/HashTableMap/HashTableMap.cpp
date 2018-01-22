// HashTableMap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
	map<int,string> myMap;
	unordered_set<string> myHash;

	unordered_map<int, string> myUnMap;

	string people[]={"Bob","Joe","George","Tom","Dave"};
	int size = sizeof(people) / sizeof(people[0]);

	for (int i = 0; i < size; i++)
	{
		
		myMap[i] = people[i];
		myHash.insert(people[i]);
		
		myUnMap[i] = people[i];
	}

	for (int i = 0; i < size; i++)
	{
		cout << myMap[i].c_str() << endl;
		
		cout << myUnMap[i].c_str() << endl;
	}
	cout << endl;

	unordered_set<string>::iterator it;

	for (it = myHash.begin(); it != myHash.end();it++)
	{
		cout << *it << endl;
	}
	

	system("pause");
    return 0;
}

