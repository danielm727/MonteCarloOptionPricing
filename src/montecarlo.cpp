#include "montecarlo.hpp"

MonteCarlo::MonteCarlo(int numPaths)
	:m_numPaths{ numPaths }
{
}

double MonteCarlo::price(const Option& option, const BlackScholes& model)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> dist(0.0, 1.0);

	double totalPayoff{};
	double T{ option.getExpiry() };

	for (int i{}; i < m_numPaths; ++i)
	{
		double ST{ model.generateTerminalPrice(T, gen, dist) };

		totalPayoff += option.payoff(ST);
	}

	double avgPayoff{ totalPayoff / m_numPaths };
	return std::exp(-model.getRate() * T) * avgPayoff;
}

