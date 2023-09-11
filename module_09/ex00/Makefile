SRCS :=		main.cpp \
			BitcoinExchange.cpp
OBJS =		${SRCS:.cpp=.o}
TARGET :=	btc
FLAGS :=	-g3 -std=c++98 -Wall -Werror -Wextra

all:		${TARGET}

.cpp.o:
			@c++ ${FLAGS} -c $< -o ${<:.cpp=.o}

${TARGET}:	${OBJS}
			@c++ ${OBJS} -o ${TARGET}
			@printf "\033[0;32mCompiled\033[0m\n"

clean:
			@rm -rf ${OBJS}

fclean:		clean
			@rm -rf ${TARGET}

re:			fclean all

.PHONY:		all clean fclean re
