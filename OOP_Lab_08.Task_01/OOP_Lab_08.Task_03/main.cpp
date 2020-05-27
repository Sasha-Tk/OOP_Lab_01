#include <iostream>
#include "List.hpp"
#include <list>

using namespace std;

int main() 
{
	try
	{
		List <int> a;
		a.PushBack(1);
		a.PushBack(2);
		a.PushBack(3);
		a.PushBack(4);


		cout << "\nList in direct order:";
		for (auto iter = a.GetBegin(); iter != a.GetEnd(); iter++)
		{
			cout << "\n\t" << *iter;
		}


		cout << "\nList in reverse order:";
		for (auto iter = a.GetRbegin(); iter != a.GetRend(); iter--)
		{
			cout << "\n\t" << *iter;
		}
	}


	catch (const char* error)
	{
		cout << "\nError: " << error;
	}
	return 0;
}