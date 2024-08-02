SRC		=	complex.cpp \
			checkTerm.cpp \
			Polynomial.cpp \
			PolynomialSolver.cpp \
			myMath.cpp

OBJ		=	$(addprefix bin/, ${SRC:.cpp=.o})
NAME	=	libcomputorv1.a
CC		=	c++ -Wall -Wextra -Werror -m64 -g -Iinc

all: ${NAME} test

test: ${NAME}
	@echo "---------------01-------------------"
	./poly "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
	@echo "---------------02-------------------"
	./poly "5 * X^0 + 4 * X^1 = 4 * X^0"
	@echo "---------------03-------------------"
	./poly "- 5 * X^0 + 4 * X^1 = 4 * X^0"
	@echo "---------------04-------------------"
	./poly "- 5 * X^0 + 4 * X^1 = - 4 * X^0"
	@echo "---------------05-------------------"
	./poly "- 5 * X^0 + 4 * X^1 = 4 * X^1"
	@echo "---------------06-------------------"
	./poly "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0"
	@echo "---------------07-------------------"
	./poly "8 * X^0 - 6 * X^1 = - 0 * X^2 - 5.6 * X^3 + 3 * X^0"
	@echo "---------------08-------------------"
	./poly "8 * X^0 - 6 * X^1 = - 0 * X^2 - 5.6 * X^3 + 3 * X^0"
	@echo "---------------09-------------------"
	./poly "5 * X^0 = 5 * X^0"
	@echo "---------------10-------------------"
	./poly "X = 6"
	@echo "---------------11-------------------"
	./poly "5 = 6 + 4 * X^0 - 9.3 * X^2 + 3X + X - X + X ^2 - 1    X ^  1"
	@echo "---------------12-------------------"
	./poly "X^2-4=0"
	@echo "----------------13-------------------"
	./poly "X^2+2=0"
	@echo "----------------14------------------"
	./poly "0.5X^2-0.25X+1=0"
	@echo "----------------15------------------"
	./poly "X^2-4X = 0"
	@echo "----------------16------------------"
	./poly "X^3-4X = 0"
	@echo "----------------17------------------"
	./poly "5 = 0"
	@echo "----------------18------------------"
	./poly "a^2-4a = 0"
	@echo "----------------19------------------"
	./poly "a2^2 = 0"
	@echo "----------------20------------------"
	./poly "adasd1"
	@echo "----------------21------------------"
	./poly ""
	@echo "----------------22------------------"
	./poly "abc = 123"
	@echo "----------------23------------------"
	./poly "aX^b = 123"
	@echo "----------------24------------------"
	./poly "X^2"
	@echo "----------------25------------------"
	./poly "="

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

.PHONY: all clean fclean re test
