#include "Polynomial.hpp"

double	&Polynomial::operator[](int index)
{
	if (index < 0)
		throw (std::out_of_range("Index out of range"));
	if (index > _degree)
		while (index > _degree++)
			_coefficients.push_back(0);
	return (_coefficients[index]);
}

void	Polynomial::operator<<(std::string &expression)
{
	_coefficients.clear();
	_coefficients.push_back(0);
	_results.clear();
	_degree = 0;
	_expression = expression;
}

void				Polynomial::addResult(double result) { _results.push_back(result); }
std::string			Polynomial::getExpression(void) { return _expression; }
int					Polynomial::getDegree(void) { return _degree; }
std::vector<double>	Polynomial::getCoefficients(void) { return _coefficients; }
