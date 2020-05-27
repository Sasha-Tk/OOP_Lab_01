#include <iostream>
#include "List.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
using namespace std;

int main() {
	try {
		List a;
		a.PushBack(2);
		a.PushBack(4);
		a.PushBack(6);
		a.PushBack(-10);
		a.PushBack(1);
		cout << "\n\nList_1 before sorting:\n";
		a.PrintList(cout, 0);

		InsertionSort* Insertion = new InsertionSort;
		a.SetSortAlgorithm(Insertion);
		a.Sort();
		cout << "\n\nList_1 after sorting by insertion:\n";
		a.PrintList(cout, 0);

		List b;
		b.PushBack(6);
		b.PushBack(-9);
		b.PushBack(7);
		b.PushBack(11);
		b.PushBack(-14);
		cout << "\n\nList_2 before sorting:\n";
		b.PrintList(cout, 0);

		BubbleSort* bubble = new BubbleSort;

		b.SetSortAlgorithm(bubble);
		b.Sort();
		cout << "\n\nList_2 after sorting by bubble sorting:\n";
		b.PrintList(cout, 0);
	}
	catch(const char* error)
	{
		cout << "\nError: " << error;
	}
	return 0;
}