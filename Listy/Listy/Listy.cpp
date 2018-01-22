// Listy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

int const static MAX_SIZE = 10;

class Listy
{
	int size;
	int index;
	int data[MAX_SIZE];

public:
	Listy();
	int elementAt(int x);
	void setData(int val[]);
	int BinarySearch(int lv, int rv,int x);

};

int Listy::BinarySearch( int lv, int rv,int x)
{
	if (lv > rv)
		return -1;  // not foumd

	// Check for x
	// Calculate mid point
	int mid = (lv + rv) / 2;

	if (x == data[mid])
		return mid;

	if ( x<data[mid] )
	{
		BinarySearch(lv, mid,x);
	}
	else
	{
		BinarySearch(mid, rv, x);
	}

}

Listy::Listy()
{
	size = MAX_SIZE;
	index = 0;
}

int Listy::elementAt(int x)
{

	if (x > MAX_SIZE)
		return -1;
	else
		return data[x];

}

void Listy::setData(int val[])
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		data[i] = val[i];
	}

}



int main()
{
	int data[MAX_SIZE] = { 3,5,8,12,14,17,23,27,32,43 };
	Listy list;

	list.setData(data);

	// Since it is sorted we can do a binary search

	cout << "Position of element is " << list.BinarySearch(0, MAX_SIZE - 1, 12) << endl;



	system("pause");
    return 0;
}

