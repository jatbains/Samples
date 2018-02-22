/* 
	This is the implementation of the methods for the EfficientRangeContainer
	class.  The methods implemented support building the AVL tree and querying 
	for the ranges from the tree.
*/

#include "stdafx.h"
#include "EfficientRangeContainer.h"
#include <iostream>
#include "AVLTree.h"
#include "KDTree.h"

using namespace std;





EfficientRangeContainer::EfficientRangeContainer(long data[],int size)
{
	kdtree = new KDTree();
	mTree = new AVLTree();

	for (int i = 0; i < size; i++)
	{
		kdtree->BuildTree( i, data[i]);
	}

	for (int i = 0; i < size; i++)
	{
		mTree->BuildTree(data[i], i);
	}

}

bool EfficientRangeContainer::CheckIfValInKD(int ind, long val)
{
	return kdtree->Search(ind, val);
}

RangeIds* EfficientRangeContainer::findIdsInRange(long fromValue,
	long toValue,
	bool fromInclusive,
	bool toInclusive)
{
	RangeIds *newRange = new RangeIds();


	mTree->FindNodesInRange(newRange, fromValue, toValue, fromInclusive, toInclusive);

	newRange->SortIds();

	return newRange;
}