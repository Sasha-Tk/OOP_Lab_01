#pragma once
#include <iostream>
#include <string>

using namespace std;

class СomputerСharacteristics
{
private:

	string CPU;
	int RAM;
	string GPU;
	string Resolution;

	СomputerСharacteristics(const string CPU, int RAM, const string GPU, const string resolution);
	~СomputerСharacteristics();
public:
	static СomputerСharacteristics* ComputerConfig(const string CPU, int RAM, const string GPU, const string resolution);

	string GetCPU() const;
	int GetRAM() const;
	string GetGPU() const;
	string GetResolution() const;
	friend ostream& operator<<(ostream& out, СomputerСharacteristics* config);
};