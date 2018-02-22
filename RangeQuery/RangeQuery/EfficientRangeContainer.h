#pragma once

/*
	The module implements the RangeContainer defined in the Interface
	module
*/
#include "stdafx.h"
#include "Interfaces.h"
#include "RangeIds.h"
#include "AVLTree.h"
#include "KDTree.h"

class EfficientRangeContainer : public RangeContainer
{
	AVLTree *mTree;
	KDTree *kdtree;

public:
	EfficientRangeContainer(long data[],int size);
	bool CheckIfValInKD(int ind, long val);
	RangeIds* findIdsInRange(long fromValue,
		long toValue,
		bool fromInclusive,
		bool toInclusive);
};
