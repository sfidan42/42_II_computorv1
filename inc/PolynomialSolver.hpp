#pragma once
# include <Polynomial.hpp>
# include <sstream>
# include <iostream>

class PolynomialSolver
{
private:
	Polynomial	_polynomial;
	bool		_isSolved;
private:
	void	_parse(std::stringstream &ss, bool isRight);
	void	_parser(void);
	void	_printReducedForm(void);
public:
	void	readPolynomial(std::string &polynomial);
	void	solvePolynomial(void);
	void	printSolution(void);
};
