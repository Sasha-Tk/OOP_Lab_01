#include "СomputerСonfig.h"
#include <iostream>

using namespace std;

int main()
{
	try 
	{
		СomputerConfig* config_1 = СomputerConfig::InstanceComputerConfig("Intel i5-4460", 16, "AMD R9 380 4G", "1920 x 1080");
		
		cout << config_1;

		СomputerConfig* config_2 = СomputerConfig::InstanceComputerConfig("AMD Ryzen 7", 32, "Nvidia 2080 Super", "3840 x 2160");
		cout << config_2;
	}
	catch (const char* error)
	{
		cout << "Error: " << error;
	}
}