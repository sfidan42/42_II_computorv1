#include "PolynomialSolver.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"polynomial\"" << std::endl;
		return (1);
	}
	std::string			polynomial;
	PolynomialSolver	polynomialSolver;

	polynomial = argv[1];
	polynomialSolver.readPolynomial(polynomial);
	polynomialSolver.solvePolynomial();
	return (0);
}
