#include "blackscholes.hpp"

BlackScholes::BlackScholes(double S0, double r, double sigma)
	:m_S0{ S0 }, m_r{ r }, m_sigma{ sigma }
{
}

double BlackScholes::generateTerminalPrice(double T, std::mt19937& gen, std::normal_distribution<>& dist) const
{
	double Z{ dist(gen) };
	double drift{ m_r - 0.5 * m_sigma * m_sigma };
	double diffusion{ m_sigma * std::sqrt(T) * Z };

	return m_S0 * std::exp(drift + diffusion);
}

double BlackScholes::generateTerminalPriceWithZ(double T, double Z) const
{
	double drift{ m_r - 0.5 * m_sigma * m_sigma };
	double diffusion{ m_sigma * std::sqrt(T) * Z };

	return m_S0 * std::exp(drift + diffusion);
}

double BlackScholes::getRate() const
{
	return m_r;
}
