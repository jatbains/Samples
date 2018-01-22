// Heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class Heap
{
	int *data;
	int size;
	int capacity;

public:
	Heap(int totalSize)
	{
		capacity = totalSize;
		data = new int[capacity];
		size = 0;
	}

	void MinHeapify(int i);

	int parent(int index) { return (index - 1) / 2; }

	int leftChild(int index) { return (2 * index + 1); }

	int rightChild(int index) { return (2 * index + 2); }

	int extractMin(void);

	void decreaseKey(int i);

	int getMin(void) { return data[0]; }

	void deleteKey(int i);

	void insertKey(int k);
};


int main()
{




	system("pause");
    return 0;
}

