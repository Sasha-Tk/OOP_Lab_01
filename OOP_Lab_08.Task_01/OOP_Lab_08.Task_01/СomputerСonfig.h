#pragma once
#include <iostream>
#include <string>

using namespace std;

class �omputerConfig
{
private:

	string CPU;
	int RAM;
	string GPU;
	string Resolution;

	�omputerConfig(const string CPU, int RAM, const string GPU, const string resolution);
	~�omputerConfig();
public:
	static �omputerConfig* InstanceComputerConfig(const string CPU, int RAM, const string GPU, const string resolution);

	string GetCPU() const;
	int GetRAM() const;
	string GetGPU() const;
	string GetResolution() const;
	friend ostream& operator<<(ostream& out, �omputerConfig* config);
};