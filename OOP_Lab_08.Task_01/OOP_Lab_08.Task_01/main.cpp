#include "СomputerСharacteristics.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	try 
	{
		СomputerСharacteristics* config_1 = СomputerСharacteristics::ComputerConfig("Intel i5-4460", 16, "Msi AMD R9 380 4G", "1920 x 1080");
		СomputerСharacteristics* config_2 = СomputerСharacteristics::ComputerConfig("AMD Ryzen 7", 32, "Msi Nvidia 2080 Super", "3840 x 2160");
		cout << config_1;
		cout << config_2;
	}
	catch (const char* error)
	{
		cout << "Error: " << error;
	}
}