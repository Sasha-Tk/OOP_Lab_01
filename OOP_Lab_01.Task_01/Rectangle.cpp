#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle() 	{
	width = 0;
	height = 0;
	cout << "\nConstructor_1" << endl;
}
Rectangle::Rectangle(int width, int height)
{
	this->width = width;
	this->height = height;
	cout << "\nConstructor_2" << endl;
}
Rectangle::~Rectangle()
{
	cout << "\nDestructor" << endl;
}

Rectangle::Rectangle(const Rectangle& copy_source)
{
	cout << "\nConstructor copy" << endl;
	this->width = copy_source.width;
	this->height = copy_source.height;
}

int Rectangle::GetWidth()
{
	return this->width;
}

int Rectangle::GetHeight()
{
	return this->height;
}

void Rectangle::SetWidth(int weight)
{
	if (weight <= 0)
	{
		throw "The width value was entered incorrectly!";
	}
	this->width = weight;
}

void Rectangle::SetHeigth(int height)
{
	if (height <= 0)
	{
		throw "The height value was entered incorrectly!";
	}
	this->height = height;
}

int Rectangle::Perimeter()
{
	int per = 2 * (this->width + this->height);
	return per;
}

int Rectangle::Square()
{
	int area = this->width * this->height;
	return area;
}
