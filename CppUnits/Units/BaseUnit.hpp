#pragma once

#include "Resources.hpp"

namespace Units::BaseUnit
{
	using namespace Units::Resources;
	class BaseUnit
	{
	public:
		virtual ~BaseUnit() = default;

		virtual inline constexpr void operator=(const Variant& variant) const = 0;

		virtual inline bool operator==(const Variant& variant) const = 0;

		virtual inline bool operator!=(const Variant& variant) const = 0;

		virtual inline void operator()(const Variant& variant) const = 0;
	};
}
