#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ListItem.h"


using namespace std;

class SortingAlgorithm;

class List
{
private:
	ListItem* head;
	ListItem* tail;
	int size;
	SortingAlgorithm* algorithm;

	void DeleteElements();
public:
	List();
	~List();
	int GetSize()const;
	bool IsEmpty() const;
	void PushBack(int item);
	void PushFront(int item);
	int PopBack();
	int PopFront();
	int PeekBack() const;
	int PeekFront() const;
	void Reverse();
	void PrintList(ostream& out, bool reverse_mode) const;
	void SetSortAlgorithm(SortingAlgorithm* algorithm);
	void Sort();
	static void Swap(ListItem*& I_1, ListItem*& I_2);
};