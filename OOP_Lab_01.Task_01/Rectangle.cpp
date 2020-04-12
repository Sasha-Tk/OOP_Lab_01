#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle_2::Rectangle_2() 	{
	width = 0;
	height = 0;
	cout << "\nConstructor_1" << endl;
}
Rectangle_2::Rectangle_2(int width, int height)
{
	this->width = width;
	this->height = height;
	cout << "\nConstructor_2" << endl;
}
Rectangle_2::~Rectangle_2()
{
	cout << "\nDestructor" << endl;
}

Rectangle_2::Rectangle_2(const Rectangle_2& copy_source)
{
	cout << "\nConstructor copy" << endl;
	this->width = copy_source.width;
	this->height = copy_source.height;
}

int Rectangle_2::GetWidth()
{
	return this->width;
}

int Rectangle_2::GetHeight()
{
	return this->height;
}

void Rectangle_2::SetWidth(int weight)
{
	if (weight <= 0)
	{
		throw "The width value was entered incorrectly!";
	}
	this->width = weight;
}

void Rectangle_2::SetHeigth(int height)
{
	if (height <= 0)
	{
		throw "The height value was entered incorrectly!";
	}
	this->height = height;
}

int Rectangle_2::Perimeter()
{
	int per = 2 * (this->width + this->height);
	return per;
}

int Rectangle_2::Square()
{
	int area = this->width * this->height;
	return area;
}
