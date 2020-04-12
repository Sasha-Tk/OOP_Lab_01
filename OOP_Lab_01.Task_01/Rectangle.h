#pragma once

class Rectangle_2
{
private:
	int width;
	int height;
public:
	Rectangle_2();
	Rectangle_2(int a, int h);
	~Rectangle_2();
	Rectangle_2(const Rectangle_2& copy_source);
	int GetWidth();
	int GetHeight();
	void SetWidth(int A);
	void SetHeigth(int H);
	int Perimeter();
	int Square();
};

