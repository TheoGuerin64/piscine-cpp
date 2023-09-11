MAKEFLAGS += -j

SRC :=		main.cpp \
			ScalarConverter.cpp
SRC_TEST := test.cpp \
			ScalarConverter.cpp
OBJS =		${SRC:.cpp=.o}
OBJS_TEST =	${SRC_TEST:.cpp=.o}
TGT :=		convert
TGT_TEST :=	test
FLAGS :=	-g3 -std=c++98 -Wall -Werror -Wextra

green := \033[0;32m

all:		${TGT} ${TGT_TEST}

.cpp.o:
			@c++ ${FLAGS} -c $< -o ${<:.cpp=.o}

${TGT}:	${OBJS}
			@c++ ${OBJS} -o ${TGT}
			@printf "\033[0;32m%s compiled\033[0m\n" ${TGT}

${TGT_TEST}: ${OBJS_TEST}
			@c++ ${OBJS_TEST} -o ${TGT_TEST}
			@printf "\033[0;32m%s compiled\033[0m\n" ${TGT_TEST}

clean:
			@rm -rf ${OBJS}
			@rm -rf ${OBJS_TEST}

fclean:		clean
			@rm -rf ${TGT}
			@rm -rf ${TGT_TEST}

re:			fclean
			@make -s

.PHONY:		all clean fclean re
