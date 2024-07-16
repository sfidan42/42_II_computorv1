#include <PolynomialSolver.hpp>

std::string ltrim(const std::string &s) {
    std::string result = s;
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return result;
}

std::string rtrim(const std::string &s) {
    std::string result = s;
    result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), result.end());
    return result;
}

std::string trim(const std::string &s) {
    return ltrim(rtrim(s));
}

std::string	checkTerm(std::string &term)
{
	std::stringstream	term_ss(term);

	if (term.find("X") == std::string::npos)
	{
		try
		{
			std::stod(term);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error("(if) Invalid term:__" + term + "__");
		}
		return (term + " * X^0");
	}
	else
	{
		std::string	coef;
		std::string	degree;
		std::getline(term_ss, coef, 'X');
		std::getline(term_ss, degree, 'X');
		coef = trim(coef);
		degree = trim(degree);
		size_t	i = coef.length() - 1;
		if (coef[i] == '*')
		{
			coef.erase(coef.begin() + i);
			coef = trim(coef);
		}
		if (coef == "" || coef == "+")
			coef = "1";
		else if (coef == "-")
			coef = "-1";
		if (degree[0] == '^')
			degree.erase(degree.begin());
		if (degree == "")
			degree = "1";
		try
		{
			std::stod(coef);
			std::stod(degree);
		}
		catch (const std::exception& e)
		{
			throw std::runtime_error("(else) Invalid term:__" + term + "__");
		}
		return (coef + " * X^" + degree);
	}
}
