#include "CarTransportation.h"

char* CarTransportation::CopyData(const char* source)
{
	char* destination = new char[strlen(source) + 1];
	strcpy_s(destination, strlen(source)+1, source);
	return destination;
}

CarTransportation::CarTransportation()
{
	cout << "\n*Constructor of class CarTransportation*";
	this->CarNumber = nullptr;
	this->DriverName = nullptr;
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

CarTransportation::CarTransportation(const CarTransportation& other)
{
	cout << "\n*Constructor of class CarTransportation*";
	this->CarNumber = CopyData(other.CarNumber);
	this->DriverName = CopyData(other.DriverName);
}

CarTransportation::~CarTransportation()
{
	cout << "\n*Destructor of class CarTransportation*";
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

char* CarTransportation::GetCarNumber() const
{
	return this->CarNumber;
}

char* CarTransportation::GetDriverName() const
{
	return this->DriverName;
}

ostream& operator<<(ostream& out, const CarTransportation& obj)
{
	out
		<< "\nInformation about driver:"
		<< "\n\tName: " << obj.GetDriverName()
		<< "\n\tNumber of car: " << obj.GetCarNumber();	
	return out;
}
