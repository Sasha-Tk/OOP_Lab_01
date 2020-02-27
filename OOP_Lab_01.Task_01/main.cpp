#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class rectangle
{
private:
	int a;
	int h;
public:
	rectangle()
	{
		a = 0;
		h = 0;
		cout << "\nСпрацював конструктор класу" << endl;
	}
	~rectangle()
	{
		cout << "\nСпрацював деструктор класу" << endl;
	}
	int getA(void)
	{
		return a;
	}
	int getH(void)
	{
		return h;
	}
	void setA(int A)
	{
		if (A <= 0)
		{
			cout << "Помилково введено значення а!";
			return;
		}
		this->a = A;

	}

	void setH(int H)
	{

		if (H <= 0)
		{
			cout << "Помилково введено значення h!";
			return;
		}
		this->h = H;
	}
	int per(void)
	{
		int per = 2 * (a + h);
		return per;
	}
	int area(void)
	{
		int area = a * h;
		return area;
	}
	void PrintData()
	{
		cout << endl << "Введені значення: " << endl;
		cout << "a = " << getA() << endl;
		cout << "h = " << getH() << endl << endl;
		cout << "Периметр = 2*(" << getA() << "+" << getH() << ") = " << per() << endl;
		cout << "Площа = " << getA() << " * " << getH() << " = " << area() << endl;
	}
};


int main()
{
	int a = 0, h = 0;
	system("chcp 1251");
	rectangle rec_1;
	cout << "\nВведіть значення а: ";
	do
	{
		cin >> a;
		if (a <= 0)
		{
			cout << "\nПомилково введено значення а, повторіть спробу: ";
		}
	} while (a <= 0);
	rec_1.setA(a);
	cout << "\nВведіть значення h: ";
	do
	{
		cin >> h;
		if (h <= 0)
		{
			cout << "\nПомилково введено значення h, повторіть спробу: ";
		}
	} while (h <= 0);
	rec_1.setH(h);
	rec_1.PrintData();
	return 0;
}
