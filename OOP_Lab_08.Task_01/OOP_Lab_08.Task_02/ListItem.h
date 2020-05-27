#pragma once
#include <iostream>

using namespace std;

class ListItem
{
private:
	int item;
	ListItem* previous;
	ListItem* next;
public:
	ListItem(int item, ListItem* previous, ListItem* next);
	~ListItem();

	const int GetItem() const;
	ListItem* GetPrevious() const;
	ListItem* GetNext() const;
	void SetItem(const int item);
	void SetPrevious(ListItem* previous);
	void SetNext(ListItem* next);
};