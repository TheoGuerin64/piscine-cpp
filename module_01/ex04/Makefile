SRC_MAIN :=	main.cpp
SRC_TEST :=	tester.cpp \
			Test.cpp

OBJS_MAIN =	${SRC_MAIN:.cpp=.o}
OBJS_TEST =	${SRC_TEST:.cpp=.o}
MAIN :=		replace
TEST :=		test
FLAGS :=	-g3 -std=c++98 -Wall -Werror -Wextra

all:		${MAIN} ${TEST}

.cpp.o:
			@c++ ${FLAGS} -c $< -o ${<:.cpp=.o}

${MAIN}:	${OBJS_MAIN}
			@c++ ${OBJS_MAIN} -o ${MAIN}
			@printf "\033[0;31mreplace compiled\033[0m\n"

${TEST}:	${OBJS_TEST}
			@c++ ${OBJS_TEST} -o ${TEST}
			@printf "\033[0;31mtest compiled\033[0m\n"

clean:
			@rm -rf ${OBJS_MAIN}
			@rm -rf ${OBJS_TEST}

fclean:		clean
			@rm -rf ${MAIN}
			@rm -rf ${TEST}

re:			fclean all

.PHONY:		all clean fclean re
