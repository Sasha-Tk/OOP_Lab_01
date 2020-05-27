#pragma once
#include  "List.hpp"

template <typename T> class List;

template <typename T> class ListIterator
{
private:
	List<T>* list;
	ListItem<T>* element;
public:
	ListIterator();
	ListIterator(List<T>* list, ListItem<T>* element);
	~ListIterator();
	ListIterator<T>& operator=(const ListIterator<T> iterator);
	ListIterator<T>& operator++();
	ListIterator<T>& operator--();
	ListIterator<T>& operator++(int);
	ListIterator<T>& operator--(int);
	bool operator!=( const ListIterator<T> other);
	bool operator==(const ListIterator<T> other);
	T& operator*();
};

template<typename T>  ListIterator<T>::ListIterator()
{
	this->list = nullptr;
	this->element = nullptr;
}

template<typename T> ListIterator<T>::ListIterator(List<T>* list, ListItem<T>* element)
{
	this->list = list;
	this->element = element;
}

template<typename T> ListIterator<T>::~ListIterator()
{

}

template<typename T> ListIterator<T>& ListIterator<T>::operator=(const ListIterator<T> iterator)
{
	this->element = iterator.element;
	this->list = iterator.list;
}

template<typename T> ListIterator<T>& ListIterator<T>::operator++()
{
	if (nullptr == this->elemen)
	{
		throw "no more elements in the list!";
	}
	this->element = this->element->GetNext();
	return *this;
}

template<typename T> ListIterator<T>& ListIterator<T>::operator++(int)
{
	if (nullptr == this->element)
	{
		throw "no more elements in the list!";
	}
	this->element = this->element->GetNext();
	return *this;
}

template<typename T> ListIterator<T>& ListIterator<T>::operator--()
{
	if (nullptr == this->element)
	{
		throw "you are off the list!";
	}
	this->element = this->element->GetPrevious();
	return *this;
}

template<typename T> ListIterator<T>& ListIterator<T>::operator--(int)
{
	if (nullptr == this->element)
	{
		throw "you are off the list!";
	}
	this->element = this->element->GetPrevious();
	return *this;
}

template<typename T> bool ListIterator<T>::operator!=(const ListIterator<T> other)
{
	return this->element!=other.element;
}

template<typename T> bool ListIterator<T>::operator==(const ListIterator<T> other)
{
	return this->element == other.element;
}

template<typename T> T& ListIterator<T>::operator*()
{
	return this->element->GetItemForIterator();
}
