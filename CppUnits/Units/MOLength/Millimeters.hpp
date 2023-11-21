#pragma once
#include <string>

#include "../BaseUnit.hpp"

#include "../Units.hpp"

namespace Units::Millimeters
{
	using namespace Units;
	using namespace Units::Resources;

	class Millimeters : public BaseUnit::BaseUnit
	{
	public:
		Millimeters() = default;
		explicit Millimeters(const Variant& variant)
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

		inline Millimeters operator=(const Micrometers::Micrometers& micrometers) const;
		inline Millimeters operator=(const Centimeters::Centimeters& centimeters) const;
		inline Millimeters operator=(const Meters::Meters& meters) const;
		inline Millimeters operator=(const Kilometers::Kilometers& kilometers) const;

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

		template<typename T = Float128>
		inline const T& operator()(void) const
		{
			return static_cast<const T&>(Value_);
		}

		//-----------------------------------------------------------------------

		friend std::ostream& operator<<(std::ostream& stream, const Millimeters& millimeters) {
			stream << millimeters.Value_;
			return stream;
		}

		friend std::istream& operator>>(std::istream& stream, const Millimeters& millimeters) {
			std::string in;
			stream >> in;
			Value_ = std::stold(in);
			return stream;
		}

		inline Millimeters operator+(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Millimeters(Value_ + getValue);
		}
		inline Millimeters operator+=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Millimeters(Value_ + getValue);
		}

		inline Millimeters operator-(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Millimeters(Value_ - getValue);
		}
		inline Millimeters operator-=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Millimeters(Value_ - getValue);
		}

		inline Millimeters operator/(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Millimeters(Value_ / getValue);
		}
		inline Millimeters operator/=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Millimeters(Value_ / getValue);
		}

		inline Millimeters operator*(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Millimeters(Value_ * getValue);
		}
		inline Millimeters operator*=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Millimeters(Value_ * getValue);
		}

		//-----------------------------------------------------------------------

		compl Millimeters() override = default;

	private:
		inline static Float128 Value_ = 0;
	};
}
