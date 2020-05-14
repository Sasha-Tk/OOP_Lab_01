#include <iostream>
#include "List.hpp"

using namespace std;

int main() {
	try {
		system("chcp 1251");
		List<int>* list_1 = new List<int>;
		List<double>* list_2 = new List<double>;
		List<char>* list_3 = new List<char>;
		List<const char*>* list_4 = new List<const char*>;

		list_1->PushBack(1);
		list_1->PushBack(2);
		list_1->PushBack(3);
		list_1->PushBack(4);
		cout << "\n--------------------------\n";
		cout << "\nList_2 in direct order:";
		list_1->PrintList(cout, 0);
		cout << "\n--------------------------\n";

		list_2->PushBack(1.1);
		list_2->PushBack(2.2);
		list_2->PushBack(3.3);
		list_2->PushBack(4.4);
		cout << "\n--------------------------\n";
		cout << "\nList_2 in reverse order:";
		list_2->PrintList(cout, 1);
		cout << "\n--------------------------\n";

		list_3->PushBack('A');
		list_3->PushBack('B');
		list_3->PushBack('C');
		list_3->PushBack('D');
		cout << "\n--------------------------\n";
		cout << "\nList_3 in direct order:";
		list_3->PrintList(cout, 0);
		cout << "\n--------------------------\n";

		list_4->PushBack("Example 1");
		list_4->PushBack("Example 2");
		list_4->PushBack("Example 3");
		list_4->PushBack("Example 4");
		cout << "\n--------------------------\n";
		cout << "\nList_4 in direct order:";
		list_4->PrintList(cout, 0);
		cout << "\n\nList_4 after reverse:";
		list_4->Reverse();
		list_4->PrintList(cout, 0);
		cout << "\n--------------------------\n";

		delete list_1;
		delete list_2;
		delete list_3;
		delete list_4;
	}
	catch(const char* error)
	{
		cout << "\nError: " << error;
	}
	return 0;
}