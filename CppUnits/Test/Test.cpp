#include <iostream>

#include "../Units/Units.hpp"

using namespace Units;

void print(const Resources::Float128& number)
{
	std::cout << number << std::endl;
}

int main(void)
{
	Centimeters::Centimeters centimeters(122.53235);
	Millimeters::Millimeters millimeters(190001);
	Meters::Meters meters(14.2473738);

	//centimeters = millimeters;
	meters = centimeters;

	print(meters());

}