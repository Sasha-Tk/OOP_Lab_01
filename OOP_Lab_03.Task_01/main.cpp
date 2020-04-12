#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "Rectangle_3.h"
#define N 3

using namespace std;

int Sort(Rectangle* arr, int k);
bool CheckValue(Rectangle* arr, int k, double value);

int main()
{
	try
	{
		int width, height, value;
		Rectangle arr[N];
		for (int i = 0; i < N; i++)
		{
			cout << "\nEnter a width value for rectangle " << i + 1 << ": ";
			do
			{
				cin >> width;
				if (width <= 0)
				{
					cout << "\nThe width value was entered incorrectly, please try again: ";
				}
			} while (width <= 0);
			arr[i].SetWidth(width);
			cout << "\nEnter a height value for rectangle " << i + 1 << ": ";
			do
			{
				cin >> height;
				if (height <= 0)
				{
					cout << "\nThe height value was entered incorrectly, please try again: ";
				}
			} while (height <= 0);
			arr[i].SetHeigth(height);
			cout << "---------------------------------------------";
		}
		cout << "\n\n**********Before sorting**********\n\n";
		for (int i = 0; i < N; i++)
		{
			cout << arr[i];
		}
		cout << "\n\n***********After sorting***********\n\n";
		Sort(arr, N);
		for (int i = 0; i < N; i++)
		{
			cout << arr[i];
		}
		do
		{
			cout << "\nEnter the value to reduce each side: ";
			cin >> value;
			if (CheckValue(arr, N, value))
				cout << "\nThe value was entered incorrectly, please try again: ";
		} while (CheckValue(arr, N, value));
		for (int i = 0; i < N; i++)
		{
			arr[i] -= value;
		}
		if (Sort(arr, N) > 0)
			cout << "\n\nAfter changing the height and width values, the array of rectangles remains orderly\n\n";
		else cout << "\n\nAfter changing the height and width values, the array of rectangles did not remain ordered\n\n";
	}
	catch (const char* message)
	{
		cout << "Error: " << message << endl;
	}
	return 0;
}

int Sort(Rectangle* arr, int k)
{
	Rectangle* p = arr;
	int c = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = i; j > 0 && p[j - 1] > p[j]; j--, c++)
		{
			swap(p[j - 1], p[j]);
		}
	}
	return c;
}

bool CheckValue(Rectangle* arr, int k, double value)
{
	if (value <= 0)
		return true;
	for (int i = 0; i < k; i++)
	{
		if (value >= arr->GetHeight() || value >= arr->GetWidth())
			return true;
	}
	return false;
}
