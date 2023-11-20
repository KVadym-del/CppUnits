#pragma once

#include <ratio>

#include "Resources.hpp"
#include "UnitsRatio.hpp"


namespace Units::Millimeters
{
	class Millimeters;
}
namespace Units::Centimeters
{
	class Centimeters;
}
namespace Units::Meters
{
	class Meters;
}
namespace Units::Kilometers
{
	class Kilometers;
}

#include "MOLength/Millimeters.hpp"
#include "MOLength/Centimeters.hpp"
#include "MOLength/Meters.hpp"
#include "MOLength/Kilometers.hpp"

namespace Units
{
	using Millimeters_t		=	Millimeters::Millimeters;
	using Centimeters_t		=	Centimeters::Centimeters;
	using Meters_t			=	Meters::Meters;
	using Kilometers_t		=	Kilometers::Kilometers;

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

	inline Millimeters Units::Millimeters::Millimeters::operator=(const Kilometers::Kilometers& kilometers) const
	{
		return Millimeters((Ratio::castToSi<Ratio::Millimeters_ratio>(kilometers())) / Ratio::castToSi<Ratio::Kilometers_ratio>(1));
	}
}

namespace Units::Centimeters
{
	inline Centimeters Centimeters::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return Centimeters(Ratio::castToSi<Ratio::Centimeters_ratio>(millimeters()) / (Ratio::castToSi<Ratio::Millimeters_ratio>(1)));
	}

	inline Centimeters Centimeters::operator=(const Meters::Meters& meters) const
	{
		return Centimeters(Ratio::castToSi<Ratio::Centimeters_ratio>(meters()) / (Ratio::castToSi<Ratio::Meters_ratio>(1)));
	}

	inline Centimeters Units::Centimeters::Centimeters::operator=(const Kilometers::Kilometers& kilometers) const
	{
		return Centimeters(Ratio::castToSi<Ratio::Centimeters_ratio>(kilometers()) / (Ratio::castToSi<Ratio::Kilometers_ratio>(1)));
	}
}

namespace Units::Meters
{
	inline Meters Meters::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return Meters(Ratio::castToSi<Ratio::Meters_ratio>(millimeters()) / (Ratio::castToSi<Ratio::Millimeters_ratio>(1)));
	}

	inline Meters Meters::operator=(const Centimeters::Centimeters& centimeters) const
	{
		return Meters(Ratio::castToSi<Ratio::Meters_ratio>(centimeters()) / (Ratio::castToSi<Ratio::Centimeters_ratio>(1)));
	}

	inline Meters Units::Meters::Meters::operator=(const Kilometers::Kilometers& kilometers) const
	{
		return  Meters(Ratio::castToSi<Ratio::Meters_ratio>(kilometers()) / (Ratio::castToSi<Ratio::Kilometers_ratio>(1)));
	}
}

namespace Units::Kilometers
{
	inline Kilometers Kilometers::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return Kilometers(Ratio::castToSi<Ratio::Kilometers_ratio>(millimeters()) / (Ratio::castToSi<Ratio::Millimeters_ratio>(1)));
	}

	inline Kilometers Units::Kilometers::Kilometers::operator=(const Centimeters::Centimeters& centimeters) const
	{
		return Kilometers(Ratio::castToSi<Ratio::Kilometers_ratio>(centimeters()) / (Ratio::castToSi<Ratio::Centimeters_ratio>(1)));
	}

	inline Kilometers Kilometers::operator=(const Meters::Meters& meters) const
	{
		return Kilometers(Ratio::castToSi<Ratio::Kilometers_ratio>(meters()) / (Ratio::castToSi<Ratio::Meters_ratio>(1)));
	}
}

/*
namespace Units::Literals 
{
	inline Units::Meters_t operator"" _m(Resources::Float128 value) {
		return Units::Meters_t(value);
	}

	inline Units::Centimeters_t operator"" _cm(Resources::Float128 value) {
		return Units::Centimeters_t(value);
	}

	static inline Millimeters_t operator"" _mm(Resources::Float128 value) {
		return Millimeters_t(value);
	}
}
*/
