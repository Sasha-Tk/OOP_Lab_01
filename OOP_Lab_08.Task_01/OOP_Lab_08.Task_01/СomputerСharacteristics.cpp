#include "СomputerСharacteristics.h"

 СomputerСharacteristics::СomputerСharacteristics(const string CPU, int RAM, const string GPU, const string resolution)
{
	cout << "\n**Constructor**";

	if (0 == CPU.size())
	{
		throw "incorrect CPU model!";
	}

	this->CPU = CPU;

	if (0 == GPU.size())
	{
		throw "incorrect GPU model!";
	}

	this->GPU = GPU;

	if (RAM <= 0)
	{
		throw "incorrect amount of memory!";
	}

	this->RAM = RAM;

	if (0 == resolution.size())
	{
		throw "incorrect screen resolution!";
	}

	this->Resolution = resolution;
}

СomputerСharacteristics::~СomputerСharacteristics()
{
	cout << "\n**Destructor**";
}

СomputerСharacteristics* СomputerСharacteristics::ComputerConfig(const string CPU, int RAM, const string GPU, const string resolution)
{
	cout << "\n**Instance function**";
	static СomputerСharacteristics instance(CPU, RAM, GPU, resolution);
	return &instance;
}

string СomputerСharacteristics::GetCPU() const
{
	return this->CPU;
}

int СomputerСharacteristics::GetRAM() const
{
	return this->RAM;
}

string СomputerСharacteristics::GetGPU() const
{
	return this->GPU;
}

string СomputerСharacteristics::GetResolution() const
{
	return this->Resolution;
}

ostream& operator<<(ostream& out, СomputerСharacteristics* config)
{
	out
		<< "\n\nComputer characteristics:"
		<< "\n\tCPU model => " << config->GetCPU()
		<< "\n\tRAM amount => " << config->GetRAM() << " GB"
		<< "\n\tGPU model => " << config->GetGPU()
		<< "\n\tScreen resolution => " << config->GetResolution() << endl;
	return out;
}