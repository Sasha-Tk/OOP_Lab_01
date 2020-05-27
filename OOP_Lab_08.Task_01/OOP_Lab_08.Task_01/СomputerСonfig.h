#pragma once
#include <iostream>
#include <string>

using namespace std;

class ÑomputerConfig
{
private:

	string CPU;
	int RAM;
	string GPU;
	string Resolution;

	ÑomputerConfig(const string CPU, int RAM, const string GPU, const string resolution);
	~ÑomputerConfig();
public:
	static ÑomputerConfig* InstanceComputerConfig(const string CPU, int RAM, const string GPU, const string resolution);

	string GetCPU() const;
	int GetRAM() const;
	string GetGPU() const;
	string GetResolution() const;
	friend ostream& operator<<(ostream& out, ÑomputerConfig* config);
};