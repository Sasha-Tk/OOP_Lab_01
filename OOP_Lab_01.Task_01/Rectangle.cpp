#include "Rectangle.h"

Rectangle::Rectangle() 	{
	width = 0;
	height = 0;
	cout << "\n��������� �����������_1 �����" << endl;
}
Rectangle::Rectangle(int width, int height)
{
	this->width = width;
	this->height = height;
	cout << "\n��������� �����������_2 �����" << endl;
}
Rectangle::~Rectangle()
{
	cout << "\n��������� ���������� �����" << endl;
}

int Rectangle::GetA(void)
{
	return this->width;
}

int Rectangle::GetH(void)
{
	return this->height;
}

void Rectangle::SetA(int weight)
{
	if (weight <= 0)
	{
		throw "��������� ������� �������� ������!";
	}
	this->width = weight;
}

void Rectangle::SetH(int height)
{
	if (height <= 0)
	{
		throw "��������� ������� �������� ������!";
	}
	this->height = height;
}

int Rectangle::Per(void)
{
	int per = 2 * (this->width + this->height);
	return per;
}

int Rectangle::Area(void)
{
	int area = this->width * this->height;
	return area;
}
