#include <iostream>

#include "../Units/Units.hpp"

using namespace Units;

void print(const Resources::Float128& number)
{
	std::cout << std::fixed << number << std::endl;
}

void print(const Kilometers_t& number)
{
	std::cout << std::fixed << number << std::endl;
}

int main(void)
{
	Millimeters_t millimeters(190001);
	Centimeters_t centimeters;
	centimeters = 24.24;
	Meters_t meters{ 14.2473738 };
	Kilometers_t kilometers;
	kilometers = centimeters;
	Micrometers_t micrometers(1200000000);

	//centimeters = centimeters + 120;
	meters = centimeters;
	millimeters = centimeters;
	kilometers = millimeters;
	kilometers = micrometers;

	//std::cin >> centimeters;

	//print(meters());
	print(kilometers);

	//print(kilometers());
	kilometers += 1;
	//print(kilometers());
}