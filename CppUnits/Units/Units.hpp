#pragma once

#include <ratio>

#include "Resources.hpp"
#include "UnitsRatio.hpp"

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

#include "MOLength/Micrometers.hpp"
#include "MOLength/Millimeters.hpp"
#include "MOLength/Centimeters.hpp"
#include "MOLength/Meters.hpp"
#include "MOLength/Kilometers.hpp"

namespace Units
{
	using Micrometers_t		=	Micrometers::Micrometers;
	using Millimeters_t		=	Millimeters::Millimeters;
	using Centimeters_t		=	Centimeters::Centimeters;
	using Meters_t			=	Meters::Meters;
	using Kilometers_t		=	Kilometers::Kilometers;

	template<typename To, typename ToRatio, typename FromRatio, typename FromValue>
	inline constexpr To convert(const FromValue& fromValue)
	{
		return To(Ratio::castToSi<ToRatio>(fromValue()) / Ratio::castToSi<FromRatio>(1));
	}
}

namespace Units::Micrometers
{
	using namespace Ratio;
	inline Micrometers Micrometers::operator=(const Centimeters::Centimeters& centimeters) const
	{
		return convert<Micrometers_t, Micrometers_ratio, Centimeters_ratio, Centimeters_t>(centimeters);
	}

	inline Micrometers Micrometers::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return convert<Micrometers_t, Micrometers_ratio, Millimeters_ratio, Millimeters_t>(millimeters);
	}

	inline Micrometers Micrometers::operator=(const Meters::Meters& meters) const
	{
		return convert<Micrometers_t, Micrometers_ratio, Meters_ratio, Meters_t>(meters);
	}

	inline Micrometers Micrometers::operator=(const Kilometers::Kilometers& kilometers) const
	{
		return convert<Micrometers_t, Micrometers_ratio, Kilometers_ratio, Kilometers_t>(kilometers);
	}
}

namespace Units::Millimeters
{
	using namespace Ratio;
	inline Millimeters Millimeters::operator=(const Micrometers::Micrometers& micrometers) const
	{
		return convert<Millimeters_t, Millimeters_ratio, Micrometers_ratio, Micrometers_t>(micrometers);
	}

	inline Millimeters Millimeters::operator=(const Centimeters::Centimeters& centimeters) const
	{
		return convert<Millimeters_t, Millimeters_ratio, Centimeters_ratio, Centimeters_t>(centimeters);
	}

	inline Millimeters Millimeters::operator=(const Meters::Meters& meters) const
	{
		return convert<Millimeters_t, Millimeters_ratio, Meters_ratio, Meters_t>(meters);
	}

	inline Millimeters Units::Millimeters::Millimeters::operator=(const Kilometers::Kilometers& kilometers) const
	{
		return convert<Millimeters_t, Millimeters_ratio, Kilometers_ratio, Kilometers_t>(kilometers);
	}
}

namespace Units::Centimeters
{
	using namespace Ratio;
	inline Centimeters Centimeters::operator=(const Micrometers::Micrometers& micrometers) const
	{
		return convert<Centimeters_t, Centimeters_ratio, Micrometers_ratio, Micrometers_t>(micrometers);
	}

	inline Centimeters Centimeters::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return convert<Centimeters_t, Centimeters_ratio, Millimeters_ratio, Millimeters_t>(millimeters);
	}

	inline Centimeters Centimeters::operator=(const Meters::Meters& meters) const
	{
		return convert<Centimeters_t, Centimeters_ratio, Meters_ratio, Meters_t>(meters);
	}

	inline Centimeters Units::Centimeters::Centimeters::operator=(const Kilometers::Kilometers& kilometers) const
	{
		return convert<Centimeters_t, Centimeters_ratio, Kilometers_ratio, Kilometers_t>(kilometers);
	}
}

namespace Units::Meters
{
	using namespace Ratio;
	inline Meters Meters::operator=(const Micrometers::Micrometers& micrometers) const
	{
		return convert<Meters_t, Meters_ratio, Micrometers_ratio, Micrometers_t>(micrometers);
	}

	inline Meters Meters::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return convert<Meters_t, Meters_ratio, Millimeters_ratio, Millimeters_t>(millimeters);
	}

	inline Meters Meters::operator=(const Centimeters::Centimeters& centimeters) const
	{
		return convert<Meters_t, Meters_ratio, Centimeters_ratio, Centimeters_t>(centimeters);
	}

	inline Meters Units::Meters::Meters::operator=(const Kilometers::Kilometers& kilometers) const
	{
		return convert<Meters_t, Meters_ratio, Kilometers_ratio, Kilometers_t>(kilometers);
	}
}


namespace Units::Kilometers
{
	using namespace Ratio;
	inline Kilometers Kilometers::operator=(const Micrometers::Micrometers& micrometers) const
	{
		return convert<Kilometers_t, Kilometers_ratio, Micrometers_ratio, Micrometers_t>(micrometers);
	}

	inline Kilometers Kilometers::operator=(const Millimeters::Millimeters& millimeters) const
	{
		return convert<Kilometers_t, Kilometers_ratio, Millimeters_ratio, Millimeters_t>(millimeters);
	}

	inline Kilometers Units::Kilometers::Kilometers::operator=(const Centimeters::Centimeters& centimeters) const
	{
		return convert<Kilometers_t, Kilometers_ratio, Centimeters_ratio, Centimeters_t>(centimeters);
	}

	inline Kilometers Kilometers::operator=(const Meters::Meters& meters) const
	{
		return convert<Kilometers_t, Kilometers_ratio, Meters_ratio, Meters_t>(meters);
	}
}
