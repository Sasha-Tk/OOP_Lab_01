#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>

using namespace std;
class CarTransportation{
private:
	char* DriverName;
	char* CarNumber;
	double CostOfOrder;
protected:
	char* CopyData(const char*);
public:
	virtual char* PrintData();
	CarTransportation();
	CarTransportation(const char*,const char*);
	virtual ~CarTransportation();
	void SetCarNumber(const char*);
	void SetDriverName(const char*);
	void SetCostOfOrder(const double);
	char* GetCarNumber() const;
	char* GetDriverName() const; 
	double GetCostOfOrder()const;
	friend bool operator<(const CarTransportation&, const CarTransportation&);
	friend bool operator>(const CarTransportation&, const CarTransportation&);
};