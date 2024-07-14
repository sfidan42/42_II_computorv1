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

void	PolynomialSolver::_solve0(void)
{
	if (_polynomial[0] == 0)
		std::cout << GREEN << "All real numbers are solutions." << RESET << std::endl;
	else
		std::cout << GREEN << "There is no solution." << RESET << std::endl;
}

void	PolynomialSolver::_solve1(void)
{
	double	a;
	double	b;

	a = _polynomial[1];
	b = _polynomial[0];
	std::cout << GREEN << "The solution is: " << -b / a << RESET << std::endl;
}

void	PolynomialSolver::_solve2(void)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	x1;
	double	x2;

	a = _polynomial[2];
	b = _polynomial[1];
	c = _polynomial[0];
	delta = b * b - 4 * a * c;
	std::cout << CYAN << BOLD << "Delta: " << delta << RESET << std::endl;
	if (delta > 0)
	{
		x1 = (-b - sqrt(delta)) / (2 * a);
		x2 = (-b + sqrt(delta)) / (2 * a);
		std::cout << RED << "x1,2 = (-b +- sqrt(delta)) / (2 * a) " << RESET << std::endl;
		std::cout << GREEN << "Discriminant is strictly positive, the two solutions are: " << x1 << " and " << x2 << RESET << std::endl;
	}
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		std::cout << RED << "x1,2 = -b / (2 * a) " << std::endl;
		std::cout << GREEN << "Discriminant is equal to zero, the solution is: " << x1 << RESET << std::endl;
	}
	else
	{
		x1 = -b / (2 * a);
		x2 = sqrt(-delta) / (2 * a);
		std::cout << RED << "x1,2 = -b / (2 * a) +- i * sqrt(-delta) / (2 * a) " << std::endl;
		std::cout << GREEN << "Discriminant is strictly negative, the two solutions are: " << x1 << " - i" << x2 << " and " << x1 << " + i" << x2 << RESET << std::endl;
	}

}

void	PolynomialSolver::_solver(void)
{
	std::cout << CYAN << "Polynomial degree: " << _polynomial.getDegree() << RESET << std::endl;
	switch (_polynomial.getDegree())
	{
	case 0:
		_solve0();
		break;
	case 1:
		_solve1();
		break;
	case 2:
		_solve2();
		break;
	default:
		std::cerr << RED << "The polynomial degree is stricly greater than 2, I can't solve." << RESET << std::endl;
		break;
	}
}

void	PolynomialSolver::solvePolynomial(void)
{
	_parser();
	_printReducedForm();
	_solver();
}
