#pragma once
#include "CarTransportation.h"
class BusTransportation : public CarTransportation
{
private:
	double Price_For_10_Kilometer;
	int Min_Amount_Of_Passengers;
	int Amount_Of_Passengers;
	double CalculationOfCostOfOrder(const double, const double, const int);
public:
	BusTransportation();
	BusTransportation(const char*, const char*, const double, const double, const int, const int);
	~BusTransportation();
	void Set_Min_Amount_Of_Passengers(const int);
	void SetAmount_Of_Passengers(const int);
	void SetPrice_For_10_Kilometer(double);
	int Get_Min_Amount_Of_Passengers();
	int GetAmount_Of_Passengers();
	double GetPrice_For_10_Kilometer() const;
	BusTransportation& operator()(const char*, const char*, const double, const double, const int, const int);
	char* PrintData() override;
};