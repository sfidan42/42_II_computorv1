#include <complex.hpp>

std::ostream	&operator<<(std::ostream &os, complex &num)
{
	os << num.first;
	if (-0.00001 < num.second && num.second < 0.00001)
		return os;
	if (num.second > 0)
		os << "+";
	os << num.second << "i";
	return os;
}

complex	mult(complex a, complex b)
{
	complex	num;

	// (a + bi) * (c + di) = ac + adi + bci + bdi^2
	// = ac + adi + bci - bd = (ac - bd) + (ad + bc)i
	// = (a.f b.f - a.s b.s) + (a.f b.s + a.s b.f) i

	num.first = a.first * b.first - a.second * b.second;
	num.second = a.first * b.second + a.second * b.first;
	return (num);
}

complex	add(complex a, complex b)
{
	complex	num;

	num.first = a.first + b.first;
	num.second = a.second + b.second;
	return (num);
}
