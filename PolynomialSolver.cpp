#include "PolynomialSolver.hpp"

void	PolynomialSolver::readPolynomial(std::string &polynomial)
{
	_polynomial << polynomial;
}

void	PolynomialSolver::_parser()
{
	std::string			left;
	std::string			right;
	std::string			term;
	std::string			terms;
	bool				neg;
	std::stringstream	ss;
	std::stringstream	left_ss;
	std::stringstream	right_ss;
	std::stringstream	terms_ss;
	std::stringstream	term_ss;

	ss << _polynomial.getExpression();
	std::getline(ss, left, '=');
	std::getline(ss, right, '=');
	left_ss << left;
	right_ss << right;
	while (std::getline(left_ss, terms, '+'))
	{
		neg = false;
		terms_ss.clear();
		terms_ss << terms;
		while (std::getline(terms_ss, term, '-'))
		{
			double				coef;
			int					degree;
			char				op;
			std::string			exp_num;
			std::string 		base;
			std::string 		exp;
			std::stringstream	exp_ss;

			term_ss.clear();
			term_ss << term;
			term_ss >> coef >> op >> exp_num;
			exp_ss.clear();
			exp_ss << exp_num;
			std::getline(exp_ss, base, '^');
			std::getline(exp_ss, exp, '^');
			degree = std::stoi(exp);
			_polynomial[degree] += neg ? -coef : coef;
			std::cout << "degree: " << degree << " coef: " << coef << std::endl;
			neg = true;
		}
	}
	while (std::getline(right_ss, terms, '+'))
	{
		neg = false;
		terms_ss.clear();
		terms_ss << terms;
		while (std::getline(terms_ss, term, '-'))
		{
			double				coef;
			int					degree;
			char				op;
			std::string			exp_num;
			std::string 		base;
			std::string 		exp;
			std::stringstream	exp_ss;

			term_ss.clear();
			term_ss << term;
			term_ss >> coef >> op >> exp_num;
			exp_ss.clear();
			exp_ss << exp_num;
			std::getline(exp_ss, base, '^');
			std::getline(exp_ss, exp, '^');
			degree = std::stoi(exp);
			coef = -coef;
			_polynomial[degree] += neg ? -coef : coef;
			neg = true;
		}
	}
}

void	PolynomialSolver::_printReducedForm(void)
{
	double	coef;

	std::cout << "Reduced form: ";
	if (_polynomial.getDegree() == 0)
	{
		std::cout << "0";
	}
	for (int i = 0; i <= _polynomial.getDegree(); i++)
	{
		coef = _polynomial[i];
		if (coef < 0)
		{
			std::cout << " - ";
			coef = -coef;
		}
		else if (i > 0)
			std::cout << " + ";
		std::cout << coef << " x^" << i;
	}
	std::cout << " = 0 " << std::endl;
}

void	PolynomialSolver::solvePolynomial(void)
{
	_parser();
	_printReducedForm();
}
