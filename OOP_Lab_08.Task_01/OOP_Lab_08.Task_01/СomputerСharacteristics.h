#pragma once
#include <iostream>
#include <string>

using namespace std;

class —omputer—haracteristics
{
private:

	string CPU;
	int RAM;
	string GPU;
	string Resolution;

	—omputer—haracteristics(const string CPU, int RAM, const string GPU, const string resolution);
	~—omputer—haracteristics();
public:
	static —omputer—haracteristics* ComputerConfig(const string CPU, int RAM, const string GPU, const string resolution);

	string GetCPU() const;
	int GetRAM() const;
	string GetGPU() const;
	string GetResolution() const;
	friend ostream& operator<<(ostream& out, —omputer—haracteristics* config);
};