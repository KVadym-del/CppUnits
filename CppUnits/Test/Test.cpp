#include <iostream>

#include "../Units/Units.hpp"

using namespace Units;

void print(const Resources::Float128& number)
{
	std::cout << std::fixed << number << std::endl;
}

void print(const Millimeters_t& number)
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

	centimeters = centimeters + 120;
	meters = centimeters;
	millimeters = kilometers;

	std::cin >> centimeters;

	print(meters());
	print(millimeters);

}