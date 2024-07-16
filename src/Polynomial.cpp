#include <Polynomial.hpp>

double	&Polynomial::operator[](size_t index)
{
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

void				Polynomial::addResult(double r, double i) { _results.emplace_back(r, i); }
complex_vector		Polynomial::getResults(void) { return (_results); }
std::string			Polynomial::getExpression(void) { return (_expression); }
size_t				Polynomial::getDegree(void){ return (_coefficients.size() - 1); }
std::vector<double>	Polynomial::getCoefficients(void) { return (_coefficients); }

void	Polynomial::clearZeroes(void)
{
	size_t	i;

	while (true)
	{
		i = _coefficients.size() - 1;
		if (i == (size_t)-1)
			return ;
		if (-0.0000001 < _coefficients[i] && _coefficients[i] < 0.0000001)
			_coefficients.pop_back();
		else
			break ;
	}
	i = this->getDegree();
	if (!(0 < i && i <= 3))
		return ;
	while (true)
	{
		if (-0.0000001 < _coefficients[0] && _coefficients[0] < 0.0000001)
			_coefficients.erase(_coefficients.begin());
		else
			break ;
		std::cout << "the polynomial is divided by X. So X = 0 is a solution." << std::endl;
	}
}
