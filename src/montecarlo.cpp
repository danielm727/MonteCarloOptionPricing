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

	for (int i{}; i < m_numPaths / 2; ++i)
	{
		double Z{ dist(gen) };
		double ST1{ model.generateTerminalPriceWithZ(T, Z) };
		double ST2{ model.generateTerminalPriceWithZ(T, -Z) };

		totalPayoff += 0.5*(option.payoff(ST1)+option.payoff(ST2));
	}

	double avgPayoff{ totalPayoff / (m_numPaths / 2) };
	return std::exp(-model.getRate() * T) * avgPayoff;
}

