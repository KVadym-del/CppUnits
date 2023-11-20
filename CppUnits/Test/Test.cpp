#include <iostream>

#include "../Units/Units.hpp"

using namespace Units;

void print(const Resources::Float128& number)
{
	std::cout << std::fixed << number << std::endl;
}

int main(void)
{
	Millimeters_t millimeters(190001);
	Centimeters_t centimeters(122.53235);
	Meters_t meters(14.2473738);
	Kilometers_t kilometers(6325);

	//centimeters = millimeters;
	meters = centimeters;
	millimeters = kilometers;

	print(meters());
	print(millimeters());

}