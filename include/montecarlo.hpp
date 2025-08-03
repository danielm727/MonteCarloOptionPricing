#pragma once
#include "option.hpp"
#include "blackscholes.hpp"

class MonteCarlo
{
public:
	MonteCarlo(int numPaths);
	double price(const Option& option, const BlackScholes& model);

private:
	int m_numPaths{};
};