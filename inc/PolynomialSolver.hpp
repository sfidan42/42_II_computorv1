#pragma once
# include <Polynomial.hpp>
# include <sstream>
# include <iostream>
# include <math.h>

class PolynomialSolver
{
private:
	Polynomial	_polynomial;
	bool		_isSolved;
private:
	void	_parse(std::stringstream &ss, bool isRight);
	void	_parser(void);
	void	_printReducedForm(void);
	void	_solve0(void);
	void	_solve1(void);
	void	_solve2(void);
	void	_solver(void);
public:
	void	readPolynomial(std::string &polynomial);
	void	solvePolynomial(void);
	void	printSolution(void);
};
