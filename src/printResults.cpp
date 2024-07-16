#include <PolynomialSolver.hpp>
#include <colors.h>
#include <sstream>

void printIrrFrac(const double &result)
{
	std::ostringstream	oss;
	std::string			resultStr;
	size_t				decimalPos;
	
	oss << result;
	resultStr = oss.str();
	decimalPos = resultStr.find('.');
	if (decimalPos != std::string::npos)
	{
		std::string wholePart = resultStr.substr(0, decimalPos);
		std::string decimalPart = resultStr.substr(decimalPos + 1);
		int numerator = std::stoi(wholePart + decimalPart);
		int denominator = std::pow(10, decimalPart.size());
		int gcd = std::__gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		std::cout << GREEN << numerator << "/" << denominator << RESET;
	}
	else
	{
		std::cout << resultStr;
	}
}

void	printResults(const complex_vector &results)
{
	std::cout << YELLOW << "The solutions are: " << RESET;
	for (std::pair<double, double> result : results)
	{
		printIrrFrac(result.first);
		if (result.second != 0)
		{
			if (result.second > 0)
				std::cout << " + ";
			else
				std::cout << " - ";
			printIrrFrac(result.second);
			std::cout << "i";
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}
