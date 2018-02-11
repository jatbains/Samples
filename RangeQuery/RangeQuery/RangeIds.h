#pragma once

/*
	This module implements the Ids interface defined in the interface
	module
*/


#include "Interfaces.h"
#include <list>
#include <iostream>
#include <vector>

using namespace std;

class RangeIds : public Ids
{
	vector<short> *Ids;
	int index;
public:
	RangeIds();
	short nextId();
	void StoreValues(int index);
	void SortIds();
	void PrintIndexes();
};
