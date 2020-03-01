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
		cout << "\n������ �������� ������: ";
		do
		{	
			cin >> width;
			if (width <= 0)
			{
				cout << "\n��������� ������� �������� ������, �������� ������: ";
			}
		} while (width <= 0);

		rec_1.SetA(width);

		cout << "\n������ �������� ������: ";
		do
		{
			cin >> height;
			if (height <= 0)
			{
				cout << "\n��������� ������� �������� ������, �������� ������: ";
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
	cout << endl << "������ ��������: " << endl;
	cout << "������ = " << tmp.GetA() << endl;
	cout << "������ = " << tmp.GetH() << endl << endl;
	cout << "�������� = 2*(" << tmp.GetA() << "+" << tmp.GetH() << ") = " << tmp.Per() << endl;
	cout << "����� = " << tmp.GetA() << " * " << tmp.GetH() << " = " << tmp.Area() << endl;
}
