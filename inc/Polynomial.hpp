#pragma once
# include <string>
# include <vector>
# include <iostream>

class Polynomial
{
private:
	std::string			_expression;
private:
	int					_degree;
	std::vector<double>	_coefficients;
	std::vector<double>	_results;
public:
	void				operator<<(std::string &expression);
	double				&operator[](int index);
	void				addResult(double result);
	std::string			getExpression(void);
	int					getDegree(void);
	std::vector<double>	getCoefficients(void);
	std::vector<double>	getResults(void);
};
