#pragma once
#include <ratio>
#include <chrono>
#include "Resources.hpp"

namespace Units::Ratio
{
	template<typename Ratio>
	constexpr Resources::Float128 castToSi(const Resources::Float128& value)
	{
		Resources::Float128 castedValue;
		constexpr Resources::Float128 dev = static_cast<Resources::Float128>(Ratio::num) / Ratio::den;
		if constexpr (dev > 0)
		{
			castedValue = value / dev;
		} else
		{
			castedValue = value * dev;
		}

		return castedValue;
	}

	using Micrometers_ratio		=	std::micro;
	using Millimeters_ratio		=	std::milli;
	using Centimeters_ratio		=	std::centi;
	using Meters_ratio			=	std::ratio<1>;
	using Kilometers_ratio		=	std::kilo;

}
