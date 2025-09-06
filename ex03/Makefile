CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS = ${SRCS:.cpp=.o}

${NAME} : ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} 

all: ${NAME}

clean: 
		rm -rf ${OBJS}
fclean: clean
		rm -rf a.out
re: fclean all

.PHONY: re fclean clean all