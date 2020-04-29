#include "Taxi.h"

double Taxi::CalculationOfCostOfOrder(const double Price_Of_1_Kilometer, const double kilometrage)
{
	return Price_Of_1_Kilometer * kilometrage;
}

char* Taxi::PrintData() 
{
	char* information = new char[255];
	char buffer[15];
	strcpy(information, "\n\nInformation about taxi driver:");
	strcat(information, "\n\tName: ");
	strcat(information, this->GetDriverName());
	strcat(information, "\n\tNumber of car: ");
	strcat(information, this->GetCarNumber());
	strcat(information, "\n\tPrice for 1 km: ");
	sprintf(buffer, "%.2lf", this->GetPrice_For_1_Kilometer());
	strcat(information, buffer);
	strcat(information, "\n\tCost of order: ");
	sprintf(buffer, "%.2lf", this->GetCostOfOrder());
	strcat(information, buffer);
	return information;
}

Taxi::Taxi() :CarTransportation()
{
	cout << "\n*Constructor of class Taxi*";
	this->SetCostOfOrder(0.0);
	this->Price_For_1_Kilometer = 0.0;
}

Taxi::Taxi(
	const char* DriverName,
	const char* CarNumber,
	const double Price_Of_1_Kilometer,
	const double kilometrage) : CarTransportation(DriverName, CarNumber)
{
	cout << "\n*Constructor of class Taxi*";
	if (Price_Of_1_Kilometer <= 0)
	{
		throw "incorrect cost for 1 kilometer!";
	}
	if (kilometrage <= 0)
	{
		throw "incorrect value of kilometrage!";
	}
	this->Price_For_1_Kilometer = Price_Of_1_Kilometer;
	this->SetCostOfOrder(CalculationOfCostOfOrder(Price_Of_1_Kilometer, kilometrage));
}

Taxi::~Taxi()
{
	cout << "\n**Destructor of class Taxi**";
}

void Taxi::SetPrice_For_1_Kilometer(double price)
{
	if (price <= 0)
	{
		throw "incorect price for 1 km!";
	}
	this->Price_For_1_Kilometer = price;
}

double Taxi::GetPrice_For_1_Kilometer() const
{
	return this->Price_For_1_Kilometer;
}

Taxi& Taxi::operator()(const char* DriverName, const char* CarNumber, const double Price_For_1_Kilometer, const double kilometrage)
{
	if (strlen(DriverName) == 0)
	{
		throw "incorrect driver name!";
	}

	this->SetDriverName(DriverName);

	if (strlen(CarNumber) == 0)
	{
		throw "incorrect car number!";
	}

	this->SetCarNumber(CarNumber);

	if (Price_For_1_Kilometer <= 0)
	{
		throw "incorect price for 1 km!";
	}
	this->SetPrice_For_1_Kilometer(Price_For_1_Kilometer);

	if (kilometrage <= 0)
	{
		throw "incorrect value of kilometrage!";
	}
	this->SetCostOfOrder(this->CalculationOfCostOfOrder(Price_For_1_Kilometer, kilometrage));
	return *this;
}