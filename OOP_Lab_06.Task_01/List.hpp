#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ListItem.hpp"

using namespace std;

template <typename T> class List
{
private:
	ListItem<T>* head;
	ListItem<T>* tail;
	int size;
	void DeleteElements();
	static void Swap(ListItem<T>*& I_1, ListItem<T>*& I_2);
public:
	List();
	~List();
	int GetSize()const;
	bool IsEmpty() const;
	void PushBack(T item);
	void PushFront(T item);
	T PopBack();
	T PopFront();
	T PeekBack() const;
	T PeekFront() const;
	void Reverse();
	void PrintList(ostream& out, bool reverse_mode) const;
};

template <typename T>List<T>::List()
{
	cout << "\n**Constructor of class ListItem**";
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template <typename T>List<T>::~List()
{
	cout << "\n**Destructor of class ListItem**";
	DeleteElements();
}

template<typename T> int List<T>::GetSize() const
{
	return this->size;
}

template<typename T> bool List<T>::IsEmpty() const
{
	return this->size == 0;
}

template<typename T> void List<T>::DeleteElements()
{
	ListItem<T>* del_element;
	ListItem<T>* next_element = this->head;;
	while (!IsEmpty())
	{
		del_element = next_element;
		next_element = next_element->GetNext();
		delete del_element;
		this->size--;
	}
}

template<typename T> void List<T>::Swap(ListItem<T>*& I_1, ListItem<T>*& I_2)
{
	T tmp = I_1->GetItem();
	I_1->SetItem(I_2->GetItem());
	I_2->SetItem(tmp);
}

template<typename T> void List<T>::PushBack(T item)
{
	ListItem<T>* new_el = new ListItem<T>(item, nullptr, nullptr);
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

template<typename T> void List<T>::PushFront(T item)
{
	ListItem<T>* new_el = new ListItem<T>(item, nullptr, nullptr);
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

template<typename T> T List<T>::PopBack()
{
	if (this->size <= 0)
	{
		throw "No elements in the list";
	}
	ListItem<T>* ItemToDel = this->tail;
	T item_of_element = this->tail->GetItem();
	this->tail = ItemToDel->GetPrevious();
	this->tail->SetNext(nullptr);
	delete ItemToDel;
	this->size--;
	return item_of_element;
}

template<typename T> T List<T>::PopFront()
{
	if (this->size <= 0)
	{
		throw "No elements in the list";
	}
	ListItem<T>* ItemToDel = this->head;
	T item_of_element = ItemToDel->GetItem();
	this->head = ItemToDel->GetNext();
	this->head->SetPrevious(nullptr);
	delete ItemToDel;
	this->size--;
	return item_of_element;
}

template<typename T> T List<T>::PeekBack() const
{
	return this->tail;
}

template<typename T> T List<T>::PeekFront() const
{
	return this->head;
}

template<typename T> void List<T>::Reverse()
{
	ListItem<T>* I_1 = this->head, * I_2 = this->tail;
	int n = this->size / 2;
	for (int k = 0; k < n; k++)
	{
		Swap(I_1, I_2);
		I_1 = I_1->GetNext();
		I_2 = I_2->GetPrevious();
	}
}

template<typename T> void List<T>::PrintList(ostream& out, bool reverse_mode) const
{
	if (true == reverse_mode)
	{
		ListItem<T>* ItemToPrint = this->tail;
		while (ItemToPrint != nullptr)
		{
			out << "\nValue:\t" << ItemToPrint->GetItem();
			ItemToPrint = ItemToPrint->GetPrevious();
		}
	}
	else
	{
		ListItem<T>* ItemToPrint = this->head;
		while (ItemToPrint != nullptr)
		{
			out << "\nValue:\t" << ItemToPrint->GetItem();
			ItemToPrint = ItemToPrint->GetNext();
		}
	}
}
