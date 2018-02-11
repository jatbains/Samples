/*
	This module implements the methods for the EfficientRangContainerFactory
*/


#include "stdafx.h"
#include "EfficientRangeContainerFactory.h"
#include "EfficientRangeContainer.h"

EfficientRangeContainerFactory::EfficientRangeContainerFactory()
{}

EfficientRangeContainer * EfficientRangeContainerFactory::createContainer(long data[],int size)
{
	EfficientRangeContainer * newContainer = new EfficientRangeContainer(data, size);
	isContainerInstantiated = true;
	return newContainer;
}