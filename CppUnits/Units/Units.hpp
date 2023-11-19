#pragma once

#include <ratio>

#include "Resources.hpp"
#include "UnitsRatio.hpp"

namespace Units::Centimeters
{
	class Centimeters;
}

namespace Units::Millimeters
{
	class Millimeters;
}

namespace Units::Meters
{
	class Meters;
}

#include "MOLength/Centimeters.hpp"
#include "MOLength/Millimeters.hpp"
#include "MOLength/Meters.hpp"

namespace Units
{
	using Centimeters_t = Centimeters::Centimeters;
	using Millimeters_t = Millimeters::Millimeters;
	using Meters_t = Meters::Meters;

	template<typename Generation, typename GenerationRatio, typename FromRatio, typename Value>
	inline constexpr Generation convert(const Value& value)
	{
		return Generation(Ratio::castToSi<GenerationRatio>(value()) / Ratio::castToSi<FromRatio>(1));
	}
}

namespace Units::Millimeters
{
	// return Units::convert<Millimeters, Ratio::Meters_ratio, Ratio::Centimeters_ratio, Centimeters::Centimeters>(centimeters);
	inline Millimeters Millimeters::operator=(const Centimeters::Centimeters& centimeters) const
	{
		return Millimeters((Ratio::castToSi<Ratio::Millimeters_ratio>(centimeters())) / Ratio::castToSi<Ratio::Centimeters_ratio>(1));
	}

	inline Millimeters Millimeters::operator=(const Meters::Meters& meters) const
	{
		return Millimeters((Ratio::castToSi<Ratio::Millimeters_ratio>(meters())) / Ratio::castToSi<Ratio::Meters_ratio>(1));
	}
}

namespace Units::Centimeters
{
	inline Centimeters Centimeters::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return Centimeters(Ratio::castToSi<Ratio::Centimeters_ratio>(millimeters()) / (Ratio::castToSi<Ratio::Millimeters_ratio>(1)));
	}
}

namespace Units::Meters
{
	inline Meters Meters::operator=(const Centimeters::Centimeters& centimeters) const
	{
		return Meters(Ratio::castToSi<Ratio::Meters_ratio>(centimeters()) / (Ratio::castToSi<Ratio::Centimeters_ratio>(1)));
	}

	inline Meters Meters::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return Meters(Ratio::castToSi<Ratio::Meters_ratio>(millimeters()) / (Ratio::castToSi<Ratio::Millimeters_ratio>(1)));
	}
}


