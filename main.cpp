#include <iostream>
#include "option.hpp"
#include "blackscholes.hpp"
#include "montecarlo.hpp"

int main()
{
	double S0{ 100.0 };
	double K{ 100.0 };
	double r{ 0.05 };
	double sigma{ 0.2 };
	double T{ 1.0 };
	int numPaths{ 1000000 };

	Option callOption(K, T, OptionType::Call);
	BlackScholes model(S0, r, sigma);
	MonteCarlo engine(numPaths);

	double price{ engine.price(callOption, model) };
	std::cout << "European call option price: " << price << '\n';

	return 0;
}