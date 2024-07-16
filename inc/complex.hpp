#pragma once
#include <utility>
#include <iostream>

typedef std::pair<double, double>	complex;

complex	mult(complex a, complex b);
complex	add(complex a, complex b);
std::ostream	&operator<<(std::ostream &os, complex &num);
