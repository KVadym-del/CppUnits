#pragma once
#include <variant>

namespace Units::Resources
{
	using Float128 = long double;
	using Float64 = double;

	using Int64 = long long;
	using Int32 = int;
	using Int16 = short;
	using Int8 = signed char;
	using Variant = std::variant<Int64, Int32, Int16, Int8, Float128, Float64>;
}

