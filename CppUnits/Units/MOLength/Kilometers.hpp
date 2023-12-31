#pragma once
#include <string>

#include "../BaseUnit.hpp"

#include "../Units.hpp"

namespace Units::Kilometers
{
	using namespace Units;
	using namespace Units::Resources;
	class Kilometers : public BaseUnit::BaseUnit
	{
	public:
		Kilometers() = default;
		explicit Kilometers(const Variant& variant)
		{
			std::visit([&](const auto& value) {
				Value_ = static_cast<Float128>(value);
				}, variant);
		};

		inline constexpr void operator=(const Variant& variant) const override
		{
			std::visit([&](const auto& value) {
				Value_ = static_cast<Float128>(value);
				}, variant);
		}

		inline Kilometers operator=(const Micrometers::Micrometers& micrometers) const;
		inline Kilometers operator=(const Millimeters::Millimeters& millimeters) const;
		inline Kilometers operator=(const Centimeters::Centimeters& centimeters) const;
		inline Kilometers operator=(const Meters::Meters& meters) const;

		inline bool operator==(const Variant& variant) const override
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Value_ == getValue;
		}

		inline bool operator!=(const Variant& variant) const override
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Value_ != getValue;
		}

		inline void operator()(const Variant& variant) const override
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			Value_ = getValue;
		}

		inline operator const Float128* (void) const override
		{
			return static_cast<const Float128*>(&Value_);
		}

		//-----------------------------------------------------------------------

		friend std::ostream& operator<<(std::ostream& stream, const Kilometers& centimeters) {
			stream << centimeters.Value_;
			return stream;
		}

		friend std::istream& operator>>(std::istream& stream, const Kilometers& centimeters) {
			std::string in;
			stream >> in;
			Value_ = std::stold(in);
			return stream;
		}

		inline Kilometers operator+(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Kilometers(Value_ + getValue);
		}
		inline Kilometers operator+=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Kilometers(Value_ + getValue);
		}


		inline Kilometers operator-(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Kilometers(Value_ - getValue);
		}
		inline Kilometers operator-=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Kilometers(Value_ - getValue);
		}

		inline Kilometers operator/(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Kilometers(Value_ / getValue);
		}
		inline Kilometers operator/=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Kilometers(Value_ / getValue);
		}

		inline Kilometers operator*(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Kilometers(Value_ * getValue);
		}
		inline Kilometers operator*=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Kilometers(Value_ * getValue);
		}

		//-----------------------------------------------------------------------

		compl Kilometers() override = default;

	private:
		inline static Float128 Value_ = 0;
	};
}
