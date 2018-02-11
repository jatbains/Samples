#pragma once

/*
	This module implements the interface for the RangeContainerFactory
	defined in the Interface module
*/

#include "stdafx.h"
#include "Interfaces.h"
#include "EfficientRangeContainer.h"

class EfficientRangeContainerFactory : public RangeContainerFactory
{
	bool isContainerInstantiated = false;
public:
	EfficientRangeContainerFactory();
	EfficientRangeContainer * createContainer(long data[],int size);
};
