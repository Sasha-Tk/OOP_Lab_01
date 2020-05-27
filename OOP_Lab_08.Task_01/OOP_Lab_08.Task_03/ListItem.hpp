#pragma once

#include <iostream>

using namespace std;

template <typename T> class ListItem
{
private:
	T item;
	ListItem<T>* previous;
	ListItem<T>* next;
public:
	ListItem(T item, ListItem<T>* previous, ListItem<T>* next);
	~ListItem();

	ListItem<T>* GetPrevious() const;
	ListItem<T>* GetNext() const;

	const T GetItem() const;
	T& GetItemForIterator();
	 
	
	void SetItem(const T item);
	void SetPrevious(ListItem<T>* previous);
	void SetNext(ListItem<T>* next);
};

template<typename T> ListItem<T>::ListItem(T item, ListItem<T>* previous, ListItem<T>* next)
{
	cout << "\n**Constructor of class ListItem**";
	this->item = item;
	this->previous = previous;
	this->next = next;
}

template<typename T> ListItem<T>::~ListItem()
{
	cout << "\n**Destructor of class ListItem**";
}

template<typename T> const T ListItem<T>::GetItem() const
{
	return this->item;
}

template<typename T> T& ListItem<T>::GetItemForIterator()
{
	return this->item;
}

template<typename T> ListItem<T>* ListItem<T>::GetPrevious() const
{
	return this->previous;
}

template<typename T> ListItem<T>* ListItem<T>::GetNext() const
{
	return this->next;
}

template<typename T> void ListItem<T>::SetItem(const T item)
{
	this->item = item;
}

template<typename T> void ListItem<T>::SetNext(ListItem<T>* next)
{
	this->next = next;
}

template<typename T> void ListItem<T>::SetPrevious(ListItem<T>* previous)
{
	this->previous = previous;
}