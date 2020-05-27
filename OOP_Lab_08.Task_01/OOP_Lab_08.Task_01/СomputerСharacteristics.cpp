#include "—omputer—haracteristics.h"

 —omputer—haracteristics::—omputer—haracteristics(const string CPU, int RAM, const string GPU, const string resolution)
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

—omputer—haracteristics::~—omputer—haracteristics()
{
	cout << "\n**Destructor**";
}

—omputer—haracteristics* —omputer—haracteristics::ComputerConfig(const string CPU, int RAM, const string GPU, const string resolution)
{
	cout << "\n**Instance function**";
	static —omputer—haracteristics instance(CPU, RAM, GPU, resolution);
	return &instance;
}

string —omputer—haracteristics::GetCPU() const
{
	return this->CPU;
}

int —omputer—haracteristics::GetRAM() const
{
	return this->RAM;
}

string —omputer—haracteristics::GetGPU() const
{
	return this->GPU;
}

string —omputer—haracteristics::GetResolution() const
{
	return this->Resolution;
}

ostream& operator<<(ostream& out, —omputer—haracteristics* config)
{
	out
		<< "\n\nComputer characteristics:"
		<< "\n\tCPU model => " << config->GetCPU()
		<< "\n\tRAM amount => " << config->GetRAM() << " GB"
		<< "\n\tGPU model => " << config->GetGPU()
		<< "\n\tScreen resolution => " << config->GetResolution() << endl;
	return out;
}