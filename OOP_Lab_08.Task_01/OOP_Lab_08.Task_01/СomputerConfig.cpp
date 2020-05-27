#include "—omputer—onfig.h"

 —omputerConfig::—omputerConfig(const string CPU, int RAM, const string GPU, const string resolution)
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

—omputerConfig::~—omputerConfig()
{
	cout << "\n**Destructor**";
}

—omputerConfig* —omputerConfig::InstanceComputerConfig(const string CPU, int RAM, const string GPU, const string resolution)
{
	cout << "\n**Instance function**";
	static —omputerConfig instance(CPU, RAM, GPU, resolution);
	return &instance;
}

string —omputerConfig::GetCPU() const
{
	return this->CPU;
}

int —omputerConfig::GetRAM() const
{
	return this->RAM;
}

string —omputerConfig::GetGPU() const
{
	return this->GPU;
}

string —omputerConfig::GetResolution() const
{
	return this->Resolution;
}

ostream& operator<<(ostream& out, —omputerConfig* config)
{
	out
		<< "\n\nComputer characteristics:"
		<< "\n\tCPU model => " << config->GetCPU()
		<< "\n\tRAM amount => " << config->GetRAM() << " GB"
		<< "\n\tGPU model => " << config->GetGPU()
		<< "\n\tScreen resolution => " << config->GetResolution() << endl;
	return out;
}