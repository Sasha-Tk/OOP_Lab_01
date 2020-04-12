#pragma once

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
	int GetWidth();
	int GetHeight();
	void SetWidth(int A);
	void SetHeigth(int H);
	int Perimeter();
	int Square();
};

