/*
	This is implementation for the methods for the RangeIds class.
*/

#include "stdafx.h"
#include "RangeIds.h"
#include <algorithm>


RangeIds::RangeIds()
{
	index = 0;
	Ids = new vector<short>;
}

void RangeIds::StoreValues(int index)
{
	Ids->push_back(index);
}

short RangeIds::nextId()
{
	short val = 0;
	if (index < Ids->size())
	{
		val = Ids->at(index);
		index++;
		return val;
	}
	else
	{
		return END_OF_IDS;
	}

}

void RangeIds::PrintIndexes()
{
	vector<short>::iterator it;
	for (it = Ids->begin(); it != Ids->end(); it++)
	{
		cout << "Key is " << *it << endl;
	}
}

// Sort the Ids in Acsending Order
void RangeIds::SortIds()
{
	sort(Ids->begin(),Ids->end());
}