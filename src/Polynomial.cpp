#include <Polynomial.hpp>

double	&Polynomial::operator[](size_t index)
{
	std::cout << "degree: " << index << std::endl;
	std::cout << "_coefficients.size(): " << _coefficients.size() << std::endl;
	while (_coefficients.size() <= index)
		_coefficients.push_back(0);
	return (_coefficients[index]);
}

void	Polynomial::operator<<(std::string &expression)
{
	_coefficients.clear();
	_results.clear();
	_expression = expression;
}

void				Polynomial::addResult(double result) { _results.push_back(result); }
std::string			Polynomial::getExpression(void) { return (_expression); }
size_t				Polynomial::getDegree(void) { return (_coefficients.size() - 1); }
std::vector<double>	Polynomial::getCoefficients(void) { return (_coefficients); }
