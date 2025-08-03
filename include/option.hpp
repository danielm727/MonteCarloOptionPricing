#pragma once

enum class OptionType { Call, Put };

class Option
{
public:
	Option(double strike, double expiry, OptionType type);
	double payoff(double ST) const;
	double getExpiry() const;

private:
	double m_strike{};
	double m_expiry{};
	OptionType m_type{};
};