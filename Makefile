all:
	c++ -Wall -Wextra -Werror -o poly main.cpp Polynomial.cpp PolynomialSolver.cpp

test: all
	./poly "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
	./poly "5 * X^0 + 4 * X^1 = 4 * X^0"
	./poly "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"

clean:
	rm -f poly