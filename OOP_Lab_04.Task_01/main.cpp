#include <iostream>
#include "CarTransportation.h"
#include "Taxi.h"
#include <string>
#define N 4
using namespace std;

double TotalAmount(const Taxi* arr, int k);
void Sorting(Taxi* arr, int k);
void PrintInfo(Taxi* arr, int k);
void Swap(Taxi* t_1, Taxi* t_2);
int main()
{
	try {
		system("chcp 1251");
		int max_i = 0;
		Taxi info[N];
		info[0]("Daniel Morales", "2001ZY13", 1.7, 12);
		info[1]("Frank Martin", "32 AJE 13", 15, 95.9);
		info[2]("Dominic Toretto", "GPT-803", 9.8, 47);
		info[3]("James Bond", "JB007", 25, 6);
		cout << "\n\n-----------------------------------------------\n\n";
		cout << "\n\n****Before sorting****\n\n";
		PrintInfo(info, N);
		cout << "\n\n-----------------------------------------------\n\n";
		Sorting(info, N);
		cout << "\n\n-----------------------------------------------\n\n";
		cout << "\n\n****After sorting****\n\n";
		PrintInfo(info, N);
		cout << "\n\nThe total amount = " << TotalAmount(info, N) << endl;
		cout << "\n\n****Information about driver with max amount***\n\n" << info[0];
		cout << "\n\n-----------------------------------------------\n\n";
	}
	catch (const char* messege)
	{
		cout << "\nError: " << messege;
	}
	return 0;
}

double TotalAmount(const Taxi* arr, int k)
{
	double sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += arr[i].GetCostOfOrder();
	}
	return sum;
}

void Sorting(Taxi* arr, int k)
{
	Taxi* p = arr;
	for (int i = 1; i < k; i++)
	{
		for (int j = i; j > 0 && p[j - 1] < p[j]; j--)
		{
			Swap(&p[j - 1], &p[j]);
		}
	}
}

void PrintInfo(Taxi* arr, int k)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i];
	}
}

void Swap(Taxi* t_1, Taxi* t_2)
{
	Taxi tmp = *t_1;
	*t_1 = *t_2;
	*t_2 = tmp;
}
