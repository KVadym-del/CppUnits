#pragma once
#include <ratio>

#include "UnitsRatio.hpp"
#include "Resources.hpp"

namespace Units::Micrometers
{
	class Micrometers;
}
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

namespace Units
{
	using Micrometers_t = Micrometers::Micrometers;
	using Millimeters_t = Millimeters::Millimeters;
	using Centimeters_t = Centimeters::Centimeters;
	using Meters_t = Meters::Meters;
	using Kilometers_t = Kilometers::Kilometers;
}

#include "MOLength/Micrometers.hpp"
#include "MOLength/Millimeters.hpp"
#include "MOLength/Centimeters.hpp"
#include "MOLength/Meters.hpp"
#include "MOLength/Kilometers.hpp"

namespace Units
{
	template<typename To, typename ToRatio, typename FromRatio, typename FromValue>
	inline constexpr To convertor(const FromValue& fromValue)
	{
		return To(Ratio::castToSi<ToRatio>(fromValue()) / Ratio::castToSi<FromRatio>(1));
	}
}

#define UNIT_DEFINER(To, From) 	inline To To::operator=(const From::From& unit) const\
	{\
		return convertor<To, To##_ratio, From##_ratio, From::From>(unit);\
	}\

namespace Units::Micrometers
{
	using namespace Ratio;

	UNIT_DEFINER(Micrometers, Millimeters);
	UNIT_DEFINER(Micrometers, Centimeters);
	UNIT_DEFINER(Micrometers, Meters);
	UNIT_DEFINER(Micrometers, Kilometers);
}

namespace Units::Millimeters
{
	using namespace Ratio;

	UNIT_DEFINER(Millimeters, Micrometers);
	UNIT_DEFINER(Millimeters, Centimeters);
	UNIT_DEFINER(Millimeters, Meters);
	UNIT_DEFINER(Millimeters, Kilometers);
}

namespace Units::Centimeters
{
	using namespace Ratio;

	UNIT_DEFINER(Centimeters, Micrometers);
	UNIT_DEFINER(Centimeters, Millimeters);
	UNIT_DEFINER(Centimeters, Meters);
	UNIT_DEFINER(Centimeters, Kilometers);
}

namespace Units::Meters
{
	using namespace Ratio;

	UNIT_DEFINER(Meters, Micrometers);
	UNIT_DEFINER(Meters, Millimeters);
	UNIT_DEFINER(Meters, Centimeters);
	UNIT_DEFINER(Meters, Kilometers);
}


namespace Units::Kilometers
{
	using namespace Ratio;

	UNIT_DEFINER(Kilometers, Micrometers);
	UNIT_DEFINER(Kilometers, Millimeters);
	UNIT_DEFINER(Kilometers, Centimeters);
	UNIT_DEFINER(Kilometers, Meters);
}
