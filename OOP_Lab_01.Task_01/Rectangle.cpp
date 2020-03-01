#include "Rectangle.h"

Rectangle::Rectangle() 	{
	width = 0;
	height = 0;
	cout << "\nСпрацював конструктор_1 класу" << endl;
}
Rectangle::Rectangle(int width, int height)
{
	this->width = width;
	this->height = height;
	cout << "\nСпрацював конструктор_2 класу" << endl;
}
Rectangle::~Rectangle()
{
	cout << "\nСпрацював деструктор класу" << endl;
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
		throw "Помилково введено значення ширини!";
	}
	this->width = weight;
}

void Rectangle::SetH(int height)
{
	if (height <= 0)
	{
		throw "Помилково введено значення висоти!";
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
