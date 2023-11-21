#pragma once

#include <string>

#include "../BaseUnit.hpp"

#include "../Units.hpp"

namespace Units::Meters
{
	using namespace Units;
	using namespace Units::Resources;

	class Meters : public BaseUnit::BaseUnit
	{
	public:
		Meters() = default;
		explicit Meters(const Variant& variant)
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

		inline Meters operator=(const Millimeters::Millimeters& millimeters) const; // <-
		inline Meters operator=(const Centimeters::Centimeters& centimeters) const; // <-
		inline Meters operator=(const Kilometers::Kilometers& centimeters) const; // <-

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

		friend std::ostream& operator<<(std::ostream& stream, const Meters& mters) {
			stream << mters.Value_;
			return stream;
		}

		friend std::istream& operator>>(std::istream& stream, const Meters& mters) {
			std::string in;
			stream >> in;
			Value_ = std::stold(in);
			return stream;
		}

		inline Meters operator+(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Meters(Value_ + getValue);
		}
		inline Meters operator+=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Meters(Value_ + getValue);
		}

		inline Meters operator-(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Meters(Value_ - getValue);
		}
		inline Meters operator-=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Meters(Value_ - getValue);
		}

		inline Meters operator/(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Meters(Value_ / getValue);
		}
		inline Meters operator/=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Meters(Value_ / getValue);
		}

		inline Meters operator*(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Meters(Value_ * getValue);
		}
		inline Meters operator*=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Meters(Value_ * getValue);
		}

		//-----------------------------------------------------------------------

		compl Meters() override = default;

	private:
		inline static Float128 Value_ = 0;
	};
}
