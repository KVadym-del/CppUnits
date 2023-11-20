# CppUnits
It's simple header-only library for units of measurement in C++.

## How to initialize Unit?
Firstly include header file:
```cpp
#include "Units/Units.hpp"
```

Than you can initialize units like:
```cpp
Millimeters_t millimeters(190001);

Centimeters_t centimeters;
centimeters = 24.24;

Meters_t meters{ 14.2473738 };

Kilometers_t kilometers;
kilometers = centimeters;
```
## Usage
You can use units like normal variables:
```cpp
centimeters = centimeters + 120;

std::cout << std::fixed << centimeters << std::endl;

std::cin >> centimeters;
```
## Sharing unit as a parameter of function
You can share unit as a parameter of function in two ways
### 1. Using as class
```cpp
void print(const Millimeters_t& number)
{
	std::cout << std::fixed << number << std::endl;
}

print(millimeters);
```
### 2. Using as pure value
To get pure value from unit you need to use ```()``` at the end of unit object.
```cpp
void print(const Resources::Float128& number)
{
	std::cout << std::fixed << number << std::endl;
}

print(meters());
```
Using interface ```BaseUnit::BaseUnit``` as function parameter is not recommended because it's not fully implemented yet.