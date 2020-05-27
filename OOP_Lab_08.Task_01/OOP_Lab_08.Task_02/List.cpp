#pragma once
#include "List.h"
#include "SortingAlgorithm.h"


List::List()
{
	cout << "\n**Constructor of class List**";
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
	this->algorithm = nullptr;
}

List::~List()
{
	cout << "\n**Destructor of class List**";
	DeleteElements();
}

int List::GetSize() const
{
	return this->size;
}

bool List::IsEmpty() const
{
	return this->size == 0;
}

void List::DeleteElements()
{
	ListItem* del_element;
	ListItem* next_element = this->head;;
	while (!IsEmpty())
	{
		del_element = next_element;
		next_element = next_element->GetNext();
		delete del_element;
		this->size--;
	}
}
void List::Swap(ListItem*& I_1, ListItem*& I_2)
{
	int tmp = I_1->GetItem();
	I_1->SetItem(I_2->GetItem());
	I_2->SetItem(tmp);
}

void List::PushBack(int item)
{
	ListItem* new_el = new ListItem(item, nullptr, nullptr);
	if (this->size == 0)
	{
		this->head = new_el;
		this->tail = new_el;
	}
	else
	{
		new_el->SetPrevious(this->tail);
		this->tail->SetNext(new_el);
		this->tail = new_el;
	}
	this->size++;
}

void List::PushFront(int item)
{
	ListItem* new_el = new ListItem(item, nullptr, nullptr);
	if (this->size == 0)
	{
		this->head = new_el;
		this->tail = new_el;
	}
	else
	{
		new_el->SetNext(this->head);
		this->head->SetPrevious(new_el);
		this->head = new_el;
	}
	this->size++;
}

int List::PopBack()
{
	if (this->size <= 0)
	{
		throw "No elements in the list";
	}
	ListItem* ItemToDel = this->tail;
	int item_of_element = this->tail->GetItem();
	this->tail = ItemToDel->GetPrevious();
	this->tail->SetNext(nullptr);
	delete ItemToDel;
	this->size--;
	return item_of_element;
}

int List::PopFront()
{
	if (this->size <= 0)
	{
		throw "No elements in the list";
	}
	ListItem* ItemToDel = this->head;
	int item_of_element = ItemToDel->GetItem();
	this->head = ItemToDel->GetNext();
	this->head->SetPrevious(nullptr);
	delete ItemToDel;
	this->size--;
	return item_of_element;
}

int List::PeekBack() const
{
	return this->tail->GetItem();
}

int List::PeekFront() const
{
	return this->head->GetItem();
}

void List::Reverse()
{
	ListItem* I_1 = this->head, * I_2 = this->tail;
	int n = this->size / 2;
	for (int k = 0; k < n; k++)
	{
		Swap(I_1, I_2);
		I_1 = I_1->GetNext();
		I_2 = I_2->GetPrevious();
	}
}

void List::PrintList(ostream& out, bool reverse_mode) const
{
	if (true == reverse_mode)
	{
		ListItem* ItemToPrint = this->tail;
		while (ItemToPrint != nullptr)
		{
			out << "\nValue:\t" << ItemToPrint->GetItem();
			ItemToPrint = ItemToPrint->GetPrevious();
		}
	}
	else
	{
		ListItem* ItemToPrint = this->head;
		while (ItemToPrint != nullptr)
		{
			out << "\nValue:\t" << ItemToPrint->GetItem();
			ItemToPrint = ItemToPrint->GetNext();
		}
	}
}

void List::SetSortAlgorithm(SortingAlgorithm* algorithm)
{
	this->algorithm = algorithm;
}

void List::Sort()
{
	this->algorithm->ToSort(this->head, this->tail);
}

