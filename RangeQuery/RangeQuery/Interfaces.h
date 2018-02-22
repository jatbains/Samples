#pragma once
/**
   The Interfaces for the Project
**/
#include <list>

using namespace std;

class Ids
{
public:
	static const short END_OF_IDS = -1;

	virtual short nextId() = 0;
};

class RangeContainer 
{
public:
	virtual bool CheckIfValInKD(int ind, long val) = 0;
	virtual Ids* findIdsInRange(long fromValue,
		long toValue,
		bool fromInclusive,
		bool toInclusive) = 0;
};

class RangeContainerFactory
{
	virtual RangeContainer* createContainer(long data[],int size) = 0;
};
