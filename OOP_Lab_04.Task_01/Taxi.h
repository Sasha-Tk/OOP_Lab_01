#pragma once
#include "CarTransportation.h"
class Taxi :
	public CarTransportation
{
private:
	double Price_For_1_Kilometer;
	double CostOfOrder;
	double CalculationOfCostOfOrder(const double Price_Of_1_Kilometer, const double kilometrage);
public:
	Taxi();
	Taxi(const char* DriverName, const char* CarNumber, const double Price_Of_1_Kilometer, const double kilometrage);
	~Taxi();
	void SetPrice_For_1_Kilometer(double price);
	void SetCostOfOrder(double kilometrage);
	double GetPrice_For_1_Kilometer() const;
	double GetCostOfOrder() const;
	Taxi& operator()(const char* DriverName, const char* CarNumber, const double Price_Of_1_Kilometer, const double kilometrage);
	friend bool operator<(const Taxi& t_1, const Taxi& t_2);
	friend bool operator>(const Taxi& t_1, const Taxi& t_2);
	friend ostream& operator<< (ostream& out, const Taxi& obj);
	Taxi& operator=(Taxi& other);
};

