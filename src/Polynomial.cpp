#include <Polynomial.hpp>

double	&Polynomial::operator[](size_t index)
{
	//std::cout << "degree: " << index << std::endl;
	//std::cout << "_coefficients.size(): " << _coefficients.size() << std::endl;
	while (_coefficients.size() <= index)
		_coefficients.push_back(0);
	return (_coefficients[index]);
}

void	Polynomial::operator<<(std::string &expression)
{
	_coefficients.clear();
	_expression = expression;
}

std::string			Polynomial::getExpression(void) { return (_expression); }
size_t				Polynomial::getDegree(void) { return (_coefficients.size() - 1); }
std::vector<double>	Polynomial::getCoefficients(void) { return (_coefficients); }

void	Polynomial::clearZeroes(void)
{
	size_t	i;

	i = _coefficients.size();
	while (i--)
	{
		if (-0.0000001 < _coefficients[i] && _coefficients[i] < 0.0000001)
			_coefficients.pop_back();
		else
			break ;
	}
}
