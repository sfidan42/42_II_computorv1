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
			std::cout << CYAN << term << " --> " << RESET;
			term = checkTerm(term);
			std::cout << CYAN << term << " --> " << RESET;
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
	size_t				degree;
	double				coef;
	std::vector<double>	coefficients;
	
	std::cout << GREEN << "Reduced form: ";
	degree = _polynomial.getDegree();
	coefficients = _polynomial.getCoefficients();
	for (size_t i = degree; i != (size_t)-1; i--)
	{
		coef = coefficients[i];
		if (coef == 0 && i != 0)
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
	std::cout << GREEN << "No need to check solutions" << RESET << std::endl;
}

void	PolynomialSolver::_solve1(void)
{
	double	a;
	double	b;

	a = _polynomial[1];
	b = _polynomial[0];
	_polynomial.addResult(-b / a);
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
		_polynomial.addResult(x1);
		_polynomial.addResult(x2);
		std::cout << RED << "x1,2 = (-b +- sqrt(delta)) / (2 * a) " << RESET << std::endl;
		std::cout << GREEN << "Discriminant is strictly positive, the two solutions are: " << x1 << " and " << x2 << RESET << std::endl;
	}
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		_polynomial.addResult(x1);
		std::cout << RED << "x1,2 = -b / (2 * a) " << std::endl;
		std::cout << GREEN << "Discriminant is equal to zero, the solution is: " << x1 << RESET << std::endl;
	}
	else
	{
		x1 = -b / (2 * a);
		x2 = sqrt(-delta) / (2 * a);
		_polynomial.addResult(x1, x2);
		_polynomial.addResult(x1, -x2);
		std::cout << RED << "x1,2 = -b / (2 * a) +- i * sqrt(-delta) / (2 * a) " << std::endl;
		std::cout << GREEN << "Discriminant is strictly negative, the two solutions are: " << x1 << " - i" << x2 << " and " << x1 << " + i" << x2 << RESET << std::endl;
	}
}

typedef void (PolynomialSolver::*solver)(void);

void	PolynomialSolver::_solver(void)
{
	size_t	degree;
	solver	solvers[3];
	
	degree = _polynomial.getDegree();
	std::cout << CYAN << "Polynomial degree: " << degree << RESET << std::endl;
	solvers[0] = &PolynomialSolver::_solve0;
	solvers[1] = &PolynomialSolver::_solve1;
	solvers[2] = &PolynomialSolver::_solve2;
	if (degree == (size_t)-1)
		_polynomial[0] = 0;
	if (degree > 2)
		throw std::runtime_error("The polynomial degree is stricly greater than 2, I can't solve.");
	(this->*solvers[degree])();
}

void printIrrFrac(const double &result)
{
	std::ostringstream	oss;
	std::string			resultStr;
	size_t				decimalPos;
	
	oss << result;
	resultStr = oss.str();
	decimalPos = resultStr.find('.');
	if (decimalPos != std::string::npos)
	{
		std::string wholePart = resultStr.substr(0, decimalPos);
		std::string decimalPart = resultStr.substr(decimalPos + 1);
		int numerator = std::stoi(wholePart + decimalPart);
		int denominator = pow(10, decimalPart.size());
		int gcd = std::__gcd(numerator, denominator);
		numerator /= gcd;
		denominator /= gcd;
		std::cout << GREEN << numerator << "/" << denominator << RESET;
	}
	else
	{
		std::cout << resultStr;
	}
}

void	PolynomialSolver::_printResults(void)
{
	complex_vector	results;

	results = _polynomial.getResults();
	std::cout << YELLOW << "The solutions are: " << RESET;
	for (complex result : results)
	{
		printIrrFrac(result.first);
		if (result.second != 0)
		{
			if (result.second > 0)
				std::cout << " + ";
			else
				std::cout << " - ";
			printIrrFrac(result.second);
			std::cout << "i";
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}

void	PolynomialSolver::_checker(void)
{
	complex				ans;
	std::vector<double>	coefficients;
	complex_vector		results;

	coefficients = _polynomial.getCoefficients();
	results = _polynomial.getResults();
	for (complex result : results)
	{
		std::cout << BLUE << "solve for: " << result.first << " + " << result.second << "i" << RESET << std::endl;
		ans = {0, 0};
		complex	num = {1, 0};
		complex term;
		for (double coef : coefficients)
		{
			if (coef)
			{
				term = mult(num, {coef, 0});
				std::cout << YELLOW << "term: " << coef << " * (" << num << ") = " << term << RESET << std::endl;
				ans = add(ans, term);
			}
			num = mult(num, result);
		}
		if (-0.00001 < ans.first && ans.first < 0.00001)
			ans.first = 0;
		if (-0.00001 < ans.second && ans.second < 0.00001)
			ans.second = 0;
		std::cout << MAGENTA << "sum of these: " << ans << RESET << std::endl;
		if (-0.000001 < ans.first && ans.first < 0.000001 && -0.000001 < ans.second && ans.second < 0.000001)
		{
			std::cout << GREEN << "The solution is correct." << RESET << std::endl;
			continue ;
		}
		throw std::runtime_error("The solution is not correct.");
	}
}

void	PolynomialSolver::solvePolynomial(void)
{
	_parser();
	_printReducedForm();
	_solver();
	_printResults();
	_checker();
}
