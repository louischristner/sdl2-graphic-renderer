CPP		=	g++
CFLAGS	=	-O3	#Option d'optimisation du programme
LDFLAGS	=	-lSDL2 -lSDL2_image
NAME	=	prog

SRC		=	sources/Entity.cpp				\
			sources/GraphicException.cpp	\
			sources/SDL2Renderer.cpp		\
			main.cpp

OBJ		=	$(SRC:.cpp=.o)

all: ${NAME}

${NAME}: ${OBJ}
	${CPP} $(CFLAGS) -o ${NAME} ${OBJ} ${LDFLAGS}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
