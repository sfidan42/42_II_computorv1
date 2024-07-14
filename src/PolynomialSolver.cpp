#include <PolynomialSolver.hpp>
#include <colors.h>

void	PolynomialSolver::readPolynomial(std::string &polynomial)
{
	_polynomial << polynomial;
}

void	PolynomialSolver::_parse(std::stringstream &ss, bool isRight)
{
	bool				neg;
	std::string			term;
	std::stringstream	term_ss;
	std::string			terms;
	std::stringstream	terms_ss;

	while (std::getline(ss, terms, '+'))
	{
		neg = false;
		terms_ss.clear();
		terms_ss << terms;
		while (std::getline(terms_ss, term, '-'))
		{
			double				coef;
			size_t				degree;
			char				op;
			char				c;

			if (term.empty())
			{
				neg = true;
				continue ;
			}
			term_ss.clear();
			term_ss << term;
			if (!(term_ss >> coef >> op >> c >> c >> degree))
				continue ;
			if (neg)
				coef = -coef;
			if (isRight)
				coef = -coef;
			if (coef)
				_polynomial[degree] += coef;
			std::cout << YELLOW << coef << "x^" << degree << RESET << std::endl;
			neg = true;
		}
	}
}

void	PolynomialSolver::_parser()
{
	std::stringstream	ss;
	std::stringstream	left_ss;
	std::stringstream	right_ss;
	std::string			left;
	std::string			right;

	ss << _polynomial.getExpression();
	std::getline(ss, left, '=');
	std::getline(ss, right, '=');
	left_ss << left;
	right.erase(right.begin());
	right_ss << right;
	std::cout << BLUE << "Left:__" << left << "__" << RESET << std::endl;
	std::cout << BLUE << "Right:__" << right << "__" << RESET << std::endl;
	_parse(left_ss, false);
	_parse(right_ss, true);
	_polynomial.clearZeroes();
}

void	PolynomialSolver::_printReducedForm(void)
{
	double				coef;
	std::vector<double>	coefficients;
	
	std::cout << GREEN << "Reduced form: ";
	coefficients = _polynomial.getCoefficients();
	for (size_t i = coefficients.size() - 1; i != (size_t)-1; i--)
	{
		coef = coefficients[i];
		if (coef == 0)
			continue ;
		if (coef < 0)
		{
			std::cout << " - ";
			coef = -coef;
		}
		else
			std::cout << " + ";
		if (i == 0)
			std::cout << coef;
		else if (i == 1)
			std::cout << coef << "x";
		else
			std::cout << coef << "x^" << i;
	}
	std::cout << " = 0 " << RESET << std::endl;
}

void	PolynomialSolver::solvePolynomial(void)
{
	_parser();
	_printReducedForm();
	std::cout << CYAN << "Polynomial degree: " << _polynomial.getDegree() << RESET << std::endl;
	if (_polynomial.getDegree() > 2)
	{
		std::cout << RED << "The polynomial degree is stricly greater than 2, I can't solve." << RESET << std::endl;
		return ;
	}
}
