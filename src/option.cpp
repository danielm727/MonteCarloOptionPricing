#include "option.hpp"
#include <algorithm>

Option::Option(double strike, double expiry, OptionType type)
	:m_strike{ strike }, m_expiry{ expiry }, m_type{ type }
{
}

double Option::payoff(double ST) const
{
	return (m_type == OptionType::Call) ? std::max(ST - m_strike, 0.0) : std::max(m_strike - ST, 0.0);
}

double Option::getExpiry() const
{
	return m_expiry;
}


