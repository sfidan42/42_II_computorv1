#pragma once
# include <string>
# include <vector>
# include <iostream>

typedef std::vector<std::pair<double, double>> complex_vector;

class Polynomial
{
private:
	std::string			_expression;
private:
	std::vector<double>	_coefficients;
	complex_vector		_results;
public:
	void				operator<<(std::string &expression);
	double				&operator[](size_t index);
	void				addResult(double r, double i = 0);
	complex_vector		getResults(void);
	std::string			getExpression(void);
	size_t				getDegree(void);
	std::vector<double>	getCoefficients(void);
	void				clearZeroes(void);
};
