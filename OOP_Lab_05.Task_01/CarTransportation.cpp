#include "CarTransportation.h"

char* CarTransportation::CopyData(const char* source)
{
	char* destination = new char[strlen(source) + 1];
	strcpy_s(destination, strlen(source)+1, source);
	return destination;
}

char* CarTransportation::PrintData()
{
	char* information = new char[255];
	char buffer[15];
	strcpy(information, "\n\nInformation about driver:");
	strcat(information, "\n\tName: ");
	strcat(information, this->GetDriverName());
	strcat(information, "\n\tNumber of car: ");
	strcat(information, this->GetCarNumber());
	strcat(information, "\n\tCost of order: ");
	sprintf(buffer, "%.2lf", this->GetCostOfOrder());
	strcat(information, buffer);
	return information;
}

CarTransportation::CarTransportation()
{
	cout << "\n*Constructor of class CarTransportation*";
	this->CarNumber = nullptr;
	this->DriverName = nullptr;
	this->CostOfOrder = 0.0;
}

CarTransportation::CarTransportation(const char* DriverName, const char* CarNumber)
{
	cout << "\n*Constructor of class CarTransportation*";
	if (strlen(DriverName) == 0)
	{
		throw "incorrect driver name!";
	}
	this->DriverName = CopyData(DriverName);
	
	if (strlen(CarNumber) == 0)
	{
		throw "incorrect car number!";
	}
	this->CarNumber = CopyData(CarNumber);	
}

CarTransportation::~CarTransportation()
{
	cout << "\n**Destructor of class CarTransportation**";
	delete[] this->CarNumber;
	delete[] this->DriverName;
}

void CarTransportation::SetCarNumber(const char* CarNumber)
{
	if (strlen(CarNumber) == 0)
	{
		throw "incorrect car number!";
	}
	this->CarNumber = CopyData(CarNumber);
}

void CarTransportation::SetDriverName(const char* DriverName)
{
	if (strlen(DriverName) == 0)
	{
		throw "incorrect driver name!";
	}
	this->DriverName = CopyData(DriverName);
}

void CarTransportation::SetCostOfOrder(const double CostOfOrder)
{
	if (CostOfOrder < 0)
	{
		throw "incorrect value of cost of order!";
	}
	this->CostOfOrder = CostOfOrder;
}

char* CarTransportation::GetCarNumber() const
{
	return this->CarNumber;
}

char* CarTransportation::GetDriverName() const
{
	return this->DriverName;
}

double CarTransportation::GetCostOfOrder() const
{
	return this->CostOfOrder;
}

CarTransportation& CarTransportation::operator=(CarTransportation& other)
{
	this->SetDriverName(CopyData(other.GetDriverName()));
	this->SetCarNumber(CopyData(other.GetCarNumber()));
	this->SetCostOfOrder(other.GetCostOfOrder());
	return*this;
}

bool operator<(const CarTransportation& c_1, const CarTransportation& c_2)
{
	return c_1.CostOfOrder < c_2.CostOfOrder;
}

bool operator>(const CarTransportation& c_1, const CarTransportation& c_2)
{
	return c_1.CostOfOrder > c_2.CostOfOrder;
}