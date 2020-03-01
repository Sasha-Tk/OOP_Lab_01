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
	int GetA(void);
	int GetH(void);
	void SetA(int A);
	void SetH(int H);
	int Per(void);
	int Area(void);
	
	
};

