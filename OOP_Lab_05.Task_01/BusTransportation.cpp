#include "BusTransportation.h"

double BusTransportation::CalculationOfCostOfOrder(const double Price_Of_10_Kilometer,
												   const double kilometrage,
												   const int Amount_Of_Passengers)
{
	return Price_Of_10_Kilometer * kilometrage/10.0 * Amount_Of_Passengers;
}

BusTransportation::BusTransportation()
{
	cout << "\n*Constructor of class BusTransportation*";
	this->SetCostOfOrder(0.0);
	this->Price_For_10_Kilometer = 0.0;
	this->Min_Amount_Of_Passengers = 0;
	this->Amount_Of_Passengers = 0;
}

BusTransportation::BusTransportation(const char* DriverName, 
									 const char* CarNumber,
									 const double Price_Of_10_Kilometer, 
									 const double kilometrage, 
									 const int Min_Amount_Of_Passengers, 
									 const int Amount_Of_Passengers) 
									 : CarTransportation(DriverName, CarNumber)
{
	cout << "\n*Constructor of class BusTransportation*";
	if (Min_Amount_Of_Passengers<0)
	{
		throw "incorrect minimal amount of passengers!";
	}
	if (Amount_Of_Passengers < 0)
	{
		throw "incorrect amount of passengers!";
	}
	if (Amount_Of_Passengers < Min_Amount_Of_Passengers)
	{
		throw "the number of passengers must be greater than the minimum number of passengers!";
	}
	this->Min_Amount_Of_Passengers = Min_Amount_Of_Passengers;
	this->Amount_Of_Passengers = Amount_Of_Passengers;

	if (Price_Of_10_Kilometer <= 0)
	{
		throw "incorect price for 10 km!";
	}
	this->Price_For_10_Kilometer = Price_Of_10_Kilometer;
	this->SetCostOfOrder(CalculationOfCostOfOrder(Price_Of_10_Kilometer, kilometrage, Amount_Of_Passengers));
}

BusTransportation::~BusTransportation()
{
	cout << "\n**Destructor of class BusTransportation**";
}

void BusTransportation::Set_Min_Amount_Of_Passengers(const int amount)
{
	if (amount < 0)
	{
		throw "incorrect minimal amount of passengers!";
	}
	this->Min_Amount_Of_Passengers = amount;
}

void BusTransportation::SetAmount_Of_Passengers(const int amount)
{
	if (amount < 0)
	{
		throw "incorrect minimal amount of passengers!";
	}
	if (amount < this->Min_Amount_Of_Passengers)
	{
		throw "the number of passengers must be greater than the minimum number of passengers!";
	}
	this->Amount_Of_Passengers = amount;
}

void BusTransportation::SetPrice_For_10_Kilometer(double price)
{
	if (price <= 0)
	{
		throw "incorect price for 1 km!";
	}
	this->Price_For_10_Kilometer = price;
}

int BusTransportation::Get_Min_Amount_Of_Passengers()
{
	return this->Min_Amount_Of_Passengers;
}

int BusTransportation::GetAmount_Of_Passengers()
{
	return this->Amount_Of_Passengers;
}

double BusTransportation::GetPrice_For_10_Kilometer() const
{
	return this->Price_For_10_Kilometer;
}

BusTransportation& BusTransportation::operator()(const char* DriverName, 
												 const char* CarNumber, 
												 const double Price_For_10_Kilometer, 
												 const double kilometrage,
												 const int Min_Amount_Of_Passengers,
												 const int Amount_Of_Passengers)
{
	this->SetDriverName(DriverName);
	this->SetCarNumber(CarNumber);
	this->SetPrice_For_10_Kilometer(Price_For_10_Kilometer);
	this->Set_Min_Amount_Of_Passengers(Min_Amount_Of_Passengers);
	this->SetAmount_Of_Passengers(Amount_Of_Passengers);
	if (kilometrage <= 0)
	{
		throw "incorrect value of kilometrage!";
	}
	this->SetCostOfOrder(this->CalculationOfCostOfOrder(Price_For_10_Kilometer, kilometrage, Amount_Of_Passengers));
	return *this;
}

char* BusTransportation::PrintData()
{
	char* information = new char[255];
	char buffer[15];
	strcpy(information, "\n\nInformation about bus driver:");
	strcat(information, "\n\tName: ");
	strcat(information, this->GetDriverName());
	strcat(information, "\n\tNumber of car: ");
	strcat(information, this->GetCarNumber());
	strcat(information, "\n\tPrice for 10 km: ");
	sprintf(buffer, "%.2lf", this->GetPrice_For_10_Kilometer());
	strcat(information, buffer);
	strcat(information, "\n\tMinimal amount of passengers: ");
	sprintf(buffer, "%d", this->Get_Min_Amount_Of_Passengers());
	strcat(information, buffer);
	strcat(information, "\n\tAmount of passengers: ");
	sprintf(buffer, "%d", this->GetAmount_Of_Passengers());
	strcat(information, buffer);
	strcat(information, "\n\tCost of order: ");
	sprintf(buffer, "%.2lf", this->GetCostOfOrder());
	strcat(information, buffer);
	return information;
}