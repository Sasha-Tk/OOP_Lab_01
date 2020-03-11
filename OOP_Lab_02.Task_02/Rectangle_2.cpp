#include "Rectangle_2.h"
#include <iostream>

using namespace std;

void Rectangle_2::InitRectangle(int n, int value)
{
	this->n = n;
	this->width = new int [this->n];
	this->height = new int [this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->width[i] = value;
		this->height[i] = value;
	}
}

Rectangle_2::Rectangle_2() 
{	
	cout << "\nConstructor_1" << endl;
	Rectangle_2::InitRectangle(1, 1);
}
Rectangle_2::Rectangle_2(int n)
{
	cout << "\nConstructor_2" << endl;
	this->n = n;
	Rectangle_2::InitRectangle(this->n, 2);
}
Rectangle_2::Rectangle_2(int n, int value)
{
	cout << "\nConstructor_2" << endl;
	Rectangle_2::InitRectangle(n, value);
}
Rectangle_2::~Rectangle_2()
{
	cout << "\nDestructor" << endl;
	delete[] this->width;
	delete[] this->height;
}

Rectangle_2::Rectangle_2(const Rectangle_2& copy_source)
{
	cout << "\nConstructor copy" << endl;
	this->n = copy_source.n;
	this->height = new int[this->n];
	this->width = new int[this->n];
	for (int i = 0; i < this->n; i++) 
	{
		this->height[i] = copy_source.height[i];
		this->width[i] = copy_source.width[i];
	}
}

int Rectangle_2::GetWidth(int n)
{
	return this->width[n];
}

int Rectangle_2::GetHeight(int n)
{
	return this->height[n];
}

void Rectangle_2::SetN(int n)
{
	this->n = n;
}

int Rectangle_2::GetN()
{
	return this->n;
}

void Rectangle_2::SetWidth(int n,int weight)
{
	if (weight <= 0)
	{
		throw "The width value was entered incorrectly!";
	}
	this->width[n] = weight;
}

void Rectangle_2::SetHeigth(int n, int height)
{
	if (height <= 0)
	{
		throw "The height value was entered incorrectly!";
	}
	this->height[n] = height;
}

int Rectangle_2::Perimeter(int n)
{
	int per = 2 * (this->width[n] + this->height[n]);
	return per;
}

int Rectangle_2::Square(int n)
{
	int area = this->width[n] * this->height[n];
	return area;
}
