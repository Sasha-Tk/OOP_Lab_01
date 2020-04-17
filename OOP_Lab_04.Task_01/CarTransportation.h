#pragma once
#include <string.h>
#include <iostream>

using namespace std;
class CarTransportation
{
private:
	char* DriverName;
	char* CarNumber;
protected:
	char* CopyData(const char* source);
public:
	CarTransportation();
	CarTransportation(const char*,const char*);
	CarTransportation(const CarTransportation& other);
	~CarTransportation();
	void SetCarNumber(const char* CarNumber);
	void SetDriverName(const char* DriverName);
	char* GetCarNumber() const;
	char* GetDriverName() const; 
	friend ostream& operator<< (ostream& out, const CarTransportation& obj);
};

