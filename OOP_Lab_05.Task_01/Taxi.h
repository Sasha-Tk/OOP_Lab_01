#pragma once
#include "CarTransportation.h"
class Taxi : public CarTransportation
{
private:
	double Price_For_1_Kilometer;
	double CalculationOfCostOfOrder(const double, const double);
public:
	char* PrintData() override;
	Taxi();
	Taxi(const char*, const char*, const double, const double);
	~Taxi();
	void SetPrice_For_1_Kilometer(double);
	double GetPrice_For_1_Kilometer() const;
	Taxi& operator()(const char*, const char*, const double, const double);
};