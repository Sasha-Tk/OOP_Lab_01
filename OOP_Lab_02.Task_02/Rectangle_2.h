#pragma once

class Rectangle_2
{
private:
	int *width;
	int *height;
	int n;
	void InitRectangle(int n, int value);
public:
	Rectangle_2();
	Rectangle_2(int n);
	Rectangle_2(int n, int value);
	~Rectangle_2();
	Rectangle_2(const Rectangle_2& copy_source);
	int GetWidth(int n);
	int GetHeight(int n);
	void SetN(int n);
	int GetN();
	void SetWidth(int n, int A);
	void SetHeigth(int n,int H);
	int Perimeter(int n);
	int Square(int n);
};

