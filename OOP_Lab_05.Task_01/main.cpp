#include <iostream>
#include "CarTransportation.h"
#include "Taxi.h"
#include "BusTransportation.h"

#define N 5

using namespace std;

double TotalAmount(CarTransportation** arr, int k);
void Sorting(CarTransportation** arr, int k);
void PrintInfo(CarTransportation** arr, int k);
void Swap(CarTransportation*& t_1, CarTransportation*& t_2);
void FreeMem(CarTransportation** array, int k);

int main()
{
	try {
		system("chcp 1251");
		CarTransportation* transp[N];
		transp[0] = new Taxi("Daniel Morales", "2001ZY13", 1.7, 12);
		transp[1] = new BusTransportation("Jack Traven", "2525", 7, 14, 10, 12);
		transp[2] = new CarTransportation("Dominic Toretto", "GPT-803");
		transp[3] = new Taxi("Frank Martin", "32 AJE 13", 15, 95.9);
		transp[4] = new Taxi("James Bond", "JB007", 25, 6);
		PrintInfo(transp, N);
		cout << "\n\n-----------------------------------------------\n\n";
		cout << "\n\n****Before sorting****\n\n";
		PrintInfo(transp, N);
		cout << "\n\n-----------------------------------------------\n\n";
		Sorting(transp, N);
		cout << "\n\n****After sorting****\n\n";
		PrintInfo(transp, N);
		cout << "\n\nThe total amount = " << TotalAmount(transp, N) << endl;
		cout << "\n\n****Information about driver with max amount***\n\n";
		cout<<transp[N - 1]->PrintData();
		cout << "\n\n-----------------------------------------------\n\n";
		FreeMem(transp, N);
	}
	catch (const char* messege)
	{
		cout << "\nError: " << messege;
	}
	return 0;
}

double TotalAmount(CarTransportation** arr, int k)
{
	double sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += arr[i]->GetCostOfOrder();
	}
	return sum;
}

void Sorting(CarTransportation** arr, int k)
{
	CarTransportation** p = arr;
	for (int i = 1; i < k; i++)
	{
		for (int j = i; j > 0 && *p[j - 1]>*p[j]; j--)
		{
			Swap(p[j - 1], p[j]);
		}
	}
}

void PrintInfo(CarTransportation** arr, int k)
{
	
	for (int i = 0; i < k; i++)
	{
		char* buffer = arr[i]->PrintData();
		cout << buffer;
		delete[] buffer;
	}
}

void Swap(CarTransportation*& t_1, CarTransportation*& t_2)
{
	CarTransportation* tmp = t_1;
	t_1 = t_2;
	t_2 = tmp;
}

void FreeMem(CarTransportation** array, int k)
{
	for (int i = 0; i < k; i++)
	{
		delete array[i];
	}
}