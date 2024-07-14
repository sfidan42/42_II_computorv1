#pragma once
# include <string>
# include <vector>
# include <iostream>

class Polynomial
{
private:
	std::string			_expression;
private:
	std::vector<double>	_coefficients;
	std::vector<double>	_results;
public:
	void				operator<<(std::string &expression);
	double				&operator[](size_t index);
	void				addResult(double result);
	std::string			getExpression(void);
	size_t				getDegree(void);
	std::vector<double>	getCoefficients(void);
	std::vector<double>	getResults(void);
};
