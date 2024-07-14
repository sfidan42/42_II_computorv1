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
			std::string			exp_num;
			std::string 		base;
			std::string 		exp;
			char				c;

			if (term.empty())
			{
				neg = true;
				continue ;
			}
			term_ss.clear();
			term_ss << term;
			term_ss >> coef >> op >> c >> c >> degree;
			if (isRight)
				coef = -coef;
			if (neg)
				coef = -coef;
			_polynomial[degree] += coef;
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
	right_ss << right;
	_parse(left_ss, false);
	_parse(right_ss, true);
}

void	PolynomialSolver::_printReducedForm(void)
{
	double				coef;
	std::vector<double>	coefficients;
	
	std::cout << RED << "Reduced form: ";
	coefficients = _polynomial.getCoefficients();
	for (int i = 0, n = coefficients.size(); i <= n; i++)
	{
		coef = coefficients[i];
		if (coef < 0)
		{
			std::cout << " - ";
			coef = -coef;
		}
		else if (i > 0)
			std::cout << " + ";
		std::cout << coef << "x^" << i;
	}
	std::cout << " = 0 " << RESET << std::endl;
}

void	PolynomialSolver::solvePolynomial(void)
{
	_parser();
	_printReducedForm();
}
