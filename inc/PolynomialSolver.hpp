#pragma once
# include <checkTerm.hpp>
# include <complex.hpp>
# include <Polynomial.hpp>
# include <myMath.h>
# include <sstream>
# include <iostream>

class PolynomialSolver
{
private:
	Polynomial	_polynomial;
private:
	void	_parse(std::stringstream &ss, bool isRight);
	void	_parser(void);
	void	_printReducedForm(void);
	void	_solve0(void);
	void	_solve1(void);
	void	_solve2(void);
	void	_solver(void);
	void	_checker(void);
	void	_printResults(void);
public:
	void	readPolynomial(std::string &polynomial);
	void	solvePolynomial(void);
};
