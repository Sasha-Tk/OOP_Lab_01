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
		cout << "\n��������� ����������� �����" << endl;
	}
	~rectangle()
	{
		cout << "\n��������� ���������� �����" << endl;
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
			cout << "��������� ������� �������� �!";
			return;
		}
		this->a = A;

	}

	void setH(int H)
	{

		if (H <= 0)
		{
			cout << "��������� ������� �������� h!";
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
		cout << endl << "������ ��������: " << endl;
		cout << "a = " << getA() << endl;
		cout << "h = " << getH() << endl << endl;
		cout << "�������� = 2*(" << getA() << "+" << getH() << ") = " << per() << endl;
		cout << "����� = " << getA() << " * " << getH() << " = " << area() << endl;
	}
};


int main()
{
	int a = 0, h = 0;
	system("chcp 1251");
	rectangle rec_1;
	cout << "\n������ �������� �: ";
	do
	{
		cin >> a;
		if (a <= 0)
		{
			cout << "\n��������� ������� �������� �, �������� ������: ";
		}
	} while (a <= 0);
	rec_1.setA(a);
	cout << "\n������ �������� h: ";
	do
	{
		cin >> h;
		if (h <= 0)
		{
			cout << "\n��������� ������� �������� h, �������� ������: ";
		}
	} while (h <= 0);
	rec_1.setH(h);
	rec_1.PrintData();
	return 0;
}
