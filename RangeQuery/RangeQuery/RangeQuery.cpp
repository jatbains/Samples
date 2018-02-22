/*		
	RangeQuery.cpp : Defines the entry point for the console application.
	This will be used to verify the functionality of the Developed
	Classes.
*/

#include "stdafx.h"
#include "Interfaces.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "RangeIds.h"
#include "EfficientRangeContainerFactory.h"
#include "EfficientRangeContainer.h"

using namespace std;
void runARangeQuery(RangeContainer *rc, long fromVal, long toVal, bool fromIncl, bool toIncl);
void FindValInKD(RangeContainer *rc, int ind, long val);

int main()
{
	RangeIds *myids = new RangeIds();
	list<int> myIds;
	RangeContainer *rc;
	long data[] = { 10, 12, 17, 21, 2, 15, 16 };
	int size = sizeof(data) / sizeof(data[0]);

	EfficientRangeContainerFactory *rangeFactory = new EfficientRangeContainerFactory();
	
	rc = rangeFactory->createContainer(data,size);


	// Run a query on it
	runARangeQuery(rc, 14, 17, true, true);
	runARangeQuery(rc, 14, 17, true, false);
	runARangeQuery(rc, 20, LONG_MAX, false, true);

	FindValInKD(rc,3, 21);
	system("pause");
    return 0;
}

void FindValInKD(RangeContainer *rc, int ind, long val)
{
	cout << "Looking for Value in KD Tree" << endl;
	cout << (rc->CheckIfValInKD(ind, val) ? "Value Found" : "Value Not Found") << endl;
}

void runARangeQuery(RangeContainer *rc,long fromVal, long toVal, bool fromIncl, bool toIncl)
{
	Ids *ids = rc->findIdsInRange(fromVal, toVal, fromIncl, toIncl);
	
	short id = ids->nextId();
	do {
		cout << "Index is " << id << endl;
		id = ids->nextId();
	} while (id != -1);
	cout << "Index is " << id << endl;

	cout << endl;
}