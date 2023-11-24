#pragma once
#include <string>

#include "../BaseUnit.hpp"

#include "../Units.hpp"

namespace Units::Micrometers
{
	using namespace Units;
	using namespace Units::Resources;

	class Micrometers : public BaseUnit::BaseUnit
	{
	public:
		Micrometers() = default;
		explicit Micrometers(const Variant& variant)
		{
			std::visit([&](const auto& value) {
				Value_ = static_cast<Float128>(value);
				}, variant);
		}

		inline constexpr void operator=(const Variant& variant) const override
		{
			std::visit([&](const auto& value) {
				Value_ = static_cast<Float128>(value);
				}, variant);
		}

		inline Micrometers operator=(const Millimeters::Millimeters& millimeters) const;
		inline Micrometers operator=(const Centimeters::Centimeters& centimeters) const;
		inline Micrometers operator=(const Meters::Meters& meters) const;
		inline Micrometers operator=(const Kilometers::Kilometers& kilometers) const;

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

		friend std::ostream& operator<<(std::ostream& stream, const Micrometers& Micrometers) {
			stream << Micrometers.Value_;
			return stream;
		}

		friend std::istream& operator>>(std::istream& stream, const Micrometers& Micrometers) {
			std::string in;
			stream >> in;
			Value_ = std::stold(in);
			return stream;
		}

		inline Micrometers operator+(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Micrometers(Value_ + getValue);
		}
		inline Micrometers operator+=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Micrometers(Value_ + getValue);
		}

		inline Micrometers operator-(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Micrometers(Value_ - getValue);
		}
		inline Micrometers operator-=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Micrometers(Value_ - getValue);
		}

		inline Micrometers operator/(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Micrometers(Value_ / getValue);
		}
		inline Micrometers operator/=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Micrometers(Value_ / getValue);
		}

		inline Micrometers operator*(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Micrometers(Value_ * getValue);
		}
		inline Micrometers operator*=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Micrometers(Value_ * getValue);
		}

		//-----------------------------------------------------------------------

		compl Micrometers() override = default;

	private:
		inline static Float128 Value_ = 0;
	};
}
