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

	// SI master units
	using Meters_ratio = std::ratio<1>;

	using Centimeters_ratio = std::centi;
	using Millimeters_ratio = std::milli;

	/* TODO: fix this
	using Meters_duration = std::chrono::duration<Resources::Float128> ;
	using Centimeters_duration = std::chrono::duration<Resources::Float128, std::centi> ;
	using Millimeters_duration = std::chrono::duration<Resources::Float128, std::milli> ;
	*/
}
