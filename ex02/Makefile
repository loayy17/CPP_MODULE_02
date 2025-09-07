CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Fixed.cpp
OBJS = ${SRCS:.cpp=.o}

a.out : ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} 

all: a.out

clean: 
		rm -rf ${OBJS}
fclean: clean
		rm -rf a.out
re: fclean all

.PHONY: re fclean clean all