#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Rectangle_2.h"
using namespace std;

void PrintData(Rectangle_2* tmp);
int CheckValue(int);
int main()
{
	try
	{
		system("chcp 1251");
		int width, height, n;
		cout << "\nEnter a n value: ";
		n = CheckValue(0);
		Rectangle_2* rec_1 = new Rectangle_2(n); //rec_1 is object in dynamic memory
		rec_1->SetN(n);
		for (int i = 0; i < rec_1->GetN(); i++) {
			cout << "\nEnter a width value of rectangle " << i + 1 << ": ";
			width = CheckValue(1);
			rec_1->SetWidth(i,width);
			cout << "\nEnter a height value of rectangle "<<i + 1<<": ";
			height = CheckValue(1);
			rec_1->SetHeigth(i,height);
			cout << "----------------------------------------------";
		}
		PrintData(rec_1);
		Rectangle_2 *rec_2 = new Rectangle_2(*rec_1); //rec_2 is copy of rec_1 in dynamic memory
		PrintData(rec_2);
		Rectangle_2 rec_3(*rec_1); //rec_3 is copy of rec_1 in static memory
		PrintData(&rec_3);
		Rectangle_2 rec_4(1, 11); //rec_4 is object in static memory
		PrintData(&rec_4);
		delete rec_1;
		delete rec_2;
	}
	catch (const char* message)
	{
		cout << "Error:" << message << endl;
	}
	return 0;
}
int CheckValue(int comparand) 
{
	int value;
	do
	{
		cin >> value;
		if (value < comparand && value!= 0)
		{
			cout << "\nThe value was entered incorrectly, please try again: ";
		}
		if (value == 0)
		{
			cout << "\nThe value was entered incorrectly, please try again: ";
		}
	} while (value < comparand || value==0);
	return value;
}
void PrintData(Rectangle_2* tmp) {
	for (int i = 0; i < tmp->GetN(); i++)
	{
		cout << endl << "Output data " <<i+1<<":"<<endl;
		cout << "Widht_"<< i + 1 <<" = "<< tmp->GetWidth(i) << endl;
		cout << "Widht_" << i + 1 << " = "<< tmp->GetHeight(i) << endl;
		cout << "Perimeter_"<<i+1<<" = 2*(" << tmp->GetWidth(i) << "+" << tmp->GetHeight(i) << ") = " << tmp->Perimeter(i) << endl;
		cout << "Square_"<<i+1<<" = " << tmp->GetWidth(i) << " * " << tmp->GetHeight(i) << " = " << tmp->Square(i) << endl;
	}
}
