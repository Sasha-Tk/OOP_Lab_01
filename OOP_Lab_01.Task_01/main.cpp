#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Rectangle.h"
using namespace std;

void PrintData(Rectangle& tmp); 
	
int main()
{
	try
	{
		int width, height;
		system("chcp 1251");
		Rectangle rec_1;
		cout << "\nВведіть значення ширини: ";
		do
		{	
			cin >> width;
			if (width <= 0)
			{
				cout << "\nПомилково введено значення ширини, повторіть спробу: ";
			}
		} while (width <= 0);

		rec_1.SetA(width);

		cout << "\nВведіть значення висоти: ";
		do
		{
			cin >> height;
			if (height <= 0)
			{
				cout << "\nПомилково введено значення висоти, повторіть спробу: ";
			}
		} while (height <= 0);

		rec_1.SetH(height);
		PrintData(rec_1);
	}
	catch (const char* message)
	{
		cout << "Error:" << message << endl;
	}
	return 0;
}
void PrintData(Rectangle& tmp) {
	cout << endl << "Введені значення: " << endl;
	cout << "ширина = " << tmp.GetA() << endl;
	cout << "висота = " << tmp.GetH() << endl << endl;
	cout << "Периметр = 2*(" << tmp.GetA() << "+" << tmp.GetH() << ") = " << tmp.Per() << endl;
	cout << "Площа = " << tmp.GetA() << " * " << tmp.GetH() << " = " << tmp.Area() << endl;
}
