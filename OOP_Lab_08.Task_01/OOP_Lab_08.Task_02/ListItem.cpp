#pragma once
#include "ListItem.h"

ListItem::ListItem(int item, ListItem* previous, ListItem* next)
{
	cout << "\n**Constructor of class ListItem**";
	this->item = item;
	this->previous = previous;
	this->next = next;
}

ListItem::~ListItem()
{
	cout << "\n**Destructor of class ListItem**";
}

const int ListItem::GetItem() const
{
	return this->item;
}

ListItem* ListItem::GetPrevious() const
{
	return this->previous;
}
ListItem* ListItem::GetNext() const
{
	return this->next;
}

void ListItem::SetItem(const int item)
{
	this->item = item;
}

void ListItem::SetNext(ListItem* next)
{
	this->next = next;
}

void ListItem::SetPrevious(ListItem* previous)
{
	this->previous = previous;
}