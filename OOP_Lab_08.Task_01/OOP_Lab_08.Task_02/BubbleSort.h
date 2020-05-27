#pragma once
#include "SortingAlgorithm.h"
class BubbleSort :
	public SortingAlgorithm
{
	void ToSort(ListItem* begin, ListItem* end) override;
};