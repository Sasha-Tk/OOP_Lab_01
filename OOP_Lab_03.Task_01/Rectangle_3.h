#pragma once 
#include <iostream>

using namespace std;

class Rectangle
{
private:
	int width;
	int height;
public:
	Rectangle();
	Rectangle(int a, int h);
	~Rectangle();
	Rectangle(const Rectangle& copy_source);
	int GetWidth() const;
	int GetHeight() const;
	void SetWidth(int A);
	void SetHeigth(int H);
	int Perimeter() const;
	int Square() const;
	friend bool operator <(const Rectangle& R_1, const Rectangle& R_2);
	friend bool operator >(const Rectangle& R_1, const Rectangle& R_2);
	Rectangle& operator -=(int n);
	friend ostream& operator<<(ostream& out, const Rectangle& R);
};

