#pragma once
#include <iostream>
#include <string>

using namespace std;

class ŅomputerConfig
{
private:

	string CPU;
	int RAM;
	string GPU;
	string Resolution;

	ŅomputerConfig(const string CPU, int RAM, const string GPU, const string resolution);
	~ŅomputerConfig();
public:
	static ŅomputerConfig* InstanceComputerConfig(const string CPU, int RAM, const string GPU, const string resolution);

	string GetCPU() const;
	int GetRAM() const;
	string GetGPU() const;
	string GetResolution() const;
	friend ostream& operator<<(ostream& out, ŅomputerConfig* config);
};