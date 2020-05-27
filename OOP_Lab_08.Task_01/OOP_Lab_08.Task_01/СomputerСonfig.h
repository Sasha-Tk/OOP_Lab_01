#pragma once
#include <iostream>
#include <string>

using namespace std;

class СomputerConfig
{
private:

	string CPU;
	int RAM;
	string GPU;
	string Resolution;

	СomputerConfig(const string CPU, int RAM, const string GPU, const string resolution);
	~СomputerConfig();
public:
	static СomputerConfig* InstanceComputerConfig(const string CPU, int RAM, const string GPU, const string resolution);

	string GetCPU() const;
	int GetRAM() const;
	string GetGPU() const;
	string GetResolution() const;
	friend ostream& operator<<(ostream& out, СomputerConfig* config);
};