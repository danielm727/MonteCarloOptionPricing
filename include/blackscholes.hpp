#pragma once
#include <random>

class BlackScholes
{
public:
	BlackScholes(double S0, double r, double sigma);
	double generateTerminalPrice(double T, std::mt19937& gen, std::normal_distribution<>& dist) const;
	double generateTerminalPriceWithZ(double T, double Z) const;
	double getRate() const;

private:
	double m_S0{};
	double m_r{};
	double m_sigma{};
};