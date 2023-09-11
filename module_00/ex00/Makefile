SRCS :=		megaphone.cpp

OBJS		= ${SRCS:.cpp=.o}
TARGET		:= megaphone
FLAGS		:= -g3 -std=c++98 -Wall -Werror -Wextra

all:		${TARGET}

.cpp.o:
			@c++ ${FLAGS} -c $< -o ${<:.cpp=.o}

${TARGET}:	${OBJS}
			@c++ ${FLAGS} ${OBJS} -o ${TARGET}
			@printf "\033[0;31mCompiled\033[0m\n"

clean:
			@rm -rf ${OBJS}

fclean:		clean
			@rm -rf ${TARGET}

re:			fclean all
