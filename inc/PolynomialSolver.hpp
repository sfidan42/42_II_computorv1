#pragma once
# include <Polynomial.hpp>
# include <sstream>
# include <iostream>
# include <math.h>
# include <algorithm>

typedef std::pair<double, double>	complex;

std::string	checkTerm(std::string &term);
void		printResults(const complex_vector &results);
complex		add(complex a, complex b);
complex		mult(complex a, complex b);

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
public:
	void	readPolynomial(std::string &polynomial);
	void	solvePolynomial(void);
};
