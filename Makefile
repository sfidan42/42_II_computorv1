SRC		=	Polynomial.cpp \
			PolynomialSolver.cpp
		
OBJ		=	$(addprefix bin/, ${SRC:.cpp=.o})
NAME	=	libcomputorv1.a
CC		=	c++ -Wall -Wextra -Werror -m64 -g -Iinc

all: ${NAME}
	@echo
	./poly "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
	@echo
	./poly "5 * X^0 + 4 * X^1 = 4 * X^0"
	@echo
	./poly "- 5 * X^0 + 4 * X^1 = 4 * X^0"
	@echo
	./poly "- 5 * X^0 + 4 * X^1 = - 4 * X^0"
	@echo
	./poly "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
	@echo

bin/%.o: src/%.cpp | bin
	${CC} -c $< -o $@

bin:
	mkdir bin

${NAME}: ${OBJ} main.cpp
	ar rcs ${NAME} ${OBJ}
	${CC} main.cpp -L. -lcomputorv1 -o poly

clean:
	rm -f ./poly ${OBJ}

fclean: clean
	rm -f ${NAME}
	rm -rf bin

re: fclean all

.PHONY: all clean fclean re
