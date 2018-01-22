// minOperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <set>

using namespace std;

// We have two operations increment or decrement by 1
// Maintain a queue for BFS to turn x into y

typedef struct node
{
	int val;
	int level;
}node;

int minOperations(int x, int y);


int main()
{
	int x = 6;
	int y = 21;
	int level = 0;

	level = minOperations(6, 21);

	cout << "Level is " << level << endl;

	system("pause");
    return 0;
}

int minOperations(int x, int y)
{
	node n = { x,0 };

	// Create a queue and visited array
	queue<node> dfsQ;
	set<int> visited;

	// Push first node into queue
	dfsQ.push(n);

	//  In a loop check values as long as 1<= x <= 10000
	while (!dfsQ.empty())
	{
		cout << "Queue size " << dfsQ.size() << endl;
		node t = dfsQ.front();   // Get front element
		dfsQ.pop();              // Pop off front element

		// Check the value
		if (t.val == y)
			return t.level;

		// Update visit list
		visited.insert(t.val);

		// Chec if we can reach in one step
		if (t.val + 1 == y || t.val - 1 == y)
			return t.level + 1;

		// Update and add to queue  check for not found
		if (t.val <= 10000 && visited.find(t.val + 1) == visited.end())
		{
			n.val = t.val + 1;
			n.level = t.level + 1;
	
			dfsQ.push(n);     // creates a copy of the class
		}

		if (t.val > 0 && visited.find(t.val - 1) == visited.end())
		{

			n.val = t.val - 1;
			n.level = t.level + 1;
	
			dfsQ.push(n);
		}


	}


}
