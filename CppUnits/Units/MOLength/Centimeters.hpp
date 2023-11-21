#pragma once
#include <string>

#include "../BaseUnit.hpp"

#include "../Units.hpp"

namespace Units::Centimeters
{
	using namespace Units;
	using namespace Units::Resources;

	class Centimeters : public BaseUnit::BaseUnit
	{
	public:
		Centimeters() = default;
		explicit Centimeters(const Variant& variant)
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

		inline Centimeters operator=(const Millimeters::Millimeters& millimeters) const;
		inline Centimeters operator=(const Meters::Meters& meters) const;
		inline Centimeters operator=(const Kilometers::Kilometers& kilometers) const;

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
		
		/*
		template<typename T = Float128>
		inline operator T(void) const
		{
			return static_cast<const T&>(Value_);
		}
		*/

		//-----------------------------------------------------------------------

		friend std::ostream& operator<<(std::ostream& stream, const Centimeters& centimeters) {
			stream << centimeters.Value_;
			return stream;
		}

		friend std::istream& operator>>(std::istream& stream, const Centimeters& centimeters) {
			std::string in;
			stream >> in;
			Value_ = std::stold(in);
			return stream;
		}

		inline Centimeters operator+(const Variant& variant) const 
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Centimeters(Value_ + getValue);
		}
		inline Centimeters operator+=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Centimeters(Value_ + getValue);
		}

		inline Centimeters operator-(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Centimeters(Value_ - getValue);
		}
		inline Centimeters operator-=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return  Centimeters(Value_ - getValue);
		}

		inline Centimeters operator/(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Centimeters(Value_ / getValue);
		}
		inline Centimeters operator/=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Centimeters(Value_ / getValue);
		}

		inline Centimeters operator*(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Centimeters(Value_ * getValue);
		}
		inline Centimeters operator*=(const Variant& variant) const
		{
			Float128 getValue;
			std::visit([&](const auto& value) {
				getValue = static_cast<Float128>(value);
				}, variant);
			return Centimeters(Value_ * getValue);
		}

		//-----------------------------------------------------------------------

		compl Centimeters() override = default;

	private:
		inline static Float128 Value_ = 0;
	};
}
