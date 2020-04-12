#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Rectangle.h"
using namespace std;

void PrintData(Rectangle_2& tmp); 
	
int main()
{
	try
	{
		int width, height;
		system("chcp 1251");
		Rectangle_2 rec_1;
		cout << "\nEnter a width value: ";
		do
		{	
			cin >> width;
			if (width <= 0)
			{
				cout << "\nThe width value was entered incorrectly, please try again: ";
			}
		} while (width <= 0);

		rec_1.SetWidth(width);

		cout << "\nEnter a height value: ";
		do
		{
			cin >> height;
			if (height <= 0)
			{
				cout << "\nThe height value was entered incorrectly, please try again: ";
			}
		} while (height <= 0);

		rec_1.SetHeigth(height);
		PrintData(rec_1);
		Rectangle_2 rec_2(rec_1);
		PrintData(rec_2);
	}
	catch (const char* message)
	{
		cout << "Error:" << message << endl;
	}
	return 0;
}
void PrintData(Rectangle_2& tmp) {
	cout << endl << "Output data: " << endl;
	cout << "Widht = " << tmp.GetWidth() << endl;
	cout << "Height = " << tmp.GetHeight() << endl;
	cout << "Perimeter = 2*(" << tmp.GetWidth() << "+" << tmp.GetHeight() << ") = " << tmp.Perimeter() << endl;
	cout << "Square = " << tmp.GetWidth() << " * " << tmp.GetHeight() << " = " << tmp.Square() << endl;
}
