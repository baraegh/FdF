

NAME = fdf

SRCS = fdf.c render.c hooks.c draw_line.c get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c read_file.c  display.c \
		render_map.c



OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MLX = -I /usr/local/include -L /usr/local/lib -lmlx

FRAMEWORKS = -framework OpenGl -framework Appkit

${NAME} : ${OBJS}
			cd libft && make && make clean && cd .. 
			${CC} ${MLX} ${FRAMEWORKS} -o ${NAME} ${OBJS} libft/libft.a -g
		
all:	${NAME}
	
clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		cd Libft && make fclean && cd ..

re:		fclean all

.PHONY:	all clean fclean re
