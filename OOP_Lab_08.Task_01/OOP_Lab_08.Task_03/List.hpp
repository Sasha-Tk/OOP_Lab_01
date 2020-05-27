#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ListItem.hpp"
#include "ListIterator.hpp"

using namespace std;
template <typename T> class ListIterator;
template <typename T> class List
{
private:
	ListItem<T>* head;
	ListItem<T>* tail;
	int size;
	void DeleteElements();
	
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

	ListIterator<T> GetBegin();
	ListIterator<T> GetEnd();
	ListIterator<T> GetRbegin();
	ListIterator<T> GetRend();
};

template <typename T>List<T>::List()
{
	cout << "\n**Constructor of class List**";
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

template <typename T>List<T>::~List()
{
	cout << "\n**Destructor of class List**";
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
	return this->tail->GetItem();
}

template<typename T> T List<T>::PeekFront() const
{
	return this->head->GetItem();
}

template<typename T> ListIterator<T> List<T>::GetBegin()
{
	ListIterator<T> iter_b(this, this->head);
	return iter_b;
}

template<typename T> ListIterator<T> List<T>::GetEnd()
{
	ListIterator<T> iter_e(this, nullptr);
	return iter_e;
}

template<typename T> ListIterator<T> List<T>::GetRbegin()
{
	ListIterator<T> iter_rb(this, this->tail);
	return iter_rb;
}

template<typename T> ListIterator<T> List<T>::GetRend()
{
	ListIterator<T> iter_re(this, nullptr);
	return iter_re;
}