#include "Rectangle_3.h" 
#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
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
int Rectangle::GetWidth() const
{
	return this->width;
}
int Rectangle::GetHeight() const
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
int Rectangle::Perimeter() const
{
	int per = 2 * (this->width + this->height);
	return per;
}

int Rectangle::Square() const
{
	int area = this->width * this->height;
	return area;
}

bool operator<(const Rectangle& R_1, const Rectangle& R_2)
{
	return R_1.Square() < R_2.Square();
}
bool operator>(const Rectangle& R_1, const Rectangle& R_2)
{
	return R_1.Square() > R_2.Square();
}

ostream& operator<<(ostream& out, const Rectangle& R)
{
	out << "Widht = " << R.GetWidth() << endl;
	out << "Height = " << R.GetHeight() << endl;
	out << "Perimeter = 2*(" << R.GetWidth() << "+" << R.GetHeight() << ") = " << R.Perimeter() << endl;
	out << "Square = " << R.GetWidth() << " * " << R.GetHeight() << " = " << R.Square() << endl;
	out << "----------------------------------------------------" << endl;
	return out;
}

Rectangle& Rectangle::operator-=(int n)
{
	if (n >= this->width||n >= this->height) 
	{
		throw "Incorrect value of n";
	}
	this->width -= n;
	this->height -= n;
	return *this;
}