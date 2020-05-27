#include "InsertionSort.h"

void InsertionSort::ToSort(ListItem* begin, ListItem* end)
{
	ListItem* ptr_1;
	ListItem* ptr_2;

	for (ptr_1 = begin; ptr_1 != nullptr; ptr_1 = ptr_1->GetNext())
	{
		for (ptr_2 = ptr_1; ptr_2 != begin; ptr_2 = ptr_2->GetPrevious())
		{
			ListItem* current = ptr_2;
			ListItem* previous = ptr_2->GetPrevious();

			if (previous->GetItem() > current->GetItem())
			{
				List::Swap(current, previous);
			}
		}
	}
}