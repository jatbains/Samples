#pragma once

/*
	The module implements the RangeContainer defined in the Interface
	module
*/
#include "stdafx.h"
#include "Interfaces.h"
#include "RangeIds.h"
#include "AVLTree.h"

class EfficientRangeContainer : public RangeContainer
{
	AVLTree *mTree;

public:
	EfficientRangeContainer(long data[],int size);
	virtual RangeIds* findIdsInRange(long fromValue,
		long toValue,
		bool fromInclusive,
		bool toInclusive);
};
