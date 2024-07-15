#include "PolynomialSolver.hpp"
#include <colors.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"polynomial\"" << std::endl;
		return (1);
	}
	try
	{
		std::string			polynomial(argv[1]);
		PolynomialSolver	polynomialSolver;

		polynomialSolver.readPolynomial(polynomial);
		polynomialSolver.solvePolynomial();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
