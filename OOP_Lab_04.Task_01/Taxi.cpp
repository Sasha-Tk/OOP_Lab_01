#include "Taxi.h"

double Taxi::CalculationOfCostOfOrder(const double Price_Of_1_Kilometer, const double kilometrage)
{
	return Price_Of_1_Kilometer * kilometrage;
}

Taxi::Taxi() :CarTransportation()
{
	cout << "\n*Constructor of class Taxi*";
	this->CostOfOrder = 0.0;
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
	this->CostOfOrder = CalculationOfCostOfOrder(Price_Of_1_Kilometer, kilometrage);
}

Taxi::~Taxi()
{
	cout << "\n*Destructor of class Taxi*";
}

void Taxi::SetPrice_For_1_Kilometer(double price)
{
	if (price <= 0)
	{
		throw "incorect price for 1 km!";
	}
	this->Price_For_1_Kilometer = price;
}

void Taxi::SetCostOfOrder(double kilometrage)
{
	if (kilometrage <= 0)
	{
		throw "incorrect value of kilometrage!";
	}
	if (this->Price_For_1_Kilometer == 0)
	{
		throw "you must enter a price before calculating the cost of order!";
	}
	this->CostOfOrder = CalculationOfCostOfOrder(this->Price_For_1_Kilometer, kilometrage);
}

double Taxi::GetPrice_For_1_Kilometer() const
{
	return this->Price_For_1_Kilometer;
}

double Taxi::GetCostOfOrder() const
{
	return this->CostOfOrder;
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
	this->SetCostOfOrder(kilometrage);
	return *this;
}

Taxi& Taxi::operator=(Taxi& other)
{
	this->SetDriverName(CopyData(other.GetDriverName()));
	this->SetCarNumber(CopyData(other.GetCarNumber()));
	this->Price_For_1_Kilometer = other.Price_For_1_Kilometer;
	this->CostOfOrder = other.CostOfOrder;
	return* this;
}

bool operator<(const Taxi& t_1, const Taxi& t_2)
{
	return t_1.CostOfOrder<t_2.CostOfOrder;
}

bool operator>(const Taxi& t_1, const Taxi& t_2)
{
	return t_1.CostOfOrder > t_2.CostOfOrder;
}

ostream& operator<<(ostream& out, const Taxi& obj)
{
	out
		<< "\nInformation about taxi driver:"
		<< "\n\tName: " << obj.GetDriverName()
		<< "\n\tNumber of car: " << obj.GetCarNumber()
		<< "\n\tPrice for 1 km: " << obj.GetPrice_For_1_Kilometer()
		<< "\n\tCost of order: " << obj.GetCostOfOrder();
	return out;
}


