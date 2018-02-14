// MakeHeapVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct comparator {
	bool operator()(int i, int j) {
		return i > j;
	}
};

int main()
{
	vector<int> data = { 5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4 };
	vector<int> input = { 0 };
	priority_queue<int, std::vector<int>, comparator> minHeap;
	make_heap(input.begin(), input.end());

	vector<int>::iterator it;

	for (it = data.begin(); it != data.end(); it++)
	{
		input.push_back(*it);
		make_heap(input.begin(), input.end());
		minHeap.push(*it);
		cout << input.front() << endl;
		cout << minHeap.top() << endl;
		cout << (input.front()+minHeap.top())/2 << endl;
	}

	//for (it = data.begin(); it != data.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	system("pause");
    return 0;
}

